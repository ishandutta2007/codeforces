#include <bits/stdc++.h>
using namespace std;

const int N = 220000;
vector<int> adj[N];
vector<pair<int, int> > ans;
int dp[N], pr[N], vis[N], dis[N], a[N], id[N];
void dfs(int u, int p) {
	dp[u] = dp[p] + 1;
	pr[u] = p;
	for (int v : adj[u]) if (v != p) dfs(v, u);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	int r = 1;
	for (int i = 1; i <= n; i++) if (dp[i] > dp[r]) r = i;
	dfs(r, 0);
	for (int i = 1; i <= n; i++) if (dp[i] > dp[r]) r = i;
	int ca = 0;
	while (r) a[ca++] = r, vis[r] = r, r = pr[r];
	reverse(a, a + ca);
	long long dap = 0;
	for (int i = 1; i < ca; i++) {
		ans.push_back(make_pair(a[i], a[0]));
		dap += i;
	}
	for (int i = 1; i <= n; i++) id[i] = i;
	sort(id + 1, id + n + 1, [](int x, int y) {
		return dp[x] < dp[y];
	});
	int L = a[0], R = a[ca - 1];
	for (int j = 1; j <= n; j++) {
		int i = id[j];
		if (vis[i]) continue;
		vis[i] = vis[pr[i]];
		dis[i] = dis[pr[i]] + 1;
		int D = vis[i];
		int w = (dp[D] - dp[L] > dp[R] - dp[D] ? L : R);
		ans.push_back(make_pair(i, w));
		dap += (abs(dp[w] - dp[D]) + dis[i]);
	}
	reverse(ans.begin(), ans.end());
	cout << dap << endl;
	for (auto e : ans) cout << e.first << " " << e.second << " " << e.first << "\n";
	return 0;
}