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

const int N = 5e5 + 10;

int c[N];
pair<int, bool> par[N];
bool ok[N], vis[N], assign[N];
vector<pair<int, bool>> g[N];

int get_root(int u, bool& path);
void merge(int u, int v);
bool check(int u);

int main() {
	fast_cin();
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		par[i] = {i, 0};
	}
	for (int i = 1; i <= k; ++i) {
		ok[i] = true;
	}
	vector<pii> edges(m);
	for (auto& [u, v] : edges) {
		cin >> u >> v;
		if (c[u] == c[v]) {
			merge(u, v);
		} else if (c[u] > c[v]) {
			swap(u, v);
		}
	}
	ll good = 0;
	for (int i = 1; i <= k; ++i) {
		good += ok[i];
	}
	ll ans = (good * (good - 1)) / 2;
	map<pii, vector<pii>> cross_edges;
	for (auto& [u, v] : edges) {
		if (c[u] != c[v]) {
			cross_edges[{c[u], c[v]}].pb({u, v});
		}
	}
	for (auto& [gp, e] : cross_edges) {
		int g1 = gp.first, g2 = gp.second;
		if (!ok[g1] or !ok[g2]) {
			continue;
		}
		vector<int> seen;
		for (auto& [u, v] : e) {
			bool type = 1;
			int ru = get_root(u, type), rv = get_root(v, type);
			seen.pb(ru);
			seen.pb(rv);
			g[ru].pb({rv, type});
			g[rv].pb({ru, type});
		}
		sort(seen.begin(), seen.end());
		seen.erase(unique(seen.begin(), seen.end()), seen.end());
		bool is_ok = true;
		for (auto& u : seen) {
			vis[u] = false;
		}
		for (auto& u : seen) {
			is_ok &= check(u);
		}
		for (auto& u : seen) {
			g[u].clear();
		}
		ans -= (!is_ok);
	}
	cout << ans << '\n';
}

int get_root(int u, bool& path) {
	if (u != par[u].first) {
		par[u].first = get_root(par[u].first, par[u].second);
		path ^= par[u].second;
	}
	return par[u].first;
}

void merge(int u, int v) {
	bool type = 1;
	u = get_root(u, type);
	v = get_root(v, type);
	if (u == v) {
		if (type) {
			ok[c[u]] = false;
		}
	} else {
		par[v] = {u, type};
	}
}

bool check(int u) {
	if (vis[u]) {
		return true;
	}
	bool ans = true;
	vis[u] = true;
	for (auto& [v, type] : g[u]) {
		if (!vis[v]) {
			assign[v] = assign[u] ^ type;
			ans &= check(v);
		}
		ans &= ((assign[u] ^ assign[v]) == type);
	}
	return ans;
}