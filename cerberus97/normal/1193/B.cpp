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

const int N = 1e5 + 10;

int p[N], id[N], sz[N];
pii fruit[N];
vector<int> g[N];
map<int, ll> dp[N];

int main() {
	fast_cin();
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 2; i <= n; ++i) {
		cin >> p[i];
		g[p[i]].pb(i);
	}
	for (int i = 1; i <= m; ++i) {
		int v, d, w;
		cin >> v >> d >> w;
		fruit[v] = {d, w};
	}
	for (int u = n; u >= 1; --u) {
		sz[u] = 1;
		if (g[u].empty()) {
			id[u] = u;
			dp[u][fruit[u].first] = fruit[u].second;
		} else {
			int big_sz = 0, big = -1;
			for (auto &v : g[u]) {
				sz[u] += sz[v];
				if (sz[v] > big_sz) {
					big_sz = sz[v];
					big = v;
				}
			}
			id[u] = id[big];
			auto &cur = dp[id[u]];
			for (auto &v : g[u]) {
				if (v == big) {
					continue;
				}
				for (auto &i : dp[id[v]]) {
					cur[i.first] += i.second;
				}
				dp[id[v]].clear();
			}
			int d = fruit[u].first, w = fruit[u].second;
			ll sum = 0;
			while (true) {
				auto it = cur.upper_bound(d);
				if (it == cur.end()) {
					break;
				} else if (sum + it->second <= w) {
					sum += it->second;
					cur.erase(it);
				} else {
					it->second -= (w - sum);
					break;
				}
			}
			cur[d] += w;
		}
	}
	ll ans = 0;
	for (auto &i : dp[id[1]]) {
		ans += i.second;
	}
	cout << ans << endl;
}