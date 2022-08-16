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

#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char *name, Arg1 &&arg1) {
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

#else
#define trace(...)
#endif // ifndef ONLINE_JUDGE

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 3e5 + 10, LOG = log2(N) + 2;
const ll inf = 1e18 + 42;

struct edge_t {
	int v; vector<ll> w;
	// edge_t() : w(2) {}
};

vector<edge_t> g[N];
ll cost[N];
int depth[N];
int up[N][LOG];
ll up_cost[N][LOG][2][2];

void dfs1(int u, int p, vector<ll> w);
void dfs2(int u, int p, vector<ll> w);
int get_lca(int u, int v);
ll get_cost(int u, int l, int k1, int k2);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> cost[i];
	}
	for (int i = 1; i < n; ++i) {
		int u, v; ll w1, w2;
		cin >> u >> v >> w1 >> w2;
		g[u].pb({v, {w2, w1}});
		g[v].pb({u, {w2, w1}});
	}
	cost[0] = inf;
	dfs1(1, 0, {0, 0});
	dfs2(1, 0, {0, 0});
	for (int i = 1; i <= n; ++i) {
		trace(i, depth[i], cost[i]);
	}
	int q; cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		int k1 = (u % 2), k2 = (v % 2);
		u = (u + 1) / 2;
		v = (v + 1) / 2;
		int l = get_lca(u, v);
		trace(u, v, l);
		ll cand1 = get_cost(u, l, k1, 0) + get_cost(v, l, k2, 0);
		ll cand2 = get_cost(u, l, k1, 1) + get_cost(v, l, k2, 1);
		cout << min(cand1, cand2) << '\n';
	}
}

void dfs1(int u, int p, vector<ll> w) {
	depth[u] = depth[p] + 1;
	for (auto &e : g[u]) {
		int v = e.v;
		if (v == p) {
			continue;
		}
		dfs1(v, u, e.w);
		for (int j = 0; j < 2; ++j) {
			cost[u] = min(cost[u], e.w[j] + e.w[1 - j] + cost[v]);
		}
	}
}

void dfs2(int u, int p, vector<ll> w) {
	cost[u] = min(cost[u], w[0] + w[1] + cost[p]);
	for (int j = 0; j < 2; ++j) {
		up_cost[u][0][j][j] = min(w[j], cost[u] + w[1 - j] + cost[p]);
		up_cost[u][0][j][1 - j] = min(cost[u] + w[1 - j], w[j] + cost[p]);
	}

	up[u][0] = p;
	for (int j = 1; j < LOG; ++j) {
		int t = up[u][j - 1];
		up[u][j] = up[t][j - 1];
		for (int k = 0; k < 2; ++k) {
			ll cand1 = up_cost[u][j - 1][k][k] + up_cost[t][j - 1][k][k];
			ll cand2 = up_cost[u][j - 1][k][1 - k] + up_cost[t][j - 1][1 - k][k];
			up_cost[u][j][k][k] = min(cand1, cand2);

			cand1 = up_cost[u][j - 1][k][k] + up_cost[t][j - 1][k][1 - k];
			cand2 = up_cost[u][j - 1][k][1 - k] + up_cost[t][j - 1][1 - k][1 - k];
			up_cost[u][j][k][1 - k] = min(cand1, cand2);
		}
	}

	for (auto &e : g[u]) {
		int v = e.v;
		if (v == p) {
			continue;
		}
		dfs2(v, u, e.w);
	}
}

int get_lca(int u, int v) {
	if (depth[u] < depth[v]) {
		swap(u, v);
	}
	for (int j = LOG - 1; j >= 0; --j) {
		if (depth[u] - (1 << j) >= depth[v]) {
			trace(u, v, (1 << j), depth[u], depth[v]);
			u = up[u][j];
		}
	}
	if (u == v) {
		return u;
	}
	for (int j = LOG - 1; j >= 0; --j) {
		if (up[u][j] != up[v][j]) {
			u = up[u][j];
			v = up[v][j];
		}
	}
	return up[u][0];
}

ll get_cost(int u, int l, int k1, int k2) {
	ll d1 = 0, d2 = cost[u];
	for (int j = LOG - 1; j >= 0; --j) {
		if (depth[up[u][j]] >= depth[l]) {
			ll t1 = min(d1 + up_cost[u][j][k1][k1], d2 + up_cost[u][j][1 - k1][k1]);
			ll t2 = min(d1 + up_cost[u][j][k1][1 - k1], d2 + up_cost[u][j][1 - k1][1 - k1]);
			d1 = t1; d2 = t2;
			u = up[u][j];
		}
	}
	if (k1 == k2) {
		return d1;
	} else {
		return d2;
	}
}