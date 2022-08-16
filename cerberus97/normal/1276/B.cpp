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

const int N = 2e5 + 10;

vector<int> g[N];
bool vis1[N], vis2[N];

void dfs(int u, int bad, bool* vis);

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n, m, a, b;
		cin >> n >> m >> a >> b;
		for (int i = 1; i <= n; ++i) {
			g[i].clear();
			vis1[i] = vis2[i] = 0;
		}
		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			g[u].pb(v);
			g[v].pb(u);
		}
		dfs(a, b, vis1);
		dfs(b, a, vis2);
		ll s[2] = {0};
		for (int i = 1; i <= n; ++i) {
			if (i == a or i == b) {
				continue;
			}
			if (vis1[i] xor vis2[i]) {
				++s[vis1[i]];
			}
		}
		cout << s[0] * s[1] << '\n';
	}
}

void dfs(int u, int bad, bool* vis) {
	vis[u] = true;
	for (auto& v : g[u]) {
		if (v != bad and !vis[v]) {
			dfs(v, bad, vis);
		}
	}
}