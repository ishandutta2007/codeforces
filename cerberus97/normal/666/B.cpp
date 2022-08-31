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

const int N = 3e3 + 10, inf = 1e9 + 42;

vector<int> g[N];
vector<pii> f_cities[N], r_cities[N];
int dist[N][N];

void bfs(int s, int n, int *d);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
	}
	for (int i = 1; i <= n; ++i) {
		bfs(i, n, dist[i]);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (dist[i][j] == inf) {
				continue;
			}
			f_cities[i].push_back({dist[i][j], j});
			r_cities[j].push_back({dist[i][j], i});
		}
	}
	for (int i = 1; i <= n; ++i) {
		sort(f_cities[i].begin(), f_cities[i].end(), greater<pii>());
		sort(r_cities[i].begin(), r_cities[i].end(), greater<pii>());
	}
	int best = 0;
	vector<int> ans = {};
	for (int u = 1; u <= n; ++u) {
		for (int v = 1; v <= n; ++v) {
			if (u == v or dist[u][v] == inf) {
				continue;
			}
			for (int i = 0; i < min(int(r_cities[u].size()), 3); ++i) {
				int x = r_cities[u][i].second;
				if (x == u or x == v) {
					continue;
				}
				for (int j = 0; j < min(int(f_cities[v].size()), 3); ++j) {
					int y = f_cities[v][j].second;
					if (y == u or y == v or y == x) {
						continue;
					}
					int cand = dist[x][u] + dist[u][v] + dist[v][y];
					if (cand > best) {
						best = cand;
						ans = {x, u, v, y};
					}
				}
			}
		}
	}
	// cout << best << endl;
	for (auto &u : ans) {
		cout << u << ' ';
	}
	cout << endl;
}

void bfs(int s, int n, int *d) {
	for (int i = 1; i <= n; ++i) {
		d[i] = inf;
	}
	d[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto &v : g[u]) {
			if (d[u] + 1 < d[v]) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
}