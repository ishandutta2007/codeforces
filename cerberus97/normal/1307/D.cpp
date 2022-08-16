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

const int N = 2e5 + 10, inf = 1e9 + 42;

vector<int> g[N];

vector<int> bfs(int s, int n);

int main() {
	fast_cin();
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> special(k);
	for (auto& u : special) {
		cin >> u;
	}
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	auto d1 = bfs(1, n);
	auto d2 = bfs(n, n);
	sort(special.begin(), special.end(), [&] (int u, int v) {
		return d1[u] < d1[v];
	});
	int ans = 0;
	for (int i = 1; i < k; ++i) {
		ans = max(ans, min(d1[n], d1[special[i - 1]] + 1 + d2[special[i]]));
	}
	cout << ans << '\n';
}

vector<int> bfs(int s, int n) {
	vector<int> dist(n + 1, inf);
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		auto u = q.front();
		q.pop();
		for (auto& v : g[u]) {
			if (dist[u] + 1 < dist[v]) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
	return dist;
}