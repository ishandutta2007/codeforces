#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)
int n, a[200009], b[200009], dist[200009], s, t, dp[200009], dist1[2000009], dist2[200009];
vector<int>x[200009]; queue<int>Q; vector<pair<int, int>>X; vector<int>D;
void dfs(int pos, int depth) {
	if (dist[pos] >= 0) return;
	dist[pos] = depth;
	for (int i = 0; i < x[pos].size(); i++) dfs(x[pos][i], depth + 1);
}
int main() {
	cin >> n;
	for (int i = 1; i < n; i++) { scanf("%d%d", &a[i], &b[i]); x[a[i]].push_back(b[i]); x[b[i]].push_back(a[i]); }
	for (int i = 1; i <= n; i++) dist[i] = -1; dfs(1, 0);
	int maxn = -1; for (int i = 1; i <= n; i++) { if (maxn < dist[i]) { maxn = dist[i]; s = i; } }
	for (int i = 1; i <= n; i++) dist[i] = -1; dfs(s, 0);
	maxn = -1; for (int i = 1; i <= n; i++) { if (maxn < dist[i]) { maxn = dist[i]; t = i; } }
	for (int i = 1; i <= n; i++) dp[i] = 99999999;
	int cx = t; dp[cx] = 0; D.push_back(cx);
	while (cx != s) {
		for (int i : x[cx]) { if (dist[i] < dist[cx]) { cx = i; break; } }
		dp[cx] = 0; D.push_back(cx);
	}
	for (int i = 1; i <= n; i++) { if (dp[i] == 0)Q.push(i); }
	while (!Q.empty()) {
		int a1 = Q.front(); Q.pop();
		for (int i : x[a1]) { if (dp[i] > dp[a1] + 1) { dp[i] = dp[a1] + 1; Q.push(i); } }
	}
	for (int i = 1; i <= n; i++) { if (dp[i] != 0) { X.push_back(make_pair(dp[i], i)); } }
	sort(X.begin(), X.end(), greater<pair<int, int>>());

	for (int i = 1; i <= n; i++) dist[i] = -1; dfs(s, 0); for (int i = 1; i <= n; i++)dist1[i] = dist[i];
	for (int i = 1; i <= n; i++) dist[i] = -1; dfs(t, 0); for (int i = 1; i <= n; i++)dist2[i] = dist[i];

	long long ans = 0; vector<tuple<int, int, int>>QQ;
	for (int i = 0; i < X.size(); i++) {
		int to = X[i].second;
		if (dist1[to] >= dist2[to]) { QQ.push_back(make_tuple(to, s, to)); ans += dist1[to]; }
		if (dist1[to] < dist2[to]) { QQ.push_back(make_tuple(to, t, to)); ans += dist2[to]; }
	}
	for (int i = 0; i < (int)D.size() - 1; i++) {
		QQ.push_back(make_tuple(s, D[i], D[i])); ans += dist1[D[i]];
	}
	cout << ans << endl;
	for (int i = 0; i < QQ.size(); i++) printf("%d %d %d\n", get<0>(QQ[i]), get<1>(QQ[i]), get<2>(QQ[i]));
	return 0;
}