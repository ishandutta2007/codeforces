/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

#define F first
#define S second
const int N = 101;
vector <int> wef[N][N], adj[N];
vector <pair <int, int>> ans;
bool vis[N];
int dis[N][N], par[N], cnt = 0, p[N][N], sz[N][N], few[N][N], n;
bitset <N> b[N][N];

int get_root (int i, int x) {
	if (p[i][x] == x)
		return x;
	return p[i][x] = get_root(i, p[i][x]);
}

void merge (int i, int x, int y) {
	x = get_root(i, x);
	y = get_root(i, y);
	if (x == y)
		return;
	p[i][x] = y;
	sz[i][y] += sz[i][x];
	sz[i][x] = 0;
}

bool dfs(int v, int p) {
	vis[v] = true;
	bool f = true;
	for (int i : wef[v][p]) 
		if (v != p) {
			if (vis[i])
				return false;
			adj[v].push_back(i);
			adj[i].push_back(v);
			cnt++;
			f &= dfs(i, v);
		}
	return f;
}

void dfst(int v, int p) {
	for (auto u : adj[v])
		if (u != p) {
			par[u] = v;
			dfst(u, v);
		}
}

int dist(int i, int j) {
	if (dis[i][j] != -1)
		return dis[i][j];
	if (i == j)
		return dis[i][j] = 0;
	if (i == 0) 
		return dis[i][j] = dist(par[j], i) + 1;
	if (j == 0) 
		return dis[i][j] = dist(par[i], j) + 1;
	return dis[i][j] = min(dist(par[j], i), dist(par[i], j)) + 1;
}

bool check() {
	par[0] = 0;
	dfst(0, -1);
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dis[i][j] = -1;
			few[i][j] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist(i, j);
		}
	}
	bool f = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			few[i][dis[i][j]] = p[i][j];
		}
		for (int j = 0; j < n; j++) {
			f &= (few[i][dis[i][j]] == p[i][j]);
		}
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			few[i][j] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			few[i][p[i][j]] = dis[i][j];
		}
		for (int j = 0; j < n; j++) {
			f &= (few[i][p[i][j]] == dis[i][j]);
		}
	}
	return f;
}

void solve() {
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) {
			p[i][j] = j;
			sz[i][j] = 1;
			wef[i][j].clear();
		}
	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = i + 1; j < n; j++) 
			for (int l = 0; l < n; l++) {
				char c;
				cin >> c;
				b[i][j][l] = (c - '0');
				if (c == '1') {
					merge(l, i, j);
					wef[l][i].push_back(j);
					wef[l][j].push_back(i);
				}
			}
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			get_root(i, j);
	bool h = true;
	for (int i = 0; i < n; i++) 
		for (int j = i + 1; j < n; j++) 
			for (int l = 0; l < n; l++) 
				if ((b[i][j][l] == 0) && (p[l][i] == p[l][j]))
					h = false;
	if (!h) {
		cout << "No\n";
		return;
	}
	bool f = false;
	for (int b = 0; b < n; b++) 
		for (int g = 0; g < n; g++) {
			if (b == g)
				continue;
			for (int i = 0; i <= n; i++)
				adj[i].clear(), vis[i] = false;
			adj[g].push_back(b);
			adj[b].push_back(g);
			cnt = 1;
			bool h = dfs(g, b);
			if (cnt != n - 1 || (!h))
				continue;
			if (check()) {
				f = true;
				ans.clear();
				for (int i = 0; i < n; i++) {
					for (int j : adj[i]) {
						if (i < j) {
							ans.push_back({i + 1, j + 1});
						}
					}
				}
			}
		}
	if (!f)
		cout << "No" << '\n';
	else {
		cout << "Yes\n";
		for (pair <int, int> p : ans)
			cout << p.F << ' ' << p.S << '\n';
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}