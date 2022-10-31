#include <bits/stdc++.h>

using namespace std;

#define MOD 998244353

int n, c[26];
long long dp[2][225][225][3][3], ans, wtf[225][225], ftw[225];

void add(long long& a, long long b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

void sub(long long& a, long long b) {
	a += MOD - b;
	if (a >= MOD) a -= MOD;
}

int main() {
	scanf("%d", &n);
	dp[0][0][0][2][2] = 24 * 24;
	dp[0][0][1][2][1] = 24;
	dp[0][0][1][1][2] = 24;
	dp[0][1][0][2][0] = 24;
	dp[0][1][0][0][2] = 24;
	dp[0][1][1][0][1] = 1;
	dp[0][1][1][1][0] = 1;
	dp[0][0][2][1][1] = 1;
	dp[0][2][0][0][0] = 1;
	int ta = 0, tb = 1;
	for (int i = 2; i < n; i++) {
		int ma = i / 2 + 5;
		memset(dp[tb], 0, sizeof(dp[tb]));
		for (int j = 0; j <= ma; j++)
			for (int k = 0; k <= ma; k++)
				for (int kk = 0; kk < 3; kk++) {
					dp[tb][j + 1][k][kk][0] = (dp[tb][j + 1][k][kk][0] + dp[ta][j][k][1][kk] + dp[ta][j][k][2][kk]) % MOD;
					dp[tb][j][k + 1][kk][1] = (dp[tb][j][k + 1][kk][1] + dp[ta][j][k][0][kk] + dp[ta][j][k][2][kk]) % MOD;
					dp[tb][j][k][kk][2] = (dp[tb][j][k][kk][2] + (dp[ta][j][k][0][kk] + dp[ta][j][k][1][kk]) * 24 + dp[ta][j][k][2][kk] * 23) % MOD;
				}
		swap(ta, tb);
	}
	int ma = n / 2 + 5;
	for (int i = 0; i <= ma; i++)
		for (int j = 0; j <= ma; j++)
			for (int ii = 0; ii < 3; ii++)
				for (int jj = 0; jj < 3; jj++) {
					add(wtf[i][j], dp[ta][i][j][ii][jj]);
					add(ftw[i], dp[ta][i][j][ii][jj]);
				}
	ans = 26 * 26;
	for (int i = 2; i < n; i++) ans = (ans * 25) % MOD;
	for (int i = 0; i < 26; i++) scanf("%d", c + i);
	for (int i = 0; i < 26; i++)
		for (int ii = c[i] + 1; ii <= ma; ii++) {
			sub(ans, ftw[ii]);
			for (int j = i + 1; j < 26; j++) {
				for (int jj = c[j] + 1; jj <= ma; jj++)
					add(ans, wtf[ii][jj]);
			}
		}
	printf("%lld\n", ans);
}