#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, p[5009][26], dp[5009][5009], mod = 1000000007; string S;

int main() {
	cin >> n >> S;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 26; j++) p[i][j] = n + 3;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) p[i][S[j] - 'a'] = min(p[i][S[j] - 'a'], j);
	}
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] == 0) continue;
			for (int k = 0; k < 26; k++) {
				dp[i + 1][p[j][k]] += dp[i][j];
				if (dp[i + 1][p[j][k]] >= mod) dp[i + 1][p[j][k]] -= mod;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i <= n; i++) { sum += dp[n][i]; if (sum >= mod) sum -= mod; }
	cout << sum << endl;
	return 0;
}