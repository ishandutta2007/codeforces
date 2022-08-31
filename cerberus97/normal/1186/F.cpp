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

const int N = 1e6 + 10, M = 2e6 + 10;

vector<pii> g[N];
bool seen[M];
int deg[N];

void dfs(int u, vector<pii> &edges);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb({v, i});
		g[v].pb({u, i});
		++deg[u]; ++deg[v];
	}
	for (int i = 1; i <= n; ++i) {
		if (deg[i] & 1) {
			g[0].pb({i, m});
			g[i].pb({0, m});
			++m;
		}
	}
	vector<pii> ans;
	for (int i = 0; i <= n; ++i) {
		vector<pii> edges;
		dfs(i, edges);
		int k = edges.size();
		vector<int> del(k, 0);
		for (int j = 1; j < k; j += 2) {
			if (edges[j - 1].first == 0) {
				del[j - 1] = true;
			} else if (edges[(j + 1) % k].second == 0) {
				del[(j + 1) % k] = true;
			} else {
				del[j] = true;
			}
		}
		for (int j = 0; j < k; ++j) {
			if (!del[j] and edges[j].first and edges[j].second) {
				ans.pb(edges[j]);
			}
		}
	}
	cout << ans.size() << '\n';
	for (auto &e : ans) {
		cout << e.first << ' ' << e.second << '\n';
	}
}

void dfs(int u, vector<pii> &edges) {
	while (true) {
		while (!g[u].empty() and seen[g[u].back().second]) {
			g[u].pop_back();
		}
		if (!g[u].empty()) {
			auto e = g[u].back();
			int v = e.first, id = e.second;
			seen[id] = true;
			edges.pb({u, v});
			u = v;
		} else {
			break;
		}
	}
}