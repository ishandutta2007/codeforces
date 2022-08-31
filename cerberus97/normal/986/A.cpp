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

const int N = 1e5 + 10,S = 120, inf = 1e7;

queue<int> start[S];
int dist[S][N], a[N];
vector<int> g[N];

void bfs(queue<int> &q, int *d, int n);

int main() {
	int n, m, k, s;
	cin >> n >> m >> k >> s;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		start[a[i]].push(i);
	}
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	for (int i = 1; i <= k; ++i) {
		bfs(start[i], dist[i], n);
	}
	for (int i = 1; i <= n; ++i) {
		vector<int> temp;
		for (int j = 1; j <= k; ++j) {
			temp.pb(dist[j][i]);
		}
		sort(temp.begin(), temp.end());
		int ans = 0;
		for (int j = 0; j < s; ++j) {
			ans += temp[j];
		}
		cout << ans << ' ';
	}
}

void bfs(queue<int> &sq, int *d, int n) {
	for (int i = 1; i <= n; ++i) {
		d[i] = inf;
	}
	queue<int> q;
	while (!sq.empty()) {
		d[sq.front()] = 0;
		q.push(sq.front());
		sq.pop();
	}
	while (!q.empty()) {
		auto u = q.front();
		q.pop();
		for (auto &v : g[u]) {
			if (d[v] > d[u] + 1) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
}