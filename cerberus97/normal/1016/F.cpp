/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 3e5 + 10;

bool yay = false;
vector<pll> g[N];
vector<int> path;
ll furthest[N], dist[N], f[N], d[N], vc[N], ec[N], best[N];

bool dfs1(int u, int n, int p, ll d);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i < n; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].pb({v, w});
		g[v].pb({u, w});
	}
	dfs1(1, n, 0, 0);
	path.pb(1);
	reverse(path.begin(), path.end());
	ll cur = dist[n];
	int k = path.size();
	for (int i = 0; i < k; ++i) {
		f[i] = furthest[path[i]];
		d[i] = dist[path[i]];
	}
	ll temp = 0;
	best[k - 1] = f[k - 1] - d[k - 1];
	for (int i = k - 2; i >= 0; --i) {
		if (f[i] == 0 and f[i + 1] == 0) {
			if (i != k - 2) {
				temp = max(temp, d[i] + f[i] + d[k - 1] + best[i + 2]);
			}
		} else {
			temp = max(temp, d[i] + f[i] + d[k - 1] + best[i + 1]);
		}
		best[i] = max(best[i + 1], f[i] - d[i]);
	}
	while (m--) {
		ll x; cin >> x;
		if (yay) {
			cout << cur << '\n';
		} else {
			cout << min(cur, x + temp) << '\n';
		}
	}
}

bool dfs1(int u, int n, int p, ll d) {
	bool found = (u == n);
	furthest[u] = 0;
	for (auto &e : g[u]) {
		if (e.first != p) {
			if (dfs1(e.first, n, u, d + e.second)) {
				path.pb(e.first);
				found = true;
			} else {
				furthest[u] = max(furthest[u], e.second + furthest[e.first]);
				vc[u] += vc[e.first];
				++ec[u];
			}
		}
	}
	if (found) {
		dist[u] = d;
		if (ec[u] > 1 or vc[u] >= 2) {
			// cout << u << ' ' << vc[u] << ' ' << g[u].
			yay = true;
		}
	} else {
		++vc[u];
		ec[u] += g[u].size();
	}
	return found;
}