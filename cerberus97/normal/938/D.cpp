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

const int N = 2e5 + 10;
const ll inf = 1e18;

ll dist[N];
bool seen[N];
vector <pll> g[N];

void dijkstra(int s, int n);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v; ll w;
		cin >> u >> v >> w;
		w <<= 1;
		g[u].pb({w, v});
		g[v].pb({w, u});
	}
	for (int i = 1; i <= n; ++i) {
		ll w;
		cin >> w;
		g[0].pb({w, i});
	}
	dijkstra(0, n);
	for (int i = 1; i <= n; ++i) {
		cout << dist[i] << ' ';
	}
}

void dijkstra(int s, int n) {
	for (int i = 0; i <= n; ++i) {
		dist[i] = inf;
	}
	dist[s] = 0;
	priority_queue<pll, vector<pll>, greater<pll>> q;
	q.push({0, s});
	while (!q.empty()) {
		ll d; int v;
		tie(d, v) = q.top();
		q.pop();
		if (seen[v]) {
			continue;
		}
		seen[v] = true;
		for (auto &e : g[v]) {
			if (d + e.first < dist[e.second]) {
				dist[e.second] = d + e.first;
				q.push({dist[e.second], e.second});
			}
		}
	}
}