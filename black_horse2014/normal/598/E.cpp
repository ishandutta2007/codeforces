#include <bits/stdc++.h>
using namespace std;

const int N = 33;
const int K = 55;

int dp[N][N][K];

const int inf = 1e9;

inline void chkmin(int &a, int b) {
	if (b < a) a = b;
}

int main() {
	for (int i = 0; i <= 30; i++) {
		for (int j = 0; j <= 30; j++) {
			for (int k = 0; k <= 50; k++) dp[i][j][k] = inf;
			dp[i][j][0] = 0;
			if (i * j <= 50) dp[i][j][i * j] = 0;
		}
	}
	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j <= 30; j++) {
			if (i == 1 && j == 1) continue;
			for (int k = 1; k <= 50 && k < i * j; k++) {
				for (int ii = 1; ii <= i-1; ii++) {
					for (int kk = 0; kk <= k && kk <= ii * j; kk++) {
						chkmin(dp[i][j][k], dp[ii][j][kk] + dp[i - ii][j][k - kk] + j * j);
					}
				}
				for (int jj = 1; jj <= j-1; jj++) {
					for (int kk = 0; kk <= k && kk <= jj * i; kk++) {
						chkmin(dp[i][j][k], dp[i][jj][kk] + dp[i][j - jj][k - kk] + i * i);
					}
				}
			}
		}
	}
	int ncase;
	for (scanf("%d", &ncase); ncase--; ) {
		int n, m, k; scanf("%d%d%d", &n, &m, &k);
		printf("%d\n", dp[n][m][k]);
	}
	return 0;
}