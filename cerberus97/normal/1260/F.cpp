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

const int N = 1e5 + 10, C = 1e5, mod = 1e9 + 7;

int l[N], r[N];
ll inv_s[N];

vector<int> g[N];
int sz[N], depth[N], ent[N], ext[N], at[N], nxt = 1;

pii tree[4 * N], lazy[4 * N];
ll ans = 0;

void dfs_sz(int u, int p);
void dfs_tour(int u);
void solve(int u, bool keep);
void update(int i, int l, int r, int ql, int qr, ll v1, ll v2);
pii query(int i, int l, int r, int ql, int qr);
void propagate(int i, int lc, int rc, int l, int mid, int r);
void add(pii &p1, pii p2);
ll pwr(ll x, ll e);
ll mul(ll a, ll b);

int main() {
	fast_cin();
	int n; cin >> n;
	ll all = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> l[i] >> r[i];
		ll s = (r[i] - l[i] + 1);
		all = mul(all, s);
		inv_s[i] = pwr(s, mod - 2);
	}
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs_sz(1, 0);
	dfs_tour(1);
	solve(1, true);
	ans = mul(ans, all);
	cout << ans << '\n';
}

void dfs_sz(int u, int p) {
	sz[u] = 1;
	depth[u] = depth[p] + 1;
	for (int i = 0; i < int(g[u].size()); ++i) {
		if (g[u][i] == p) {
			g[u].erase(g[u].begin() + i);
			break;
		}
	}
	for (auto &v : g[u]) {
		dfs_sz(v, u);
		sz[u] += sz[v];
		if (sz[v] > sz[g[u][0]]) {
			swap(v, g[u][0]);
		}
	}
	reverse(g[u].begin(), g[u].end());
}

void dfs_tour(int u) {
	at[nxt] = u;
	ent[u] = nxt++;
	for (auto &v : g[u]) {
		dfs_tour(v);
	}
	ext[u] = nxt;
}

void solve(int u, bool keep) {
	for (auto &v : g[u]) {
		solve(v, v == g[u].back());
	}
	for (int i = 0; i < int(g[u].size()) - 1; ++i) {
		int v = g[u][i];
		for (int t = ent[v]; t < ext[v]; ++t) {
			int w = at[t];
			auto q = query(1, 1, C, l[w], r[w]);
			ll temp = mul(depth[w] - 2 * depth[u] + 2 * mod, q.first);
			temp += q.second;
			ans += mul(temp, inv_s[w]);
			ans %= mod;
		}
		for (int t = ent[v]; t < ext[v]; ++t) {
			int w = at[t];
			update(1, 1, C, l[w], r[w], inv_s[w], mul(inv_s[w], depth[w]));
		}
	}
	auto q = query(1, 1, C, l[u], r[u]);
	ll temp = mul(depth[u] - 2 * depth[u] + 2 * mod, q.first);
	temp += q.second;
	ans += mul(temp, inv_s[u]);
	ans %= mod;
	update(1, 1, C, l[u], r[u], inv_s[u], mul(inv_s[u], depth[u]));
	if (!keep) {
		for (int t = ent[u]; t < ext[u]; ++t) {
			int w = at[t];
			update(1, 1, C, l[w], r[w], mod - inv_s[w], mod - mul(inv_s[w], depth[w]));
		}
	}
}

void update(int i, int l, int r, int ql, int qr, ll v1, ll v2) {
	if (l > qr or ql > r) {
		return;
	} else if (ql <= l and r <= qr) {
		add(tree[i], {mul(v1, r - l + 1), mul(v2, r - l + 1)});
		add(lazy[i], {v1, v2});
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		propagate(i, lc, rc, l, mid, r);
		update(lc, l, mid, ql, qr, v1, v2);
		update(rc, mid + 1, r, ql, qr, v1, v2);
		tree[i] = tree[lc];
		add(tree[i], tree[rc]);
	}
}

pii query(int i, int l, int r, int ql, int qr) {
	if (l > qr or ql > r) {
		return {0, 0};
	} else if (ql <= l and r <= qr) {
		return tree[i];
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		propagate(i, lc, rc, l, mid, r);
		pii res = query(lc, l, mid, ql, qr);
		add(res, query(rc, mid + 1, r, ql, qr));
		return res;
	}
}

void propagate(int i, int lc, int rc, int l, int mid, int r) {
	add(tree[lc], {mul(lazy[i].first, (mid - l + 1)), mul(lazy[i].second, (mid - l + 1))});
	add(lazy[lc], lazy[i]);
	add(tree[rc], {mul(lazy[i].first, (r - mid)), mul(lazy[i].second, (r - mid))});
	add(lazy[rc], lazy[i]);
	lazy[i] = {0, 0};
}

void add(pii &p1, pii p2) {
	p1.first = (p1.first + p2.first);
	if (p1.first >= mod) {
		p1.first -= mod;
	}
	p1.second = (p1.second + p2.second);
	if (p1.second >= mod) {
		p1.second -= mod;
	}
}

ll pwr(ll x, ll e) {
	ll res = 1;
	while (e) {
		if (e & 1) {
			res = mul(res, x);
		}
		x = mul(x, x);
		e /= 2;
	}
	return res;
}

ll mul(ll a, ll b) {
	return (a * b) % mod;
}