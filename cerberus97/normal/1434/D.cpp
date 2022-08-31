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
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 5e5 + 10, inf = 1e9 + 42;

struct node {
	vector<int> d, vl, vr;
	int min_d, ans;
	bool lazy;
};

int eu[N], ev[N], ew[N], ent[N], ext[N], d[N], at[2 * N];
bool type[N];
vector<pii> g[N];
node tree[8 * N];

void dfs1(int u, int p, int& id);
void build(int i, int l, int r);
void merge(int i, int lc, int rc);
void update(int i, int l, int r, int ql, int qr);
void propagate(int i, int lc, int rc);
void apply_flip(int i);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n - 1; ++i) {
		cin >> eu[i] >> ev[i] >> ew[i];
		g[eu[i]].pb({ev[i], ew[i]});
		g[ev[i]].pb({eu[i], ew[i]});
	}
	int nid = 1;
	dfs1(1, 0, nid);
	build(1, 1, nid - 1);
	// cout << tree[1].ans << endl << endl;
	int m; cin >> m;
	while (m--) {
		int id; cin >> id;
		int u = eu[id], v = ev[id];
		if (d[u] > d[v]) {
			swap(u, v);
		}
		update(1, 1, nid - 1, ent[v], ext[v]);
		cout << tree[1].ans << '\n';
	}
}

void dfs1(int u, int p, int& id) {
	ent[u] = id;
	at[id++] = u;
	d[u] = d[p] + 1;
	for (auto& e : g[u]) {
		int v = e.first, wt = e.second;
		if (v != p) {
			type[v] = type[u] ^ wt;
			dfs1(v, u, id);
			at[id++] = u;
		}
	}
	ext[u] = id - 1;
}

void build(int i, int l, int r) {
	if (l == r) {
		tree[i] = {{-inf, -inf}, {-inf, -inf}, {-inf, -inf}, d[at[l]], 0, 0};
		tree[i].d[type[at[l]]] = d[at[l]];
		tree[i].vl[type[at[l]]] = -d[at[l]];
		tree[i].vr[type[at[l]]] = -d[at[l]];
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		build(lc, l, mid);
		build(rc, mid + 1, r);
		merge(i, lc, rc);
	}
	// cout << "info about range " << l << " to " << r << '\n';
	// cout << tree[i].d[0] << ' ' << tree[i].vl[0] << ' ' << tree[i].vr[0] << ' ' << tree[i].min_d << ' ' << tree[i].ans << '\n';
}

void merge(int i, int lc, int rc) {
	tree[i].d.resize(2);
	tree[i].vl.resize(2);
	tree[i].vr.resize(2);
	for (int j = 0; j < 2; ++j) {
		tree[i].d[j] = max(tree[lc].d[j], tree[rc].d[j]);
		tree[i].vl[j] = max(tree[lc].vl[j], tree[rc].vl[j]);
		tree[i].vr[j] = max(tree[lc].vr[j], tree[rc].vr[j]);
		tree[i].vl[j] = max(tree[i].vl[j], tree[lc].d[j] - 2 * tree[rc].min_d);
		tree[i].vr[j] = max(tree[i].vr[j], -2 * tree[lc].min_d + tree[rc].d[j]);
	}
	tree[i].min_d = min(tree[lc].min_d, tree[rc].min_d);
	tree[i].ans = max(tree[lc].ans, tree[rc].ans);
	for (int j = 0; j < 2; ++j) {
		tree[i].ans = max(tree[i].ans, tree[lc].vl[j] + tree[rc].d[j]);
		tree[i].ans = max(tree[i].ans, tree[lc].d[j] + tree[rc].vr[j]);
	}
}

void update(int i, int l, int r, int ql, int qr) {
	if (l > qr or ql > r) {
		return;
	} else if (ql <= l and r <= qr) {
		apply_flip(i);
		tree[i].lazy ^= 1;
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		propagate(i, lc, rc);
		update(lc, l, mid, ql, qr);
		update(rc, mid + 1, r, ql, qr);
		merge(i, lc, rc);
	}
}

void propagate(int i, int lc, int rc) {
	if (tree[i].lazy) {
		apply_flip(lc);
		apply_flip(rc);
		tree[lc].lazy ^= 1;
		tree[rc].lazy ^= 1;
		tree[i].lazy = 0;
	}
}

void apply_flip(int i) {
	swap(tree[i].d[0], tree[i].d[1]);
	swap(tree[i].vl[0], tree[i].vl[1]);
	swap(tree[i].vr[0], tree[i].vr[1]);
}