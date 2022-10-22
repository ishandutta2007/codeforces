/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
vector <int> g[N];
int sz[N];
bool vis[N];
int cnt = 0, a[N], b[N], c[N], h[N];

void dfs(int v) {
	vis[v] = true;
	for (int u : g[v]) {
		if (!vis[u]) {
			h[u] = h[v] + 1;
			dfs(u);
			sz[v] += sz[u];
		}
		if (h[u] >= h[v]) {
			sz[v]++;
		}
	}
}

void dfs2(int v, int par) {
	vis[v] = true;
	vector <int> n;
	if (par != -1)
		n.push_back(par);
	for (int u : g[v]) {
		if (h[u] >= h[v] + 2)
			n.push_back(u);
	}
	for (int u : g[v]) {
		if (!vis[u]) {
			if (sz[u] % 2 == 0)
				dfs2(u, -1), n.push_back(u);
			else
				dfs2(u, v);
		}
	}
	for (int i = 0; i < (int)n.size() - 1; i += 2) {
		a[cnt] = n[i];
		b[cnt] = v;
		c[cnt] = n[i + 1];
		cnt++;
	}
}


int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i])
			dfs(i);
	}
	for (int i = 1; i <= n; i++) 
		vis[i] = false;
	for (int i = 1; i <= n; i++) 
		if (!vis[i])
			dfs2(i, -1);
	cout << cnt << '\n';
	for (int i = 0; i < cnt; i++) {
		cout << a[i] << ' ' << b[i] << ' ' << c[i] << '\n';
	}
}