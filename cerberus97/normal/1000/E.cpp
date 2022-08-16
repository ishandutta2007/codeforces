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

const int N = 3e5 + 10, inf = 1e6;

vector<int> g[N];
int dsu[N], sz[N], parent[N], dist[N], depth[N];
bool seen[N];

void dfs(int u, int p);
int bfs(int s, int n);
int dsu_find(int i);
void dsu_join(int i, int j);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	for (int i = 1; i <= n; ++i) {
		dsu[i] = i;
		sz[i] = 1;
	}
	dfs(1, 0);
	for (int i = 1; i <= n; ++i) {
		int p = dsu_find(i);
		if (p == i) {
			continue;
		}
		for (auto &j : g[i]) {
			g[p].pb(j);
		}
	}
	// for (int i = 1; i <= n; ++i) {
	// 	cout << dsu_find(i) << ' ';
	// }
	// cout << endl;
	int s = dsu_find(1);
	s = bfs(s, n);
	int t = bfs(s, n);
	cout << dist[t];
}

void dfs(int u, int p) {
	seen[u] = true;
	parent[u] = p;
	depth[u] = depth[p] + 1;
	for (auto &v : g[u]) {
		if (v == p) {
			continue;
		} else if (seen[v]) {
			int cur = u;
			while (depth[cur] > depth[v]) {
				dsu_join(cur, parent[cur]);
				int temp = parent[cur];
				parent[cur] = parent[v];
				cur = temp;
			}
		} else {
			dfs(v, u);
		}
	}
}

int bfs(int s, int n) {
	for (int i = 1; i <= n; ++i) {
		dist[i] = inf;
	}
	int ans = 0;
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		ans = u;
		for (auto &v : g[u]) {
			v = dsu_find(v);
			if (dist[v] > dist[u] + 1) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
	return ans;
}

int dsu_find(int i) {
	if (dsu[i] != i) {
		dsu[i] = dsu_find(dsu[i]);
	}
	return dsu[i];
}

void dsu_join(int i, int j) {
	i = dsu_find(i);
	j = dsu_find(j);
	if (sz[i] >= sz[j]) {
		dsu[j] = i;
		sz[i] += sz[j];
	} else {
		dsu[i] = j;
		sz[j] += sz[i];
	}
}