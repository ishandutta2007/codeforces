#include<iostream>
#include<algorithm>
using namespace std;
int dp[1 << 15][15][2], n, m, l[15], r[15];
int main() {
	cin >> n >> m; int mask = 0;
	for (int i = n - 1; i >= 0; i--) {
		l[i] = 1e9; r[i] = -1e9;
		for (int j = 0; j <= m + 1; j++) {
			char c; cin >> c;
			if (c == '1') { l[i] = min(l[i], j); r[i] = max(r[i], j); }
		}
		if (l[i] >= 1e8)mask += (1 << i);
	}
	for (int i = 0; i < (1 << 15); i++) { for (int j = 0; j < 15; j++) { dp[i][j][0] = 1e9; dp[i][j][1] = 1e9; } }
	dp[mask][0][0] = 0;
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if (j >= 1)dp[i][j - 1][0] = min(dp[i][j - 1][0], dp[i][j][0] + 1);
			if (j < n - 1)dp[i][j + 1][0] = min(dp[i][j + 1][0], dp[i][j][0] + 1);
			if (j >= 1)dp[i][j - 1][1] = min(dp[i][j - 1][1], dp[i][j][1] + 1);
			if (j < n - 1)dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][1] + 1);
			if ((i / (1 << j)) % 2 == 1)continue;
			if (dp[i][j][0] < 1e8) {
				dp[i + (1 << j)][j][1] = min(dp[i + (1 << j)][j][1], dp[i][j][0] + (m + 1));
				dp[i + (1 << j)][j][0] = min(dp[i + (1 << j)][j][0], dp[i][j][0] + r[j] * 2);
				if (i + (1 << j) == (1 << n) - 1)dp[(1 << n) - 1][j][0] = min(dp[(1 << n) - 1][j][0], dp[i][j][0] + r[j]);
			}
			if (dp[i][j][1] < 1e8) {
				dp[i + (1 << j)][j][0] = min(dp[i + (1 << j)][j][0], dp[i][j][1] + (m + 1));
				dp[i + (1 << j)][j][1] = min(dp[i + (1 << j)][j][1], dp[i][j][1] + ((m + 1) - l[j]) * 2);
				if (i + (1 << j) == (1 << n) - 1)dp[(1 << n) - 1][j][0] = min(dp[(1 << n) - 1][j][0], dp[i][j][1] + ((m + 1) - l[j]));
			}
		}
	}
	int maxn = 1e9;
	for (int i = 0; i < n; i++)maxn = min(maxn, dp[(1 << n) - 1][i][0]);
	cout << maxn << endl;
	return 0;
}