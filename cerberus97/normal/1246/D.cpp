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

const int N = 1e5 + 10;

vector<int> g[N], ops;
int depth[N];

void dfs(int u);
void solve(int u);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i < n; ++i) {
		int p; cin >> p;
		g[p].pb(i);
	}
	dfs(0);
	solve(0);
	cout << '\n';
	reverse(ops.begin(), ops.end());
	cout << ops.size() << '\n';
	for (auto &v : ops) {
		cout << v << ' ';
	}
}

void dfs(int u) {
	depth[u] = 1;
	for (auto &v : g[u]) {
		dfs(v);
		depth[u] = max(depth[u], depth[v] + 1);
	}
}

void solve(int u) {
	cout << u << ' ';
	sort(g[u].begin(), g[u].end(), [](int v1, int v2) {
		return depth[v1] > depth[v2];
	});
	int sz = g[u].size();
	for (int i = 0; i < sz - 1; ++i) {
		int v1 = g[u][i], v2 = g[u][i + 1];
		ops.pb(v1);
		g[v2].pb(v1);
		depth[v2] = max(depth[v2], depth[v1] + 1);
	}
	if (!g[u].empty()) {
		solve(g[u].back());
	}
}