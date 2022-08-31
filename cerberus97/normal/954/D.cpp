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

const int N = 1e3 + 10, inf = 1e9;

int ds[N], dt[N];
bool mat[N][N];
vector<int> g[N];

void bfs(int s, int *dist, int n);

int main() {
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	while (m--) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
		mat[u][v] = mat[v][u] = true;
	}
	bfs(s, ds, n);
	bfs(t, dt, n);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (!mat[i][j]) {
				if (ds[i] + dt[j] + 1 < ds[t]) {
					continue;
				}
				if (ds[j] + dt[i] + 1 < ds[t]) {
					continue;
				}
				++ans;
			}
		}
	}
	cout << ans;
}

void bfs(int s, int *dist, int n) {
	for (int i = 1; i <= n; ++i) {
		dist[i] = inf;
	}

	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto &i : g[cur]) {
			if (dist[i] == inf) {
				dist[i] = dist[cur] + 1;
				q.push(i);
			}
		}
	}
}