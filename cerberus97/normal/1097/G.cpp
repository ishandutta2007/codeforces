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

const int N = 1e5 + 10, K = 210, mod = 1e9 + 7;

vector<int> g[N];
ll fact[K], s[K][K];
ll ans[K], dp[N][K], temp[K];
int sz[N];

void solve(int u, int p, int k);

int main() {
	fast_cin();
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	fact[0] = 1;
	for (int i = 1; i < K; ++i) {
		fact[i] = (i * fact[i - 1]) % mod;
	}
	s[0][0] = 1;
	for (int i = 1; i < K; ++i) {
		for (int j = 1; j <= i; ++j) {
			s[i][j] = s[i - 1][j - 1] + j * s[i - 1][j];
			s[i][j] %= mod;
		}
	}
	solve(1, 0, k);
	ll res = 0;
	for (int j = 1; j <= k; ++j) {
		ans[j] = dp[1][j];
		for (int i = 2; i <= n; ++i) {
			ll sub = dp[i][j - 1];
			if (j == 1) {
				sub -= (1 - mod);
			}
			sub %= mod;
			ans[j] -= (sub - mod);
		}
		ans[j] %= mod;
		s[k][j] *= fact[j];
		s[k][j] %= mod;
		res += ans[j] * s[k][j];
		res %= mod;
	}
	cout << res << endl;
}

void solve(int u, int p, int k) {
	sz[u] = 1;
	dp[u][0] = 2;
	for (auto &v : g[u]) {
		if (v != p) {
			solve(v, u, k);
			for (int j = 0; j <= min(k, sz[v] + sz[u]); ++j) {
				temp[j] = 0;
			}
			for (int i = 0; i <= min(k, sz[u]); ++i) {
				for (int j = 0; j <= min(k - i, sz[v]); ++j) {
					temp[i + j] += dp[u][i] * dp[v][j];
					temp[i + j] %= mod;
					temp[i + j + 1] += dp[u][i] * dp[v][j];
					temp[i + j + 1] %= mod;
				}
				temp[i + 1] -= (dp[u][i] - mod);
				temp[i + 1] %= mod;
			}
			for (int j = 0; j <= min(k, sz[v] + sz[u]); ++j) {
				dp[u][j] = temp[j];
			}
			sz[u] += sz[v];
		}
	}
}