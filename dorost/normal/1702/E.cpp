/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
bool c[N], vis[N];
vector <int> v[N], g[N];
bool f;

void dfs(int v) {
	vis[v] = true;
	for (auto u : g[v]) {
		if (!vis[u]) {
			c[u] = !c[v];
			dfs(u);
		}
		if (c[u] == c[v]) {
			f = false;
		}
	}
}

void solve() {
	f = true;
	int n;
	cin >> n;
	for (int i = 0; i <= n + 5; i++) {
		v[i].clear();
		g[i].clear();
		c[i] = 0;
		vis[i] = false;
	}
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(i);
		v[b].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		if (v[i].size() != 2) {
			cout << "No\n";
			return;
		}
		int x = v[i][0];
		int y = v[i][1];
		if (x == y) {
			cout << "No\n";
			return;
		}
		g[x].push_back(y);
		g[y].push_back(x);
	}
	f = true;
	for (int i = 0; i < n; i++) {
		if (!vis[i])
			dfs(i);
	}
	cout << (f ? "YES" : "NO") << '\n';
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