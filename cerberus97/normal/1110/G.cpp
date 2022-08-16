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

const int N = 4 * 5e5 + 10, inf = 1e9 + 42;

vector<int> g[N];
int deg[N];
char color[N];
bool seen[N];


bool solve();
int dist(int u, int v);
void add_edge(int u, int v);

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		if (solve()) {
			cout << "White\n";
		} else {
			cout << "Draw\n";
		}
	}
}

bool solve() {
	int n; cin >> n;
	for (int i = 1; i <= 4 * n; ++i) {
		g[i].clear();
		deg[i] = 0;
		seen[i] = false;
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		add_edge(u, v);
	}
	cin >> (color + 1);
	int cur = n;
	for (int i = 1; i <= n; ++i) {
		if (color[i] == 'W') {
			add_edge(i, cur + 1);
			add_edge(cur + 1, cur + 2);
			add_edge(cur + 1, cur + 3);
			cur += 3;
		}
	}
	n = cur;
	vector<int> d3_vertices;
	for (int i = 1; i <= n; ++i) {
		if (deg[i] > 3) {
			return true;
		} else if (deg[i] == 3) {
			d3_vertices.pb(i);
			int ctr = 0;
			for (auto &v : g[i]) {
				if (deg[v] > 1) {
					++ctr;
				}
			}
			if (ctr >= 2) {
				return true;
			}
		}
	}
	if (d3_vertices.size() < 2) {
		return false;
	}
	return (dist(d3_vertices[0], d3_vertices[1]) % 2 == 0);
}

void add_edge(int u, int v) {
	g[u].pb(v); g[v].pb(u);
	++deg[u]; ++deg[v];
}

int dist(int u, int v) {
	seen[u] = true;
	if (u == v) {
		return 0;
	}
	int ans = inf;
	for (auto &w : g[u]) {
		if (seen[w]) {
			continue;
		}
		ans = min(ans, 1 + dist(w, v));
	}
	return ans;
}