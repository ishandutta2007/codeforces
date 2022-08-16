/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 10, LG = log2(2 * N) + 1;

void update(int i, int l, int r, int p, int v);
int query(int i, int l, int r, int &u, int &v);
inline bool add(int &u, int &v, int x);
inline bool on_path(int u, int v, int x);
inline bool ancestor(int u, int p);
void dfs(int u);
void build_table(int n);
inline int lca(int u, int v);

int per[N], loc[N], tu[4 * N], tv[4 * N];
vector<int> g[N];
int lg2[2 * N], depth[N], ent[N], ext[N];
pii table[LG][2 * N];
int nxt_time = 1;

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> per[i];
		loc[per[i]] = i;
	}
	for (int i = 2; i <= n; ++i) {
		int p; cin >> p;
		g[p].pb(i);
	}
	dfs(1);
	for (int i = 2; i < nxt_time; ++i) {
		lg2[i] = lg2[i - 1];
		while ((1 << (lg2[i] + 1)) <= i) {
			++lg2[i];
		}
	}
	build_table(nxt_time - 1);
	for (int i = 0; i < n; ++i) {
		update(1, 0, n - 1, i, loc[i]);
	}
	int q; cin >> q;
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int i, j;
			cin >> i >> j;
			swap(loc[per[i]], loc[per[j]]);
			swap(per[i], per[j]);
			update(1, 0, n - 1, per[i], i);
			update(1, 0, n - 1, per[j], j);
		} else {
			int pu = 0, pv = 0;
			cout << query(1, 0, n - 1, pu, pv) << '\n';
		}
	}
}

void update(int i, int l, int r, int p, int v) {
	if (l == r) {
		tu[i] = tv[i] = v;
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = 2 * i + 1;
		if (p <= mid) {
			update(lc, l, mid, p, v);
		} else {
			update(rc, mid + 1, r, p, v);
		}
		tu[i] = tu[lc]; tv[i] = tv[lc];
		if (!add(tu[i], tv[i], tu[rc]) or !add(tu[i], tv[i], tv[rc])) {
			tu[i] = tv[i] = -1;
		}
	}
}

int query(int i, int l, int r, int &u, int &v) {
	if (tu[i] != -1) {
		int bak_u = u, bak_v = v;
		if (add(u, v, tu[i]) and add(u, v, tv[i])) {
			return r - l + 1;
		} else {
			u = bak_u; v = bak_v;
		}
	}
	if (l == r) {
		return 0;
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = 2 * i + 1;
		int lval = query(lc, l, mid, u, v);
		if (lval < mid - l + 1) {
			return lval;
		} else {
			return lval + query(rc, mid + 1, r, u, v);
		}
	}
}

inline bool add(int &u, int &v, int x) {
	if (!u) {
		u = v = x;
		return true;
	} else if (u == -1) {
		u = v = -1;
		return false;
	}
	if (on_path(u, v, x)) {
		return true;
	} else if (on_path(u, x, v)) {
		v = x;
		return true;
	} else if (on_path(v, x, u)) {
		u = x;
		return true;
	} else {
		return false;
	}
}

inline bool on_path(int u, int v, int x) {
	int l = lca(u, v);
	return ancestor(x, l) and (ancestor(u, x) or ancestor(v, x));
}

inline bool ancestor(int u, int p) {
	return (ent[p] <= ent[u] and ext[u] <= ext[p]);
}

void dfs(int u) {
	table[0][nxt_time] = {depth[u], u};
	ent[u] = nxt_time++;
	for (auto &v : g[u]) {
		depth[v] = 1 + depth[u];
		dfs(v);
		table[0][nxt_time++] = {depth[u], u};
	}
	ext[u] = nxt_time - 1;
}

void build_table(int n) {
	for (int j = 1; j <= lg2[n]; ++j) {
		int shift = (1 << (j - 1));
		for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
			table[j][i] = table[j - 1][i];
			if (table[j - 1][i + shift].first < table[j][i].first) {
				table[j][i] = table[j - 1][i + shift];
			}
		}
	}
}

inline int lca(int u, int v) {
	int l = ent[u], r = ent[v];
	if (l > r) {
		swap(l, r);
	}
	int j = lg2[r - l + 1];
	r -= (1 << j) - 1;
	if (table[j][l].first <= table[j][r].first) {
		return table[j][l].second;
	} else {
		return table[j][r].second;
	}
}