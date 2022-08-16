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

const int N = 2e3 + 10;

struct edge_t {
	int u, v;
	ll w;
	bool operator<(const edge_t &o) const {
		return w < o.w;
	}
};

int x[N], y[N];
ll c[N], k[N];
int par[N], station[N];

int get_root(int u);
bool merge(int u, int v);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
	}
	ll sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		sum += c[i];
		par[i] = i;
		station[i] = i;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> k[i];
	}
	vector<edge_t> edges;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			ll dist = abs(x[i] - x[j]) + abs(y[i] - y[j]);
			ll wt = (k[i] + k[j]) * dist;
			edges.pb({i, j, wt});
		}
	}
	sort(edges.begin(), edges.end());
	vector<edge_t> final_edges;
	for (auto &e : edges) {
		int u = station[get_root(e.u)];
		int v = station[get_root(e.v)];
		if (u != v and e.w < max(c[u], c[v])) {
			sum -= max(c[u], c[v]) - e.w;
			merge(u, v);
			final_edges.pb(e);
		}
	}
	cout << sum << '\n';
	cout << n - final_edges.size() << '\n';
	for (int i = 1; i <= n; ++i) {
		if (par[i] == i) {
			cout << station[i] << ' ';
		}
	}
	cout << '\n' << final_edges.size() << '\n';
	for (auto &e : final_edges) {
		cout << e.u << ' ' << e.v << '\n';
	}
}

int get_root(int u) {
	if (par[u] != u) {
		par[u] = get_root(par[u]);
	}
	return par[u];
}

bool merge(int u, int v) {
	u = get_root(u);
	v = get_root(v);
	if (u == v) {
		return false;
	} else if (c[station[u]] > c[station[v]]) {
		swap(u, v);
	}
	par[v] = u;
	return true;
}