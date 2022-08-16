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

const int N = 5e5 + 10, P = 5e5 + 10;
const ll inf = 1e18 + 42;

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

point line[4 * P];

struct li_chao_tree {
	void add_line(point add, int i = 1, ll l = 0, ll r = P) {
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
	ll query(ll x, int i = 1, ll l = 0, ll r = P) {
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
	void clear(int i = 1, ll l = 0, ll r = P) {
		ll m = (l + r) / 2;
		if (line[i].m == 0  and line[i].c == inf) {
			return;
		} else if (l == r - 1) {
			line[i] = {0, inf};
		} else {
			line[i] = {0, inf};
			clear(2 * i, l, m);
			clear(2 * i + 1, m, r);
		}
	}
} lct;

vector<int> g[N];
ll ans = inf;
int sz[N], deg[N];
ll cost[N];

void dfs1(int u, int p);
ll dfs2(int u, int p, int n);
ll c2(ll x);

int main() {
	fast_cin();
	int n; cin >> n;
	if (n == 2) {
		cout << 2 << endl;
		return 0;
	}
	for (int i = 2; i <= n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
		++deg[u]; ++deg[v];
	}
	int root = 1;
	while (deg[root] == 1) {
		++root;
	}
	dfs1(root, 0);
	dfs2(root, 0, n);
	cout << 2 * c2(n) - ans << endl;
}

void dfs1(int u, int p) {
	sz[u] = 1;
	for (auto &v : g[u]) {
		if (v == p) {
			continue;
		} else {
			dfs1(v, u);
			sz[u] += sz[v];
		}
	}
}

ll dfs2(int u, int p, int n) {
	vector<pll> check;
	cost[u] = c2(sz[u]);
	if (p != 0) {
		cost[u] += cost[p] - c2(sz[p]) + c2(sz[p] - sz[u]);
	}
	ll ret = cost[u];
	for (auto &v : g[u]) {
		if (v == p) {
			continue;
		} else {
			ll cand = dfs2(v, u, n);
			ret = min(ret, cand);
			check.pb({sz[v], cand});
		}
	}
	if (check.size() > 1) {
		for (auto &i : check) {
			i.second -= (cost[u] - c2(sz[u]) + c2(sz[u] - i.first));
			i.second += (i.first * i.first + i.first - 2 * n * i.first) / 2;
		}
		lct.add_line({check[0].first, check[0].second});
		int k = check.size();
		for (int i = 1; i < k; ++i) {
			ll temp = lct.query(check[i].first) + check[i].second + c2(n);
			ans = min(ans, temp);
			lct.add_line({check[i].first, check[i].second});
		}
		lct.clear();
	}
	return ret;
}

ll c2(ll x) {
	return (x * (x - 1)) / 2;
}