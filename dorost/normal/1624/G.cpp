/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201000;
vector <pair <int, int>> g[N], t[N];
int w[N];
bool b[N][32], vis[N];

void dfs(int x) {
	vis[x] = true;
	for (auto [y, i] : t[x]) {
		if (!vis[y])
			dfs(y);
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		g[i].clear();
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v >> w[i];
		for (int j = 0; j < 32; j++) {
			b[i][j] = (w[i] % 2);
			w[i] /= 2;
		}
		u--, v--;
		g[u].push_back({v, i});
		g[v].push_back({u, i});
	}
	int ans = 0;
	for (int i = 31; i >= 0; i--) {
		for (int j = 0; j < n; j++)
			t[j].clear(), vis[j] = false;
		for (int j = 0; j < n; j++) {
			for (auto [y, k] : g[j]) {
				if (b[k][i] == 0) 
					t[j].push_back(make_pair(y, k));
			}
		}
		dfs(0);
		bool f = true;
		for (int i = 0; i < n; i++) {
			if (!vis[i])
				f = false;
		}
		if (f) {
			for (int j = 0; j < n; j++) {
				g[j] = t[j];
			}
		} else {
			ans += (1 << i);
		}
	}
	cout << ans << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}