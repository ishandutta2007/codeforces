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

const int N = 2e5 + 10;

vector<int> g[N];
int depth[N], sz[N];

void dfs(int u, int p);

int main() {
	fast_cin();
	int n, k;
	cin >> n >> k;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1, 0);
	vector<int> ids(n);
	iota(ids.begin(), ids.end(), 1);
	sort(ids.begin(), ids.end(), [&](int u, int v) {
		return (depth[u] - sz[u]) > (depth[v] - sz[v]);
	});
	ll ans = 0;
	for (int i = 0; i < k; ++i) {
		ans += (depth[ids[i]] - sz[ids[i]] + 1);
	}
	cout << ans << endl;
}

void dfs(int u, int p) {
	sz[u] = 1;
	for (auto& v : g[u]) {
		if (v != p) {
			depth[v] = depth[u] + 1;
			dfs(v, u);
			sz[u] += sz[v];
		}
	}
}