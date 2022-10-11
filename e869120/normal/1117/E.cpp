#include <bits/stdc++.h>
using namespace std;

string S; int id[100009]; char cp[100009];

int main() {
	cin >> S;
	for (int i = 1; i <= 676; i *= 26) {
		string T = "";
		for (int j = 0; j < S.size(); j++) {
			char c = ('a' + ((j / i) % 26));
			T += c;
		}
		cout << "? " << T << endl;
		string U; cin >> U;
		for (int j = 0; j < S.size(); j++) id[j] += i * (U[j] - 'a');
	}
	for (int i = 0; i < S.size(); i++) cp[id[i]] = S[i];
	cout << "! "; for (int i = 0; i < S.size(); i++) cout << cp[i]; cout << endl;
	return 0;
}