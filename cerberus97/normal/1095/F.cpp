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

const int N = 2e5 + 10;
const ll inf = 1e18;

struct edge
{
	int u, v; ll w;
	bool operator<(const edge &o) const {
		return w < o.w;
	}
};

int par[N], sz[N];
ll a[N];
vector<edge> edges;	

int get_root(int u);
bool merge(int u, int v);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	int min_p = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] < a[min_p]) {
			min_p = i;
		}
		par[i] = i;
		sz[i] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		edges.pb({i, min_p, a[i] + a[min_p]});
	}
	while (m--) {
		int x, y; ll w;
		cin >> x >> y >> w;
		edges.pb({x, y, w});
	}
	sort(edges.begin(), edges.end());
	ll ans = 0;
	for (auto &e : edges) {
		if (merge(e.u, e.v)) {
			ans += e.w;
		}
	}
	cout << ans << endl;
}

int get_root(int u) {
	if (u != par[u]) {
		par[u] = get_root(par[u]);
	}
	return par[u];
}

bool merge(int u, int v) {
	u = get_root(u);
	v = get_root(v);
	if (u == v) {
		return false;
	} else if (sz[u] < sz[v]) {
		swap(u, v);
	}
	sz[u] += sz[v];
	par[v] = u;
	return true;
}