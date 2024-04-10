/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N];
vector <int> g[N];

void dfs(int v, int p) {
	for (auto u : g[v]) {
		if (u != p) {
			if (a[v] > 0)
				a[u] = -1 * a[u];
			dfs(u, v);
		}
	}
}

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		a[i] = 0, g[i].clear();
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		a[u]++;
		a[v]++;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, -1);
	for (int i = 1; i <= n; i++)
		cout << a[i] << ' ';
	cout << '\n';
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