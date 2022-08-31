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

const int N = 1.5e5 + 10, B = sqrt(N) + 10, mod = 998244353;

vector<int> g[N];
int sz[N], par[N], up[N], ent[N], ext[N], nxt = 1;
ll bit[N], at[N];

void dfs_sz(int u, int p);
void dfs_tour(int u, int p);
ll pwr(ll x, ll e);
void update(int idx, int n, ll val);
ll query(int idx);

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
	dfs_sz(1, 0);
	dfs_tour(1, 0);
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int v; ll d;
			cin >> v >> d;
			at[v] += d;
			for (auto &u : g[v]) {
				update(ent[u], n, d * (n - sz[u]));
				update(ext[u], n, -d * (n - sz[u]));
				break;
			}
			update(1, n, d * sz[v]);
			update(ent[v], n, -d * sz[v]);
			update(ext[v], n, d * sz[v]);
			update(ent[v], n, d * n);
			update(ent[v] + 1, n, -d * n);
		} else {
			int v; cin >> v;
			ll num = query(ent[v]) % mod;
			while (v) {
				v = up[v];
				num += at[par[v]] * (n - sz[v]);
				num %= mod;
				v = par[v];
			}
			num += mod;
			num *= pwr(n, mod - 2);
			cout << num % mod << '\n';
		}
	}
}

void dfs_sz(int u, int p) {
	sz[u] = 1;
	par[u] = p;
	for (int i = 0; i < g[u].size(); ++i) {
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
}

void dfs_tour(int u, int p) {
	ent[u] = nxt++;
	up[u] = (p and g[p][0] == u) ? up[p] : u;
	for (auto &v : g[u]) {
		dfs_tour(v, u);
	}
	ext[u] = nxt;
}

ll pwr(ll x, ll e) {
	ll res = 1;
	while (e) {
		if (e & 1) {
			res = (res * x) % mod;
		}
		x = (x * x) % mod;
		e /= 2;
	}
	return res;
}

void update(int idx, int n, ll val) {
    while (idx <= n) {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

ll query(int idx) {
    ll res = 0;
    while (idx > 0) {
        res += bit[idx];
        idx -= idx & -idx;
    }
    return res;
}