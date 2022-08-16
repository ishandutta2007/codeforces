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

const int N = 1e5 + 10, inf = 1e9 + 42;

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n + 1);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		g[v].pb(u);
	}
	int k; cin >> k;
	vector<int> p(k);
	for (auto& u : p) {
		cin >> u;
	}
	vector<int> dist(n + 1, inf);
	vector<vector<int>> back(n + 1);
	dist[p.back()] = 0;
	queue<int> q;
	q.push(p.back());
	while (!q.empty()) {
		auto u = q.front();
		q.pop();
		for (auto& v : g[u]) {
			if (dist[u] + 1 < dist[v]) {
				dist[v] = dist[u] + 1;
				back[v] = {u};
				q.push(v);
			} else if (dist[u] + 1 == dist[v]) {
				back[v].pb(u);
			}
		}
	}
	int mn = 0, mx = k - 1;
	for (int i = 0; i < k - 1; ++i) {
		if (dist[p[i + 1]] != dist[p[i]] - 1) {
			++mn;
		}
		if (back[p[i]].size() == 1 and back[p[i]][0] == p[i + 1]) {
			--mx;
		}
	}
	cout << mn << ' ' << mx << endl;
}