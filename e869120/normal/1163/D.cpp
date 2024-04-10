#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int dp[1009][59][59], c1[59][26], c2[59][26], d1, d2;
string A, S, T;

int check(string B1, string B2) {
	int L = 0;
	for (int i = 0; i <= min(B1.size(), B2.size()); i++) {
		string V1 = B1.substr(0, i);
		string V2 = B2.substr(B2.size() - i, i);
		if (V1 == V2) L = i;
	}
	return L;
}

int main() {
	cin >> A >> S >> T;
	for (int i = 0; i < S.size(); i++) {
		for (int j = 0; j < 26; j++) {
			string V = S.substr(0, i); V += (char)('a' + j);
			c1[i][j] = check(S, V);
		}
	}
	d1 = check(S, S.substr(1, S.size() - 1));
	for (int i = 0; i < T.size(); i++) {
		for (int j = 0; j < 26; j++) {
			string V = T.substr(0, i); V += (char)('a' + j);
			c2[i][j] = check(T, V);
		}
	}
	d2 = check(T, T.substr(1, T.size() - 1));
	for (int i = 0; i <= A.size(); i++) {
		for (int j = 0; j <= S.size(); j++) {
			for (int k = 0; k <= T.size(); k++) dp[i][j][k] = -(1 << 30);
		}
	}
	dp[0][0][0] = 0;
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < S.size(); j++) {
			for (int k = 0; k < T.size(); k++) {
				if (dp[i][j][k] == -(1 << 30)) continue;

				for (int l = 0; l < 26; l++) {
					if (A[i] != '*' && A[i] != ('a' + l)) continue;

					int z1 = c1[j][l], z2 = c2[k][l], sc = 0;
					if (z1 == S.size()) { z1 = d1; sc++; }
					if (z2 == T.size()) { z2 = d2; sc--; }

					dp[i + 1][z1][z2] = max(dp[i + 1][z1][z2], dp[i][j][k] + sc);
				}
			}
		}
	}

	int maxn = -100000; for (int i = 0; i <= S.size(); i++) { for (int j = 0; j <= T.size(); j++) maxn = max(maxn, dp[A.size()][i][j]); }
	cout << maxn << endl;
	return 0;
}