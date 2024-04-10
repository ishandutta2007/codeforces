#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int dp[1003][1003], r1[1003], r2[1003], n, m, W, cnt, a, b, ans; vector<int>J[1003], x[1003]; queue<int>Q; bool used[1003];
int main() {
	cin >> n >> m >> W; for (int i = 1; i <= n; i++)cin >> r1[i]; for (int i = 1; i <= n; i++)cin >> r2[i];
	for (int i = 0; i < m; i++) { cin >> a >> b; x[a].push_back(b); x[b].push_back(a); }
	for (int i = 1; i <= n; i++) {
		if (used[i] == true)continue; used[i] = true; Q.push(i);
		while (!Q.empty()) {
			int a1 = Q.front(); Q.pop(); J[cnt].push_back(a1);
			for (int j = 0; j < x[a1].size(); j++) {
				if (used[x[a1][j]] == false) { used[x[a1][j]] = true; Q.push(x[a1][j]); }
			}
		}
		cnt++;
	}
	for (int i = 0; i <= cnt; i++) { for (int j = 0; j <= W; j++)dp[i][j] = -(1LL << 30); }dp[0][0] = 0;
	for (int i = 0; i < cnt; i++) {
		vector<int>Y1, Y2; int s1 = 0, s2 = 0;
		for (int j = 0; j < J[i].size(); j++) {
			Y1.push_back(r1[J[i][j]]); Y2.push_back(r2[J[i][j]]); s1 += r1[J[i][j]]; s2 += r2[J[i][j]];
		}
		for (int j = 0; j <= W - s1; j++) { dp[i + 1][j + s1] = max(dp[i + 1][j + s1], dp[i][j] + s2); }
		for (int j = 0; j < Y1.size(); j++) {
			for (int k = 0; k <= W - Y1[j]; k++) { dp[i + 1][k + Y1[j]] = max(dp[i + 1][k + Y1[j]], dp[i][k] + Y2[j]); }
		}
		for (int j = 0; j <= W; j++)dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
	}
	for (int i = 0; i <= W; i++)ans = max(ans, dp[cnt][i]);
	cout << ans << endl;
	return 0;
}