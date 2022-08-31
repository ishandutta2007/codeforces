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

const int N = 2e5 + 10, L = log2(N) + 2;

vector<int> g[N];
int tree[4 * N], tree_ctr[4 * N], lazy[4 * N];
int d[N], up[N][L], ent[N], ext[N], nxt_tm = 1;

void dfs(int u, int p);
void build_tree(int i, int l, int r);
void update(int i, int l, int r, int ql, int qr, int v);
void propagate(int i, int lc, int rc);
void merge(int i, int lc, int rc);

int main() {
	fast_cin();
	int n, q;
	cin >> n >> q;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1, 0);
	build_tree(1, 1, n);
	set<pii> edges;
	while (q--) {
		int u, v;
		cin >> u >> v;
		if (ent[u] > ent[v]) {
			swap(u, v);
		}
		int upd_val = 1;
		if (edges.count({u, v})) {
			edges.erase({u, v});
			upd_val = -1;
		} else {
			edges.insert({u, v});
		}
		if (ent[u] < ent[v] and ext[v] <= ext[u]) {
			update(1, 1, n, ent[1], ext[1] - 1, upd_val);
			update(1, 1, n, ent[v], ext[v] - 1, upd_val);
			for (int j = L - 1; j >= 0; --j) {
				if (d[up[v][j]] > d[u]) {
					v = up[v][j];
				}
			}
			update(1, 1, n, ent[v], ext[v] - 1, -upd_val);
		} else {
			update(1, 1, n, ent[u], ext[u] - 1, upd_val);
			update(1, 1, n, ent[v], ext[v] - 1, upd_val);
		}
		if (tree[1] == int(edges.size())) {
			cout << tree_ctr[1] << '\n';
		} else {
			cout << 0 << '\n';
		}
	}
}

void dfs(int u, int p) {
	d[u] = d[p] + 1;
	up[u][0] = p;
	for (int j = 1; j < L; ++j) {
		up[u][j] = up[up[u][j - 1]][j - 1];
	}
	ent[u] = nxt_tm++;
	for (auto &v : g[u]) {
		if (v != p) {
			dfs(v, u);
		}
	}
	ext[u] = nxt_tm;
}

void build_tree(int i, int l, int r) {
	tree[i] = 0;
	tree_ctr[i] = r - l + 1;
	if (l < r) {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		build_tree(lc, l, mid);
		build_tree(rc, mid + 1, r);
	}
}

void update(int i, int l, int r, int ql, int qr, int v) {
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
	if (tree[lc] < tree[rc]) {
		swap(lc, rc);
	}
	tree[i] = tree[lc];
	tree_ctr[i] = tree_ctr[lc];
	if (tree[lc] == tree[rc]) {
		tree_ctr[i] += tree_ctr[rc];
	}
}