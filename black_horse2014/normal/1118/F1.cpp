#include <bits/stdc++.h>
using namespace std;

const int N = 330000;

int cnt[3][N], a[N];
vector<int> adj[N];

int main() {
	int n; cin >> n;
	int c[3] = {0};
	for (int i = 1; i <= n; i++) cin >> a[i], c[a[i]]++;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ans = 0;
	function<void(int, int)> dfs = [&](int u, int p) {
		for (int i = 0; i < 3; i++) cnt[i][u] = 0;
		cnt[a[u]][u]++;
		for (auto v : adj[u]) {
			if (v == p) continue;
			dfs(v, u);
			for (int i = 0; i < 3; i++) cnt[i][u] += cnt[i][v];
		}
		if (p) {
			if (cnt[1][u] && cnt[2][u]) return;
			if (cnt[1][u] < c[1] && cnt[2][u] < c[2]) return;
			ans++;
		}
	};
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}