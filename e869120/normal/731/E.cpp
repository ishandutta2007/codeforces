#include<iostream>
#include<algorithm>
using namespace std;
int n, a[200010], p[200010], s, dp[200010][2];
int dfs(int pos, int rec) {
	if (pos == n) {
		if (rec == 0)return p[pos];
		return -p[pos];
	}
	if (pos == 1) { return dfs(pos + 1, rec); }
	if (dp[pos][rec] >= -2.1e9)return dp[pos][rec];
	if (rec == 0) {
		dp[pos][rec] = max(dfs(pos + 1, rec), dfs(pos + 1, rec ^ 1) + p[pos]);
	}
	if (rec == 1) {
		dp[pos][rec] = min(dfs(pos + 1, rec), dfs(pos + 1, rec ^ 1) - p[pos]);
	}
	return dp[pos][rec];
}
int main() {
	cin >> n; for (int i = 1; i <= n; i++) { cin >> a[i]; s += a[i]; p[i] = p[i - 1] + a[i]; }
	for (int i = 0; i < 200010; i++) { for (int j = 0; j < 2; j++)dp[i][j] = -2130000000; }
	cout << dfs(1, 0) << endl;
	return 0;
}