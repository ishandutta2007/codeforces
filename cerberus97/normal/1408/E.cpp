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

const int N = 2e5 + 10;

struct edge_t {
	int u, v, w;
	bool operator<(const edge_t& o) const {
		return w > o.w;
	}
};

int par[N];

int get_root(int u);
bool merge(int u, int v);

int main() {
	fast_cin();
	int m, n;
	cin >> m >> n;
	vector<int> a(m), b(n);
	for (auto& i : a) {
		cin >> i;
	}
	for (auto& i : b) {
		cin >> i;
	}
	vector<edge_t> edges;
	ll ans = 0;
	for (int u = 0; u < m; ++u) {
		int s; cin >> s;
		while (s--) {
			int v; cin >> v;
			edges.pb({u, v + m - 1, a[u] + b[v - 1]});
			ans += a[u] + b[v - 1];
		}
	}
	sort(edges.begin(), edges.end());
	for (int i = 0; i < n + m; ++i) {
		par[i] = i;
	}
	for (auto& e : edges) {
		if (merge(e.u, e.v)) {
			ans -= e.w;
		}
	}
	cout << ans << '\n';
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
	} else {
		par[u] = v;
		return true;
	}
}