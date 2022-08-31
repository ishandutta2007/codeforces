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

const int N = 1e5 + 10, Q = 3e5 + 10, M = 3e5 + 10;
const ll inf = 1e15 + 42;

struct edge_t {
	int u, v; ll w;
	bool operator<(const edge_t &o) const {
		return w < o.w;
	}
};

vector<pll> g[N];
vector<pii> queries[N];
edge_t e[M];
ll dist[N], ans[Q];
int back[N], par[N];

int get_root(int u);
void merge(int u, int v, ll w);

int main() {
	fast_cin();
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	for (int i = 1; i <= m; ++i) {
		cin >> e[i].u >> e[i].v >> e[i].w;
		g[e[i].u].pb({e[i].v, e[i].w});
		g[e[i].v].pb({e[i].u, e[i].w});
	}
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	for (int i = 1; i <= k; ++i) {
		pq.push({0, i});
		back[i] = i;
		par[i] = i;
	}
	for (int i = k + 1; i <= n; ++i) {
		dist[i] = inf;
	}
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		int u = cur.second;
		if (dist[u] < cur.first) {
			continue;
		}
		for (auto &edge : g[u]) {
			int v = edge.first, w = edge.second;
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				back[v] = back[u];
				pq.push({dist[v], v});
			}
		}
	}
	vector<edge_t> edges;
	for (int i = 1; i <= m; ++i) {
		int u = back[e[i].u], v = back[e[i].v];
		ll w = dist[e[i].u] + dist[e[i].v] + e[i].w;
		if (u != v) {
			edges.pb({u, v, w});
		}
	}
	sort(edges.begin(), edges.end());
	for (int i = 1; i <= q; ++i) {
		int a, b;
		cin >> a >> b;
		queries[a].pb({b, i});
		queries[b].pb({a, i});
		ans[i] = inf;
	}
	for (auto &edge : edges) {
		merge(edge.u, edge.v, edge.w);
	}
	for (int i = 1; i <= q; ++i) {
		cout << ans[i] << '\n';
	}
}

int get_root(int u) {
	if (u != par[u]) {
		par[u] = get_root(par[u]);
	}
	return par[u];
}

void merge(int u, int v, ll w) {
	u = get_root(u);
	v = get_root(v);
	if (u == v) {
		return;
	} else if (queries[u].size() < queries[v].size()) {
		swap(u, v);
	}
	for (auto &q : queries[v]) {
		if (get_root(q.first) == u) {
			ans[q.second] = min(ans[q.second], w);
		} else {
			queries[u].pb(q);
		}
	}
	par[v] = u;
}