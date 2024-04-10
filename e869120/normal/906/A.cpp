#include <iostream>
#include <string>
using namespace std;
#pragma warning (disable: 4996)

int Q, col[26]; char c[100009]; string S[100009];

int main() {
	cin >> Q;
	for (int i = 1; i <= Q; i++) cin >> c[i] >> S[i];

	int ss = Q;
	for (int i = 1; i <= Q - 1; i++) {
		if (c[i] == '.') {
			for (int j = 0; j < S[i].size(); j++) { col[S[i][j] - 'a'] = 1; }
		}
		if (c[i] == '!') {
			int ret[26]; for (int j = 0; j < 26; j++) ret[j] = 0;
			for (int j = 0; j < S[i].size(); j++) ret[S[i][j] - 'a'] = 1;
			for (int j = 0; j < 26; j++) { if (ret[j] == 0) col[j] = 1; }
		}
		if (c[i] == '?') {
			col[S[i][0] - 'a'] = 1; //  selected 
		}

		int cnts = 0;
		for (int j = 0; j < 26; j++) cnts += col[j];
		if (cnts == 25) { ss = i + 1; break; }
	}
	int ans = 0;
	for (int i = ss; i <= Q - 1; i++) {
		if (c[i] != '.') ans++;
	}
	cout << ans << endl;
	return 0;
}