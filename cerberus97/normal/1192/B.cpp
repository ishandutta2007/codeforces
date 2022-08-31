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
 
const int N = 1e5 + 10, inf = 1e9 + 42;
 
struct node_t {
	ll mx, mn, to_right, to_left, lazy, ans;
};
 
node_t tree[8 * N];
ll d[2 * N], depth[N], c[N];
vector<pll> g[N];
int a[N], b[N];
int ent[N], ext[N];
int nxt = 0;
 
void dfs(int u, int p);
void update(int i, int l, int r, int ql, int qr, ll x);
void add(int i, ll x);
void combine(int i, int lc, int rc);
void propagate(int i, int lc, int rc);
 
int main() {
	fast_cin();
	int n, q; ll w;
	cin >> n >> q >> w;
	for (int i = 0; i < n - 1; ++i) {
		cin >> a[i] >> b[i] >> c[i];
		g[a[i]].pb({b[i], c[i]});
		g[b[i]].pb({a[i], c[i]});
	}
	dfs(1, 0);
	for (int i = 0; i < n - 1; ++i) {
		if (ent[a[i]] < ent[b[i]]) {
			swap(a[i], b[i]);
		}
	}
	int m = 2 * n - 1;
	for (int i = 0; i < m; ++i) {
		update(1, 0, m - 1, i, i, d[i]);
	}
	ll last = 0;
	while (q--) {
		int id; ll e;
		cin >> id >> e;
		id = (id + last) % (n - 1);
		e = (e + last) % w;
		update(1, 0, m - 1, ent[a[id]], ext[a[id]] - 1, e - c[id]);
		c[id] = e;
		last = tree[1].ans;
		cout << last << '\n';
	}
}

void dfs(int u, int p) {
	d[nxt] = depth[u];
	ent[u] = nxt++;
	for (auto &e : g[u]) {
		int v = e.first; ll w = e.second;
		if (v != p) {
			depth[v] = depth[u] + w;
			dfs(v, u);
			d[nxt++] = depth[u];
		}
	}
	ext[u] = nxt;
}
 
void update(int i, int l, int r, int ql, int qr, ll x) {
	if (l > qr or ql > r) {
		return;
	} else if (ql <= l and r <= qr) {
		add(i, x);
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		propagate(i, lc, rc);
		update(lc, l, mid, ql, qr, x);
		update(rc, mid + 1, r, ql, qr, x);
		combine(i, lc, rc);
	}
}
 
void add(int i, ll x) {
	tree[i].mx += x;
	tree[i].mn += x;
	tree[i].to_right -= x;
	tree[i].to_left -= x;
	tree[i].lazy += x;
}
 
void combine(int i, int lc, int rc) {
	tree[i].mx = max(tree[lc].mx, tree[rc].mx);
	tree[i].mn = min(tree[lc].mn, tree[rc].mn);
	tree[i].to_right = max(tree[lc].to_right, tree[rc].to_right);
	tree[i].to_right = max(tree[i].to_right, tree[rc].mx - 2 * tree[lc].mn);
	tree[i].to_left = max(tree[lc].to_left, tree[rc].to_left);
	tree[i].to_left = max(tree[i].to_left, tree[lc].mx - 2 * tree[rc].mn);
	tree[i].ans = max(tree[lc].ans, tree[rc].ans);
	tree[i].ans = max(tree[i].ans, max(tree[lc].mx + tree[rc].to_right, tree[lc].to_left + tree[rc].mx));
}
 
void propagate(int i, int lc, int rc) {
	add(lc, tree[i].lazy);
	add(rc, tree[i].lazy);
	tree[i].lazy = 0;
}