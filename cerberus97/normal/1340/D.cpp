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
int deg[N];
vector<pii> path;

void dfs(int u, int p, int t, int mx);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
		++deg[u]; ++deg[v];
	}
	int mx = 0;
	for (int i = 1; i <= n; ++i) {
		mx = max(mx, deg[i]);
	}
	path.pb({1, 0});
	dfs(1, 0, 0, mx);
	cout << path.size() << '\n';
	for (auto& i : path) {
		cout << i.first << ' ' << i.second << '\n';
	}
}

void dfs(int u, int p, int t, int mx) {
	int cur = t, left = (u == 0 ? deg[u] : deg[u] - 1);
	for (auto& v : g[u]) {
		if (v == p) {
			continue;
		}
		if (cur + 1 > mx) {
			assert(left <= (t - 1));
			cur = (t - 1) - left;
			path.pb({u, cur});
		}
		path.pb({v, cur + 1});
		dfs(v, u, cur + 1, mx);
		path.pb({u, cur + 1});
		++cur;
		--left;
	}
	if (t and cur != (t - 1)) {
		path.pb({u, t - 1});
	}
}