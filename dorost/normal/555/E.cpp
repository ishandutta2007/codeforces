/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234, LG = 19;
int par[N][LG], h[N];
bool vis[N];
vector <int> g[N];
int u[N], d[N], su[N], sd[N], xx[N], sx[N];

inline int lca(int x, int y) {
	if (par[x][LG - 1] != par[y][LG - 1]) {
		return -1;
	}
	if (h[x] < h[y])
		swap(x, y);
	int l = (h[x] - h[y]);
	for (int i = LG - 1; i >= 0; i--) {
		if (l & (1 << i))
			x = par[x][i];
	}
	if (x == y)
		return x;
	for (int i = LG - 1; i >= 0; i--) {
		int nx = par[x][i], ny = par[y][i];
		if (nx == ny)
			continue;
		x = nx;
		y = ny;
	}
	return par[x][0];
}

void dfs(int x) {
	vis[x] = true;
	for (int y : g[x]) {
		if (!vis[y]) {
			par[y][0] = x;
			h[y] = h[x] + 1;
			dfs(y);
		}
		if (h[x] < h[y]) {
			xx[x]--;
			xx[y]++;
		} else {
			xx[y]--;
			xx[x]++;
		}
	}
}

void dfs2(int v) {
	vis[v] = true;
	su[v] = u[v];
	sd[v] = d[v];
	sx[v] = xx[v];
	for (int y : g[v]) {
		if (!vis[y]) {
			dfs2(y);
			su[v] += su[y];
			sx[v] += sx[y];
			sd[v] += sd[y];
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i])
			continue;
		par[i][0] = i;
		dfs(i);
	}
	for (int j = 1; j < LG; j++) 
		for (int i = 1; i <= n; i++) 
			par[i][j] = par[par[i][j - 1]][j - 1];
	while (q--) {
		int s, t;
		cin >> s >> t;
		int l = lca(s, t);
		if (l == -1) {
			cout << "NO\n";
			return 0;
		}
		u[s]++;
		u[l]--;
		d[t]++;
		d[l]--;
	}
	for (int i = 0; i < N; i++)
		vis[i] = false;
	for (int i = 1; i <= n; i++) {
		if (vis[i])
			continue;
		dfs2(i);
	}
	bool f = true;
	for (int i = 1; i <= n; i++) {
		if (su[i] && sd[i] && (sx[i] == 2)) {
			f = false;
		}
	}
	cout << (f ? "YES" : "NO");
}