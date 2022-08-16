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

const int N = 5e5 + 10;
const ll inf = 1e18 + 42;

vector<pll> g[N];
vector<pair<pll, int>> queries[N];
ll depth[N], tree[4 * N], lazy[4 * N], ans[N], lt[N], rt[N];
int n;

void dfs1(int u);
void dfs2(int u);
void update(int i, int l, int r, int ql, int qr, ll v);
void propagate(int i, int lc, int rc);
void merge(int i, int lc, int rc);
ll query(int i, int l, int r, int ql, int qr);

int main() {
	fast_cin();
	int q;
	cin >> n >> q;
	for (int i = 2; i <= n; ++i) {
		int p, w;
		cin >> p >> w;
		g[p].pb({i, w});
	}
	depth[1] = 0;
	dfs1(1);
	for (int i = 1; i <= q; ++i) {
		int v, l, r;
		cin >> v >> l >> r;
		queries[v].pb({{l, r}, i});
	}
	dfs2(1);
	for (int i = 1; i <= q; ++i) {
		cout << ans[i] << '\n';
	}
}

void dfs1(int u) {
	lt[u] = u;
	rt[u] = u;
	for (auto &e : g[u]) {
		int v = e.first; ll w = e.second;
		depth[v] = w + depth[u];
		dfs1(v);
		lt[u] = min(lt[u], lt[v]);
		rt[u] = max(rt[u], rt[v]);
	}
	if (g[u].empty()) {
		update(1, 1, n, u, u, depth[u]);
	} else {
		update(1, 1, n, u, u, inf);
	}
}

void dfs2(int u) {
	for (auto &q : queries[u]) {
		int l = q.first.first, r = q.first.second;
		int idx = q.second;
		ans[idx] = query(1, 1, n, l, r);
	}
	for (auto &e : g[u]) {
		int v = e.first; ll w = e.second;
		update(1, 1, n, 1, n, w);
		update(1, 1, n, lt[v], rt[v], -2 * w);
		dfs2(v);
		update(1, 1, n, lt[v], rt[v], 2 * w);
		update(1, 1, n, 1, n, -w);
	}
}

void update(int i, int l, int r, int ql, int qr, ll v) {
	if (l > qr or ql > r) {
		return;
	} else if (ql <= l and r <= qr) {
		tree[i] += v;
		lazy[i] += v;
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		propagate(i, lc, rc);
		update(lc, l, mid, ql, qr, v);
		update(rc, mid + 1, r, ql, qr, v);
		merge(i, lc, rc);
	}
}

void propagate(int i, int lc, int rc) {
	tree[lc] += lazy[i];
	lazy[lc] += lazy[i];
	tree[rc] += lazy[i];
	lazy[rc] += lazy[i];
	lazy[i] = 0;
}

void merge(int i, int lc, int rc) {
	tree[i] = min(tree[lc], tree[rc]);
}

ll query(int i, int l, int r, int ql, int qr) {
	if (l > qr or ql > r) {
		return inf;
	} else if (ql <= l and r <= qr) {
		return tree[i];
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		propagate(i, lc, rc);
		return min(query(lc, l, mid, ql, qr), query(rc, mid + 1, r, ql, qr));
	}
}