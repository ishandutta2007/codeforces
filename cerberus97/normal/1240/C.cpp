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

const int N = 5e5 + 10;

vector<pll> g[N];

pll solve(int u, int p, int k);

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; ++i) {
			g[i].clear();
		}
		for (int i = 2; i <= n; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			g[u].pb({v, w});
			g[v].pb({u, w});
		}
		auto ans = solve(1, 0, k);
		cout << ans.first << '\n';
	}
}

pll solve(int u, int p, int k) {
	ll sum = 0;
	vector<ll> children;
	for (auto &e : g[u]) {
		int v = e.first;
		ll w = e.second;
		if (v == p) {
			continue;
		}
		auto ans = solve(v, u, k);
		sum += ans.first;
		if (w > ans.second) {
			children.pb(w - ans.second);
		}
	}
	sort(children.begin(), children.end(), greater<ll>());
	int sz = children.size();
	for (int i = 0; i < min(sz, k); ++i) {
		sum += children[i];
	}
	ll min_picked = 0;
	if (sz >= k) {
		min_picked = children[k - 1];
	}
	return {sum, min_picked};
}