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

const int N = 1e5 + 10, LOG = 62;

ll a[N], dist[N];
vector<ll> g[N], have[LOG], valid;
vector<pll> edges;
set<pll> s_edges;

int bfs(int s, int t);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		for (int j = 0; j < LOG; ++j) {
			if ((a[i] >> j) & 1) {
				have[j].pb(i);
			}
		}
	}
	for (int j = 0; j < LOG; ++j) {
		if (have[j].size() >= 3) {
			cout << 3 << endl;
			return 0;
		} else if (have[j].size() == 2) {
			int u = have[j][0], v = have[j][1];
			s_edges.insert({u, v});
		}
	}
	for (auto &e : s_edges) {
		edges.pb(e);
	}
	for (int i = 1; i <= n; ++i) {
		if (a[i]) {
			valid.pb(i);
		}
	}
	int ans = n + 1;
	int m = edges.size();
	for (int i = 0; i < m; ++i) {
		for (auto &u : valid) {
			g[u].clear();
		}
		for (int j = 0; j < m; ++j) {
			if (i != j) {
				int u = edges[j].first, v = edges[j].second;
				g[u].pb(v);
				g[v].pb(u);
			}
		}
		int s = edges[i].first, t = edges[i].second;
		ans = min(ans, bfs(s, t) + 1);
	}
	if (ans > n) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
}

int bfs(int s, int t) {
	for (auto &u : valid) {
		dist[u] = N;
	}
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		auto u = q.front();
		q.pop();
		if (u == t) {
			return dist[u];
		}
		for (auto &v : g[u]) {
			if (dist[u] + 1 < dist[v]) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
	return N;
}