#include <iostream>
#include <string>
using namespace std;
#pragma warning (disable: 4996)

string S; int p1 = 0, p2 = 0;

int main() {
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '0') {
			if (p1 == 0) cout << "1 1" << endl;
			if (p1 == 1) cout << "3 1" << endl;
			p1++; p1 %= 2;
		}
		if (S[i] == '1') {
			if (p2 == 0) cout << "1 3" << endl;
			if (p2 == 1) cout << "2 3" << endl;
			if (p2 == 2) cout << "3 3" << endl;
			if (p2 == 3) cout << "4 3" << endl;
			p2++; p2 %= 4;
		}
	}
	return 0;
}