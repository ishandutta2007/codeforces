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

vector<int> g[N];
vector<pii> updates[N];
int par[N], depth[N], max_dn[N], ent[N], ext[N], eid[N];
int cur_sz[N], ans[N], tree[4 * N], lazy[4 * N];
int nxt = 2, diameter = 0;

void dfs1(int u, int p);
void dfs2(int u, int up_d);
void update(int i, int l, int r, int ql, int qr, int x);
void propagate(int i, int lc, int rc);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	multiset<int> vtx_sizes;
	for (int i = 1; i <= n; ++i) {
		cur_sz[i] = (g[i].size() + (i != 1));
		vtx_sizes.insert(cur_sz[i]);
		ans[1] = max(ans[1], cur_sz[i] + 1);
		// cout << i << ' ' << cur_sz[i] << endl;
		// cout << i << ' ' << eid[i] << ' ' << ent[i] << ' ' << ext[i] << endl;
	}
	for (int i = 2; i <= n; ++i) {
		// cout << i << ' ' << cur_sz[i] + cur_sz[par[i]] - 2 << endl;
		update(1, 2, n, eid[i], eid[i], cur_sz[i] + cur_sz[par[i]] - 2);
	}
	for (int d = 1; 2 * d - 1 <= n; ++d) {
		for (auto &p : updates[d]) {
			int u = p.first, v = p.second;
			vtx_sizes.erase(vtx_sizes.find(cur_sz[u]));
			--cur_sz[u];
			vtx_sizes.insert(cur_sz[u]);
			update(1, 2, n, ent[u], ext[u] - 1, -1);
			update(1, 2, n, eid[u], eid[u], -1);
			int pos = (v == par[u] ? eid[u] : eid[v]);
			update(1, 2, n, pos, pos, -n);
		}
		ans[2 * d] = max(ans[2 * d], (vtx_sizes.empty() ? 0 : *vtx_sizes.rbegin()));
		ans[2 * d - 1] = max(ans[2 * d - 1], (vtx_sizes.empty() ? 0 : *vtx_sizes.rbegin()));
		ans[2 * d] = max(ans[2 * d], tree[1]);
	}
	for (int i = 1; i <= n; ++i) {
		if (i <= diameter) {
			ans[i] = max(ans[i], 2);
		}
		cout << max(1, ans[i]) << ' ';
	}
	cout << endl;
}

void dfs1(int u, int p) {
	par[u] = p;
	depth[u] = depth[p] + 1;
	for (int i = 0; i < g[u].size(); ++i) {
		if (g[u][i] == p) {
			g[u].erase(g[u].begin() + i);
			break;
		}
	}
	max_dn[u] = 0;
	for (auto &v : g[u]) {
		dfs1(v, u);
		max_dn[u] = max(max_dn[u], 1 + max_dn[v]);
	}
}

void dfs2(int u, int up_d) {
	diameter = max(diameter, up_d);
	// cout << u << ' ' << depth[u] << endl;
	// cout << u << ' ' << up_d << endl;
	multiset<pii> temp;
	if (up_d) {
		temp.insert({up_d, par[u]});
	}
	ent[u] = nxt;
	for (auto &v : g[u]) {
		eid[v] = nxt++;
		temp.insert({max_dn[v] + 1, v});
	}
	int cnt = temp.size();
	for (auto it = temp.begin(); next(it) != temp.end(); ++it, --cnt) {
		auto nx = next(it);
		if (nx->first > it->first) {
			ans[2 * it->first + 1] = max(ans[2 * it->first + 1], cnt);
		}
	}
	ext[u] = nxt;
	for (auto &p : temp) {
		int d = p.first, v = p.second;
		updates[d + 1].pb({u, v});
		// cout << u << ' ' << v << ' ' << d << endl;
	}
	for (auto &v : g[u]) {
		temp.erase({max_dn[v] + 1, v});
		int nxt_up = max(1, (temp.empty() ? 0 : 1 + temp.rbegin()->first));
		dfs2(v, nxt_up);
		temp.insert({max_dn[v] + 1, v});
	}
}

void update(int i, int l, int r, int ql, int qr, int x) {
	if (l > qr or ql > r) {
		return;
	} else if (ql <= l and r <= qr) {
		tree[i] += x;
		lazy[i] += x;
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		propagate(i, lc, rc);
		update(lc, l, mid, ql, qr, x);
		update(rc, mid + 1, r, ql, qr, x);
		tree[i] = max(tree[lc], tree[rc]);
	}
}

void propagate(int i, int lc, int rc) {
	tree[lc] += lazy[i];
	tree[rc] += lazy[i];
	lazy[lc] += lazy[i];
	lazy[rc] += lazy[i];
	lazy[i] = 0;
}