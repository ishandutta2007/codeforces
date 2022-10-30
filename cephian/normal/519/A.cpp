#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int w = 0, b = 0;
	for (int i = 0; i < 8; ++i) {
		string str;
		cin >> str;
		for (int j = 0; j < 8; ++j) {
			char c = str[j];
			if (c == 'Q')
				w += 9;
			else if (c == 'R')
				w += 5;
			else if (c == 'B' || c == 'N')
				w += 3;
			else if (c == 'P')
				w += 1;

			else if (c == 'q')
				b += 9;
			else if (c == 'r')
				b += 5;
			else if (c == 'b' || c == 'n')
				b += 3;
			else if (c == 'p')
				b += 1;
		}
	}
	if (w == b)
		cout << "Draw\n";
	else if (w > b)
		cout << "White\n";
	else
		cout << "Black\n";
	return 0;
}