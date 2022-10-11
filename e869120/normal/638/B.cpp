#include<iostream>
#include<string>
#include<vector>
using namespace std;
string S; int n, r[26], s[26], u[26];
int main() {
	cin >> n; for (int i = 0; i < 26; i++) { r[i] = -1; s[i] = -1; }
	for (int i = 0; i < n; i++) {
		cin >> S; for (int j = 0; j < S.size(); j++)u[S[j] - 'a'] = 1;
		for (int j = 0; j < S.size() - 1; j++) { r[S[j] - 'a'] = (S[j + 1] - 'a'); s[S[j + 1] - 'a'] = (S[j] - 'a'); }
	}
	for (int i = 0; i < 26; i++) {
		if (u[i] == 1 && s[i] == -1) {
			int V = i;
			while (true) { cout << (char)('a' + V); V = r[V]; if (V == -1)break; }
		}
	}
	cout << endl;
	return 0;
}