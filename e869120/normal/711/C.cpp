#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
long long dp[110][110][110];
long long n, m, r, a[110], p[110][110];
int main() {
	cin >> n >> m >> r;
	for (int i = 0; i < 110; i++) {
		for (int j = 0; j < 12100; j++)dp[i][j / 110][j % 110] = 99999999999999999LL;
	}
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < n; i++) { for (int j = 1; j <= m; j++)cin >> p[i][j]; }
	dp[0][0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			for (int k = 0; k <= r; k++) {
				if (dp[i][j][k] >= 9999999999999999LL)continue;
				if (a[i] == 0) {
					for (int l = 1; l <= m; l++) {
						if (j == l) { dp[i + 1][l][k] = min(dp[i + 1][l][k], dp[i][j][k] + p[i][l]); }
						if (j != l) { dp[i + 1][l][k + 1] = min(dp[i + 1][l][k + 1], dp[i][j][k] + p[i][l]); }
					}
				}
				else {
					if (j == a[i]) { dp[i + 1][a[i]][k] = min(dp[i + 1][a[i]][k], dp[i][j][k]); }
					if (j != a[i]) { dp[i + 1][a[i]][k + 1] = min(dp[i + 1][a[i]][k + 1], dp[i][j][k]); }
				}
			}
		}
	}
	long long minx = 999999999999999999LL;
	for (int i = 1; i <= m; i++)minx = min(minx, dp[n][i][r]);
	if (minx >= 999999999999999LL)minx = -1;
	cout << minx << endl;
	return 0;
}