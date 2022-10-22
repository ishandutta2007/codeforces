/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 100012, LG = 17;
int par[N][LG];
int a[N];
int s[N], h[N];
vector <int> t[N];
int p[N], sz[N];

void dfs(int v, int p = -1) {
	s[v] += a[v];
	for (int u : t[v]) {
		if (u != p) {
			s[u] += s[v];
			par[u][0] = v;
			h[u] = h[v] + 1;
			dfs(u, v);
		}
	}
}

int get_root (int x) {
	if (p[x] == x)
		return x;
	return p[x] = get_root(p[x]);
}

bool merge (int x, int y) {
	x = get_root(x);
	y = get_root(y);
	if (x == y)
		return false;
	if (sz[x] > sz[y])
		swap(x, y);
	p[x] = y;
	sz[y] += sz[x];
	sz[x] = 0;
	return true;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	for (int i = 0; i < N; i++) {
		sz[i] = 0;
		p[i] = i;
	}
	par[1][0] = 1;
	int n, m;
	cin >> n >> m;
	vector <pair <int, int>> w;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		if (merge(u, v)) {
			t[u].push_back(v);
			t[v].push_back(u);
		} else {
			w.push_back(make_pair(u, v));
		}
	}
	dfs(1);
	for (int i = 1; i < LG; i++) {
		for (int j = 1; j <= n; j++) {
			par[j][i] = par[par[j][i - 1]][i - 1];
		}
	}
	for (auto [u, v] : w) {
		if (h[u] < h[v])
			swap(u, v);
		int l = h[u] - h[v];
		int nu = u, nv = v;
		for (int j = LG - 1; j >= 0; j--) {
			if ((l >> j) & 1) {
				nu = par[nu][j];
			}
		}
		if (nu == nv) {
			nu = u;
			l = h[u] - h[v] - 1;
			for (int j = LG - 1; j >= 0; j--) {
				if ((l >> j) & 1) {
					nu = par[nu][j];
				}
			}
			a[nu]--;
			a[u]++;
		} else {
			a[1]--;
			a[u]++;
			a[v]++;
		}
	}
	dfs(1);
	vector <int> v;
	for (int i = 1; i <= n; i++) {
		cout << (s[i] == 0);
	}
}