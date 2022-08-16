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

const int K = 5e3 + 10, mod = 998244353;

ll dp[K][K];

ll pwr(ll x, ll e);

int main() {
	fast_cin();
	int n, m, k;
	cin >> n >> m >> k;
	dp[1][1] = n;
	for (int i = 1; i < k; ++i) {
		for (int j = 0; j <= i and j <= n; ++j) {
			dp[i + 1][j] += j * dp[i][j];
			dp[i + 1][j] %= mod;
			dp[i + 1][j + 1] += (n - j) * dp[i][j];
			dp[i + 1][j + 1] %= mod;
		}
	}
	ll ans = 0, m_inv = pwr(m, mod - 2);
	for (int t = 1; t <= min(n, k); ++t) {
		ll temp = dp[k][t] * pwr(m_inv, t);
		ans += temp;
		ans %= mod;
	}
	cout << ans << '\n';
}

ll pwr(ll x, ll e) {
	ll res = 1;
	while (e) {
		if (e & 1) {
			res = (res * x) % mod;
		}
		x = (x * x) % mod;
		e /= 2;
	}
	return res;
}