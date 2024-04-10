/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 100004, NINF = -1000000000, LG = 17, INF = 1000000000;
vector <pair <int, int>> g[N];
int dpd[N], d[N], mnd[N], mxd[N], u[N], v[N], par[N][LG], mx[N][LG], dpu[N], w[N], dis[N], h[N], mxu[N], mnu[N], n, m;
bool b[N];
int st = 0, mp[N];
int a[N], s[N];

int lca(int x, int y) {
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

void dfs2(int v, int p) {
	s[v] = a[v];
	for (pair <int, int> wef : g[v]) {
		int u = wef.F, w = wef.S;
		if (u != p) {
			dfs2(u, v);
			s[v] += s[u];
		}
	}
}

void dfs(int v, int p) {
	mp[v] = st++;
	for (pair <int, int> wef : g[v]) {
		int u = wef.F, w = wef.S;
		if (u != p) {
			dfs(u, v);
		}
	}
}

void dfsd(int x, int p) {
	dpd[x] = (b[x] ? 0 : NINF);
	mnd[x] = INF;
	mxd[x] = -INF;
	for (pair <int, int> wef : g[x]) {
		int u = wef.F, w = wef.S;
		if (u != p) {
			h[u] = h[x] + 1;
			par[u][0] = x;
			dis[u] = dis[x] + w;
			dfsd(u, x);
			if (dpd[u] == NINF) {
				continue;
			}
			if (dpd[u] + w > dpd[x]) {
				dpd[x] = dpd[u] + w;
				mnd[x] = mnd[u];
				mxd[x] = mxd[u];
			}
			if (dpd[u] + w == dpd[x]) {
				mnd[x] = min(mnd[x], mnd[u]);
				mxd[x] = max(mxd[x], mxd[u]);
			}
		}
	}
	if (dpd[x] == 0) {
		mnd[x] = x;
		mxd[x] = x;
	}
}

void dfsu(int x, int p) {
	int mx1 = NINF, mx2 = NINF;
	pair <int, int> mn1wef = {INF, INF}, mn2wef = {INF, INF};
	pair <int, int> mx1wef = {NINF, NINF}, mx2wef = {NINF, NINF};
	for (pair <int, int> wef : g[x]) {
		int y = wef.F, w = wef.S;
		if (y != p) {
			if (dpu[x] != NINF) {
				dpu[y] = dpu[x] + w;
			} else {
				dpu[y] = NINF;
			}
			if (b[x]) {
				dpu[y] = max(dpu[y], w);
			}
			int k = dpd[y] + w;
			if (dpd[y] == NINF)
				k = NINF;
			if (k > mx1) {
				mx2 = mx1;
				mx1 = k;
			} else if (k > mx2) {
				mx2 = k;
			}
			pair <int, int> mnk = make_pair(-k, mnd[y]);
			pair <int, int> mxk = make_pair(k, mxd[y]);
			if (mnk < mn1wef) {
				mn2wef = mn1wef;
				mn1wef = mnk;
			} else if (mnk < mn2wef) {
				mn2wef = mnk;
			}
			if (mxk > mx1wef) {
				mx2wef = mx1wef;
				mx1wef = mxk;
			} else if (mxk > mx2wef) {
				mx2wef = mxk;
			}
		}
	}
	for (pair <int, int> wef : g[x]) {
		int y = wef.F, w = wef.S;
		if (y != p) {
			int k;
			if (dpd[y] + w == mx1) {
				k = mx2;
			} else {
				k = mx1;
			}
			pair <int, int> mnk = make_pair(-(dpd[y] + w), mnd[y]);
			pair <int, int> mxk = make_pair((dpd[y] + w), mxd[y]);
			if (mnk == mn1wef) {
				mnu[y] = mn2wef.S;
			} else {
				mnu[y] = mn1wef.S;
			}
			if (mxk == mx1wef) {
				mxu[y] = mx2wef.S;
			} else {
				mxu[y] = mx1wef.S;
			}
			mx[y][0] = k - dis[x];
			dpu[y] = max(dpu[y], k + w);
		}
	}
	for (pair <int, int> wef : g[x]) {
		int y = wef.F, w = wef.S;
		if (y != p) {
			dfsu(y, x);
		}
	}
}

inline void sparse() {
	for (int i = 1; i < LG; i++) {
		for (int j = 0; j < n; j++) {
			par[j][i] = par[par[j][i - 1]][i - 1];
			mx[j][i] = max(mx[j][i - 1], mx[par[j][i - 1]][i - 1]);
		}
	}
}

int32_t main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> d[i];
	}
	for (int i = 0; i < n - 1; i++) {
		cin >> u[i] >> v[i] >> w[i];
		g[u[i]].push_back({v[i], w[i]});
		g[v[i]].push_back({u[i], w[i]});
	}
	dfs(1, -1);
	for (int i = 1; i <= n; i++)
		g[i].clear();
	for (int i = 0; i < m; i++) {
		d[i] = mp[d[i]];
		b[d[i]] = true;
	}
	for (int i = 0; i < n - 1; i++) {
		u[i] = mp[u[i]];
		v[i] = mp[v[i]];
		g[u[i]].push_back({v[i], w[i]});
		g[v[i]].push_back({u[i], w[i]});
	}
	dis[0] = 0;
	par[0][0] = 0;
	dfsd(0, -1);
	dpu[0] = (b[0] ? 0 : NINF);
	dfsu(0, -1);
	sparse();
	for (int i = 0; i < n; i++)
		a[i] = 0;
	for (int i = 0; i < n; i++) {
		if (!b[i])
			continue;
		int mn1 = INF, mx1 = NINF;
		int lst = -1;
		int wef = max(dpd[i], dpu[i]);
		if (dpd[i] >= dpu[i]) {
			lst = i;
		} else {
			int I = i;
			for (int j = LG - 1; j >= 0; j--) {
				int ni = par[I][j];
				if (dis[i] + mx[I][j] < dpu[i])
					I = ni;
			}
			lst = par[I][0];
		}
		if (mx[lst][LG - 1] + dis[i] == wef) {
			a[i]++;
			if (lst != 0) {
				a[par[lst][0]]--;
			}
		} else {
			int I = i;
			if (lst == i) {
				mn1 = mnd[lst];
				mx1 = mxd[lst];
			} else {
				int lol = h[i] - h[lst] - 1;
				for (int j = LG - 1; j >= 0; j--) {
					if (lol & (1 << j)) {
						I = par[I][j];
					}
				}
				mx1 = mxu[I];
				mn1 = mnu[I];
			}
			int L = lca(mn1, mx1);
			a[L]++;
			a[i]++;
			a[lst]--;
			if (lst != 0) {
				a[par[lst][0]]--;
			}
		}
	}
	dfs2(0, -1);
	int mx = NINF, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (!b[i]) {
			if (s[i] > mx) {
				mx = s[i];
				cnt = 0;
			}
			if (s[i] == mx)
				cnt++;
		}
	}
	cout << mx << ' ' << cnt << '\n';
}