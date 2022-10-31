#include <bits/stdc++.h>
using namespace std;

const int N = 1100;

int dp[N], fa[N];
vector<int> adj[N];

int find_far(int u) {
	memset(dp, 0, sizeof dp);
	queue<int> Q;
	Q.push(u);
	dp[u] = 1;
	while (!Q.empty()) {
		u = Q.front();
		Q.pop();
		for (int v : adj[u]) {
			if (dp[v]) continue;
			dp[v] = dp[u] + 1;
			fa[v] = u;
			Q.push(v);
		}
	}
	return u;
}

int main() {
	ios::sync_with_stdio(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	int dap = 0;
	vector<pair<int, int> > cand, ans;
	for (int i = 1; i <= n; i++) if (!dp[i]) {
		int u = find_far(i);
		int v = find_far(u);
		int mdp = (1 + dp[v]) / 2;
		int w = v;
		for (int j = 1; j <= dp[v] - mdp; j++) w = fa[w];
		cand.push_back({dp[v], w});
		dap = max(dap, dp[v] - 1);
	}
	sort(cand.begin(), cand.end());
	reverse(cand.begin(), cand.end());
	for (int i = 1; i < cand.size(); i++) {
		ans.push_back({cand[0].second, cand[i].second});
		dap = max(dap, 1 + cand[0].first / 2 + cand[i].first / 2);
	}
	if (cand.size() >= 3) {
		dap = max(dap, 2 + cand[1].first/ 2 + cand[2].first / 2);
	}
	cout << dap << endl;
	for (auto e : ans) cout << e.first << ' ' << e.second << endl;
	return 0;
}