#include <iostream>
using namespace std;

int main() {
	int cost['z' + 1] = {0};
	cost['q'] = 9;
	cost['r'] = 5;
	cost['b'] = 3;
	cost['n'] = 3;
	cost['p'] = 1;
	
	int w = 0, b = 0;
	for (int i = 0; i < 8; ++i) {
		for (int k = 0; k < 8; ++k) {
			char ch; cin >> ws >>ch;
			if (ch == '.') continue;
			(islower(ch) ? b : w) += cost[tolower(ch)];
		}
	}
	if (b > w) cout << "Black";
	else if (b < w) cout << "White";
	else cout << "Draw";
	return 0;
}