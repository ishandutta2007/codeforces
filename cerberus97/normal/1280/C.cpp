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

void dfs(int u, int p, vector<vector<int>>& g, vector<int>& sz);
 
int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int k; cin >> k;
		int n = 2 * k;
		vector<vector<int>> g(n + 1);
		vector<int> u(n), v(n), w(n);
		for (int i = 0; i < n - 1; ++i) {
			cin >> u[i] >> v[i] >> w[i];
			g[u[i]].pb(v[i]);
			g[v[i]].pb(u[i]);
		}
		vector<int> sz(n + 1, 0);
		dfs(1, 0, g, sz);
		ll mn = 0, mx = 0;
		for (int i = 0; i < n - 1; ++i) {
			ll s = min(sz[u[i]], sz[v[i]]);
			mn += ((s % 2) ? w[i] : 0);
			mx += min(s, n - s) * w[i];
		}
		cout << mn << ' ' << mx << '\n';
	}	
}

void dfs(int u, int p, vector<vector<int>>& g, vector<int>& sz) {
	sz[u] = 1;
	for (auto& v : g[u]) {
		if (v != p) {
			dfs(v, u, g, sz);
			sz[u] += sz[v];
		}
	}
}