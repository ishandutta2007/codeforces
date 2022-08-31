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

const int N = 1e5 + 10, P = 1e5 + 10;
const ll inf = 1e18 + 42;

// vector<pii> debug_set;


/* Usage:
	Tutorial - https://cp-algorithms.com/geometry/convex_hull_trick.html

	Add line y = mx + c using add_line({m, c}).
	Query for point x using query(x).
	For max instead of min, change lines marked with ###
	P > largest point at which query occurs

	Coordinate compress if too large point values
*/

struct point {
	ll m, c; // y = mx + c
	point() : m(0), c(inf) {} // ### (inf -> -inf)
	point(ll _m, ll _c) : m(_m), c(_c) {}
};

point line[8 * P];

struct li_chao_tree {
	void add_line(point add, int i = 1, ll l = -P, ll r = P) {
		// if (i == 1) {
		// 	debug_set.pb({add.m, add.c});
		// }
		ll m = (l + r) / 2;
		bool lef = (eval(add, l) < eval(line[i], l)); // ###
		bool mid = (eval(add, m) < eval(line[i], m)); // ###
		if (mid) {
			swap(add, line[i]);
		}
		if (l == r - 1) { // Leaf Node
			return;
		} else if (lef != mid) { // Intersection point in [l, m)
			add_line(add, 2 * i, l, m);
		} else { // Intersection point in [m, r)
			add_line(add, 2 * i + 1, m, r);
		}
	}
	ll query(ll x, int i = 1, ll l = -P, ll r = P) {
		ll ans = eval(line[i], x), m = (l + r) / 2;
		if (l == r - 1) {
			return ans;
		} else if (x < m) {
			return min(ans, query(x, 2 * i, l, m)); // ###
		} else {
			return min(ans, query(x, 2 * i + 1, m, r)); // ###
		}
	}
	ll eval(point p, ll x) {
		return p.m * x + p.c;
	}
	void clear(int i = 1, ll l = -P, ll r = P) {
		// if (i == 1) {
		// 	debug_set.clear();
		// 	for (int j = 1; j < 8 * P; ++j) {
		// 		line[j] = point(0, inf);
		// 	}
		// 	return;
		// }
		ll m = (l + r) / 2;
		if (line[i].c == inf) {
			return;
		}
		line[i] = point();
		if (l == r - 1) {
			return;
		}
		clear(2 * i, l, m);
		clear(2 * i + 1, m, r);
	}
};

void dfs1(int u, int p);
void dfs2(int u, int p);
void naive(int u, int p);

int a[N], b[N];
vector<int> g[N];
int sz[N], ent[N], ext[N];
int tour[2 * N], nxt_time = 0;
ll dp[N], dp_naive[N];
li_chao_tree lct;

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	// naive(1, 0);
	for (int i = 1; i <= n; ++i) {
		cout << dp[i] << ' ';
	}
	// cout << endl;
	// for (int i = 1; i <= n; ++i) {
	// 	cout << dp_naive[i] << ' ';
	// }
	// cout << endl;
	// for (int i = 1; i <= n; ++i) {
	// 	if (dp[i] != dp_naive[i]) {
	// 		cerr << "WTF" << endl;
	// 	}
	// }
}

void dfs1(int u, int p) {
	sz[u] = 1;
	ent[u] = nxt_time;
	tour[nxt_time++] = u;
	for (auto &v : g[u]) {
		if (v != p) {
			dfs1(v, u);
			sz[u] += sz[v];
		}
	}
	ext[u] = nxt_time++;
}

void dfs2(int u, int p) {
	int largest = -1, largest_sz = -1;
	for (auto &v : g[u]) {
		if (v == p) {
			continue;
		}
		if (sz[v] > largest_sz) {
			largest_sz = sz[v];
			largest = v;
		}
	}
	if (largest == -1) {
		lct.add_line({b[u], dp[u]});
		return;
	}
	for (auto &v : g[u]) {
		if (v != p and v != largest) {
			dfs2(v, u);
			lct.clear();
		}
	}
	dfs2(largest, u);
	for (auto &v : g[u]) {
		if (v != p and v != largest) {
			for (int t = ent[v]; t < ext[v]; ++t) {
				if (tour[t] != 0) {
					lct.add_line({b[tour[t]], dp[tour[t]]});
				}
			}
		}
	}
	// if (u == 2) {
	// 	for (auto &i : debug_set) {
	// 		cout << i.first << ' ' << i.second << endl;
	// 	}
	// 	cout << lct.query(a[u]) << endl;
	// }
	dp[u] = lct.query(a[u]);
	lct.add_line({b[u], dp[u]});
}

void naive(int u, int p) {
	for (auto &v : g[u]) {
		if (v != p) {
			naive(v, u);
			dp_naive[u] = inf;
		}
	}
	if (!dp_naive[u]) {
		return;
	}
	for (int t = ent[u] + 1; t < ext[u]; ++t) {
		if (tour[t]) {
			int v = tour[t];
			dp_naive[u] = min(dp_naive[u], dp[v] + a[u] * b[v]);
		}
	}
}