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

const int N = 3e5 + 10;

vector<pll> g[N];
ll best[N], w[N];

ll solve(int u, int p);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> w[i];
	}
	for (int i = 1; i < n; ++i) {
		int u, v; ll c;
		cin >> u >> v >> c;
		g[u].pb({v, c});
		g[v].pb({u, c});
	}
	cout << solve(1, 0) << endl;
}

ll solve(int u, int p) {
	vector<ll> values;
	best[u] = w[u];
	ll ans = w[u];
	for (auto &e : g[u]) {
		int v = e.first, c = e.second;
		if (v != p) {
			ans = max(ans, solve(v, u));
			values.pb(best[v] + w[u] - c);
			best[u] = max(best[u], values.back());
		}
	}
	sort(values.begin(), values.end());
	int k = values.size();
	if (k >= 2) {
		ans = max(ans, values[k - 1] + values[k - 2] - w[u]);
	}
	if (k >= 1) {
		ans = max(ans, values[k - 1]);
	}
	return ans;
}