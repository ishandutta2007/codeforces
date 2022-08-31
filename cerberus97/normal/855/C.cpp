/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, X = 12, mod = 1e9 + 7;

int x, par[N];
ll sp, m, dp[N][X][3];
bool seen[N][3] = {0};
vector <int> g[N];

void dfs(int i, int p);
void solve(int i, int p);

int main() {
	int n;
	cin >> n >> m;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	cin >> sp >> x;
	ll ans = 0;
	dfs(1, 0);
	solve(1, 1);
	for (int i = 0; i <= x; ++i) {
		ans += dp[1][i][1];
	}
	cout << ans % mod;
}

void dfs(int i, int p)
{
	par[i] = p;
	for (auto &j : g[i]) {
		if (j != p) {
			dfs(j, i);
		}
	}
}

void solve(int i, int p)
{
	if (seen[i][p]) {
		return;
	}
	seen[i][p] = true;
	for (int j = 0; j <= 2; ++j) {
		if (p == 0 and j != 1) {
			continue;
		}
		if (p == 2 and j == 0) {
			continue;
		}
		ll ways = 1;
		if (j == 1) {
			ways = sp - 1;
		}
		else if (j == 2) {
			ways = m - sp;
		}
		ll cur[X] = {0}, temp[X] = {0};
		cur[!j] = ways;
		for (auto &c : g[i]) {
			if (c == par[i]) {
				continue;
			}
			solve(c, j);
			for (int k = 0; k <= x; ++k) {
				for (int l = 0; l + k <= x; ++l) {
					temp[l + k] += cur[k] * dp[c][l][j];
					temp[l + k] %= mod;
				}
			}
			for (int k = 0; k <= x; ++k) {
				cur[k] = temp[k];
				temp[k] = 0;
			}
		}
		for (int k = 0; k <= x; ++k) {
			dp[i][k][p] += cur[k];
			dp[i][k][p] %= mod;
		}
	}
}