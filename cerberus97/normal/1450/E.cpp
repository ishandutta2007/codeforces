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

const int N = 200 + 10;

vector<pii> g[N];

int bfs(int u, int n, vector<int>& dist);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		if (w) {
			g[u].pb({v, 1});
			g[v].pb({u, -1});
		} else {
			g[u].pb({v, 0});
			g[v].pb({u, 0});
		}
	}
	int ans = -1;
	vector<int> a_dist;
	for (int u = 1; u <= n; ++u) {
		vector<int> dist;
		int cand = bfs(u, n, dist);
		if (cand > ans) {
			ans = cand;
			a_dist = dist;
		}
	}
	if (ans == -1) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		cout << *max_element(a_dist.begin(), a_dist.end()) << '\n';
		for (int u = 1; u <= n; ++u) {
			cout << a_dist[u] << ' ';
		}
		cout << '\n';
	}
}

int bfs(int s, int n, vector<int>& dist) {
	vector<int> mdist(n + 1, n + 1);
	mdist[s] = 0;
	bool relax = false;
	for (int it = 0; it <= n; ++it) {
		relax = false;
		for (int u = 1; u <= n; ++u) {
			for (auto& [v, w] : g[u]) {
				int d = (w == 0 ? 1 : w);
				if (mdist[u] + d < mdist[v]) {
					relax = true;
					mdist[v] = mdist[u] + d;
				}
			}
		}
	}
	if (relax) {
		return -1;
	}
	dist.resize(n + 1, n + 1);
	dist[0] = dist[s] = 0;
	queue<int> q;
	q.push(s);
	int layer = -1;
	while (!q.empty()) {
		auto u = q.front();
		q.pop();
		if (dist[u] == layer + 1) {
			++layer;
			for (int v = 1; v <= n; ++v) {
				if (dist[v] <= layer) {
					continue;
				} else if (mdist[v] < layer) {
					return -1;
				} else if (mdist[v] == layer) {
					dist[v] = layer;
					q.push(v);
				}
			}
		}
		for (auto& [v, w] : g[u]) {
			if (dist[v] == n + 1) {
				if (w == -1) {
					return -1;
				}
				dist[v] = dist[u] + 1;
				q.push(v);
			}
			if (dist[v] - dist[u] != 1 and dist[v] - dist[u] != -1) {
				return -1;
			}
			if (w and dist[v] - dist[u] != w) {
				return -1;
			}
		}
	}
	return *max_element(dist.begin(), dist.end());
}