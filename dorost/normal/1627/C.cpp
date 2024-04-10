/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int ans[N], h[N];
vector <pair <int, int>> g[N];

void dfs(int x, int p) {
	for (auto [y, i] : g[x]) {
		if (y != p) {
			h[y] = h[x] + 1;
			if (h[x] % 2 == 0) 
				ans[i] = 2;
			else
				ans[i] = 5;
			dfs(y, x);
		}
	}
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		g[i].clear();
	bool f = true;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].push_back({v, i});
		g[v].push_back({u, i});
		if (g[u].size() >= 3 || g[v].size() >= 3) {
			f = false;
		}
	}
	if (!f) {
		cout << -1 << '\n';
		return;
	}
	int root = -1;
	for (int i = 0; i < n; i++) {
		if (g[i].size() == 1) 
			root = i;
	}
	assert(root != -1);
	h[root] = 0;
	dfs(root, -1);
	for (int i = 0; i < n - 1; i++)
		cout << ans[i] << ' ';
	cout << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}