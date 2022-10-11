#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string S; int t, n;

int main() {
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> S;

		int c1 = 0, c2 = 0;
		for (int j = 0; j < n; j++) {
			if (S[j] == '>') break;
			c1++;
		}
		for (int j = n - 1; j >= 0; j--) {
			if (S[j] == '<') break;
			c2++;
		}
		cout << min(c1, c2) << endl;
	}
	return 0;
}