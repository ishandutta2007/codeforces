#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string S[100009]; int n, E = 0;

int solve(char c) {
	E = 0;
	for (int i = n; i >= 1; i--) {
		bool flag = true;
		for (int j = 0; j < S[i].size(); j++) { if (S[i][j] != c) flag = false; }

		if (flag == true) {
			E *= (S[i].size() + 1); E += S[i].size();
		}
		if (flag == false) {
			bool ok = false;
			for (int j = 1; j < i; j++) {
				for (int k = 0; k < S[j].size(); k++) { if (S[j][k] == c) ok = true; }
			}
			if (ok == false) {
				int t = 0, maxn = 0;
				for (int j = 0; j < S[i].size(); j++) {
					if (S[i][j] == c) t++;
					else t = 0;
					maxn = max(maxn, t);
				}
				return E * (maxn + 1) + maxn;
			}
			if (ok == true) {
				int t = 0, maxn = 1;
				for (int j = 0; j < S[i].size() * 2; j++) {
					if (S[i][j % S[i].size()] == c) t++;
					else t = 0;

					int cl = j - t + 1;
					if (cl <= (int)S[i].size() && j >= (int)S[i].size() - 1) maxn = max(maxn, t + 1);
					else maxn = max(maxn, t);
				}
				return E * (maxn + 1) + maxn;
			}
		}
	}
	return E;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> S[i];

	int ret = 0;
	for (int i = 0; i < 26; i++) ret = max(ret, solve('a' + i));

	cout << ret << endl;
	return 0;
}