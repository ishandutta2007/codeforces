#include <bits/stdc++.h>
using namespace std;

void self_max(int &a, int b) { a = max(a,b); }

void solve() {
	int n; cin >> n;
	vector<vector<int>> adj(n);
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> depth(n);
	vector<pair<int,int>> deepest(n, {-1,-1});

	const auto dfs = [&](const auto &self, int i, int p) -> void {
		if (p != -1) depth[i] = depth[p] + 1;
		for (int j: adj[i]) if (j != p) {
			self(self, j, i);
			auto &[a,b] = deepest[i];
			int c = max(depth[j], deepest[j].first);
			if (c > a) b = a, a = c;
			else if (c > b) b = c;
		}
	};
	dfs(dfs, 0, -1);

	// diam[r] = max { dist(a,b) | a,b in { v | dist(0,v) >= r } }
	vector<int> diam(n);
	for (int i = 0; i < n; i++) {
		auto &[a,b] = deepest[i];
		if (a != -1) self_max(diam[depth[i]], a-depth[i]);
		if (b != -1) self_max(diam[b], a+b-2*depth[i]);
	}
	for (int r = n-2; r >= 0; r--) {
		self_max(diam[r], diam[r+1]);
	}

	int max_depth = *max_element(begin(depth), end(depth));

	// f(x) = min { r | diam[r+1] <= 2*(r-x) }
	int r = 0;
	for (int x = 1; x <= n; x++) {
		while (r < max_depth && diam[r+1] > 2*(r-x)) r++;
		cout << r << " \n"[x==n];
	}
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}