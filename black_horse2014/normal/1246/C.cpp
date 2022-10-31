#include <bits/stdc++.h>
using namespace std;

const int N = 2200;
const int P = 1e9 + 7;

char pan[N][N];
int dp[2][N][N], sum[2][N][N];
int pos[2][N][N], cnt[2][N][N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> pan[i] + 1;
	for (int i = 1; i <= n; i++) {
		int cur = 0;
		pos[0][i][0] = m + 2;
		for (int j = m; j >= 0; j--) {
			pos[0][i][cur] = j;
			cur += pan[i][j] == 'R';
			cnt[0][i][j] = cur;
		}
	}
	for (int j = 1; j <= m; j++) {
		int cur = 0;
		pos[1][0][j] = n + 2;
		for (int i = n; i >= 0; i--) {
			pos[1][cur][j] = i;
			cur += pan[i][j] == 'R';
			cnt[1][i][j] = cur;
		}
	}
	dp[1][1][0] = sum[1][1][0] = 1;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
		int p = pos[0][i][m - j];
		if (p < j) {
			(dp[0][i][j] += sum[1][i][j - 1]) >= P && (dp[0][i][j] -= P);
			if (p) (dp[0][i][j] -= sum[1][i][p - 1]) < 0 && (dp[0][i][j] += P);
		}
		p = pos[1][n - i][j];
		if (p < i) {
			(dp[1][i][j] += sum[0][i - 1][j]) >= P && (dp[1][i][j] -= P);
			if (p) (dp[1][i][j] -= sum[0][p - 1][j]) < 0 && (dp[1][i][j] += P);
		}
		(sum[0][i][j] = sum[0][i - 1][j] + dp[0][i][j]) >= P && (sum[0][i][j] -= P);
		(sum[1][i][j] = sum[1][i][j - 1] + dp[1][i][j]) >= P && (sum[1][i][j] -= P);
	}
	cout << (dp[0][n][m] + dp[1][n][m]) % P << "\n";
	
	return 0;
}