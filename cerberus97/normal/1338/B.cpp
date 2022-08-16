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

const int N = 1e5 + 10;

vector<int> g[N];
int deg[N], depth[N], extra_leaves = 0;
set<int> par;

void dfs(int u, int p);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
		++deg[u]; ++deg[v];
	}
	int r = 1;
	while (deg[r] == 1) {
		++r;
	}
	dfs(r, 0);
	if (par.size() == 1) {
		cout << 1 << ' ';
	} else {
		cout << 3 << ' ';
	}
	cout << (n - 1) - extra_leaves << '\n';
}

void dfs(int u, int p) {
	depth[u] = depth[p] + 1;
	if (deg[u] == 1) {
		par.insert(depth[u] % 2);
	} else {
		int leaves = 0;
		for (auto& v : g[u]) {
			if (v != p) {
				dfs(v, u);
				if (deg[v] == 1) {
					++leaves;
				}
			}
		}
		extra_leaves += max(0, leaves - 1);
	}
}