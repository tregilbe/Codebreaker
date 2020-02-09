//  Code Breaker Training Simulation
// a new code breaking team which relies on human expertise to detect these low tech scrambled keywords.

#include <iostream>
#include  <string>
#include  <cstdlib>
#include  <ctime>

using namespace std;



int main()
{
	// Setting the bool to false for the while loop
	bool exit = false;

	do {
		//Welcoming player with title and objective
		cout << "\t\t\tWelcome to the Code Breaker Training Simulation!\n\n";
		cout << "Unscramble the letters to make a word. \n";
		for (int j = 1; j <= 3; j++) {
			enum fields { WORD, HINT, NUM_FIELDS };
			const int NUM_WORDS = 10;
			const string WORDS[NUM_WORDS][NUM_FIELDS] =
			{
			{"wall", "Do you feel you're banging your head against something?"},
			{"glasses", "These might help you see the answer."},
			{"labored", "Going slowly, is it?"},
			{"persistent", "Keep at it."},
			{"jumble", "It's what the game is all about."},
			{"kite", "Mary Poppins, let's go fly a !"},
			{"salt", "Used for a lot of food, potassium chloride."},
			{"throne", "Where a royal King sits."},
			{"low", "Opposite of low."},
			{"hate", "A very strong feeling of disliking, opposite of love"}
			};

			srand(static_cast<unsigned int>(time(0)));
			int choice = (rand() % NUM_WORDS);
			string theWord = WORDS[choice][WORD];   // Word to guess
			string theHint = WORDS[choice][HINT];   // Hint for word
			string jumble = theWord;   // Jumbled version of the word
			int length = jumble.size();
			for (int i = 0; i < length; ++i);
			{
				int index1 = (rand() % length);
				int index2 = (rand() % length);
				char temp = jumble[index1];
				jumble[index1] = jumble[index2];
				jumble[index2] = temp;
			}

			// Giving the player instructions
			cout << "Enter 'hint' for a hint. \n";
			cout << "Enter 'quit' to quit the game.\n\n";
			cout << "The jumble is: " << jumble;

			string guess;
			cout << "\n\nYour guess: ";
			cin >> guess;

			// game loop
			while ((guess != theWord) && (guess != "quit"))
			{
				if (guess == "hint")
				{
					cout << theHint;
				}
				else
				{
					cout << "Sorry, that's not it.";
				}
				cout << "\n\nYour guess: ";
				cin >> guess;

				if (guess == theWord)
				{
					cout << "\nThat's it! You guessed it!\n";
				}
			}
		}
		// End of match, give player option to play again
		cout << "You have completed 3 rounds and the game is over!\n";
		cout << "Would you like to try again? (0 to exit and 1 to continue)";
		cin>>exit;
		}while (exit);

		cout << "\nThanks for playing.\n";
		return 0;
	}