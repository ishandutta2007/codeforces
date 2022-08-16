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
 
const int N = 3000 + 10; 
const pll neg_inf = {-1e18 + 42, -1e18 + 42};

ll val[N];
int sz[N];
vector<int> g[N];

vector<pll> solve(int u, int p);
inline pll merge(pll& a, pll& b);

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			int b; cin >> b;
			val[i] = -b;
		}
		for (int i = 1; i <= n; ++i) {
			int w; cin >> w;
			val[i] += w;
			g[i].clear();
		}
		for (int i = 1; i < n; ++i) {
			int u, v;
			cin >> u >> v;
			g[u].pb(v);
			g[v].pb(u);
		}
		auto dp = solve(1, 0);
		cout << dp[m].first + (dp[m].second > 0) << '\n';
	}	
}

vector<pll> solve(int u, int p) {
	for (int i = 0; i < int(g[u].size()); ++i) {
		if (g[u][i] == p) {
			g[u].erase(g[u].begin() + i);
			break;
		}
	}
	sz[u] = 1;
	vector<pll> dp(2, neg_inf);
	dp[1] = {0, val[u]};
	for (auto& v : g[u]) {
		auto nxt = solve(v, u);
		vector<pll> tmp(sz[u] + sz[v] + 1, neg_inf);
		for (int i = 1; i <= sz[u]; ++i) {
			for (int j = 0; j <= sz[v]; ++j) {
				tmp[i + j - 1] = max(tmp[i + j - 1], {dp[i].first + nxt[j].first, dp[i].second + nxt[j].second});
				tmp[i + j] = max(tmp[i + j], {dp[i].first + nxt[j].first + (nxt[j].second > 0), dp[i].second});
			}
		}
		sz[u] += sz[v];
		dp = tmp;
	}
	return dp;
}

inline pll merge(pll& a, pll& b) {
	return make_pair(a.first + b.first, a.second + b.second);
}