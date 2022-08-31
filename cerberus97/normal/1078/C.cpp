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

const int N = 3e5 + 10, mod = 998244353;

vector<int> g[N];
bool seen[N][3];
ll dp[N][3];

ll solve(int u, int t, int par);
ll pwr(ll x, ll e);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	cout << solve(1, 0, 0) << endl;
}

ll solve(int u, int t, int par) {
	if (seen[u][t]) {
		return dp[u][t];
	}
	seen[u][t] = true;
	ll ans = 0;
	if (t == 0) {
		ans = solve(u, 1, par);
		ll temp = 1;
		for (auto &v : g[u]) {
			if (v == par) {
				continue;
			}
			temp *= solve(v, 0, u);
			temp %= mod;
		}
		ans += temp;
		ans %= mod;
	} else if (t == 1) {
		ll temp = 1;
		for (auto &v : g[u]) {
			if (v == par) {
				continue;
			}
			temp *= (solve(v, 0, u) + solve(v, 1, u));
			temp %= mod;
		}
		for (auto &v : g[u]) {
			if (v == par) {
				continue;
			}
			ll temp2 = (temp * pwr(solve(v, 0, u) + solve(v, 1, u), mod - 2)) % mod;
			ans += (solve(v, 2, u) * temp2);
			ans %= mod;
		}
	} else {
		ll temp = 1;
		for (auto &v : g[u]) {
			if (v == par) {
				continue;
			}
			temp *= (solve(v, 0, u) + solve(v, 1, u));
			temp %= mod;
		}
		ans = temp;
	}
	dp[u][t] = ans;
	return ans;
}

ll pwr(ll x, ll e) {
	ll res = 1;
	x %= mod;
	while (e) {
		if (e & 1) {
			res = (res * x) % mod;
		}
		e >>= 1;
		x = (x * x) % mod;
	}
	return res;
}