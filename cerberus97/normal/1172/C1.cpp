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

const int N = 2e5 + 10, M = 3010, mod = 998244353;

ll a[N], w[N];
ll dp[M][M];

ll inverse(ll x);
ll pwr(ll x, ll e);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	ll bad_wt = 0, good_wt = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> w[i];
		if (a[i]) {
			good_wt += w[i];
		} else {
			bad_wt += w[i];
		}
	}
	for (int j = 0; j <= m and j <= bad_wt; ++j) {
		dp[m][j] = j;
	}
	ll tot_wt = good_wt + bad_wt;
	for (int i = m - 1; i >= 0; --i) {
		for (int j = 0; j <= m and j <= bad_wt; ++j) {
			ll p_bad = (bad_wt - j) * inverse(tot_wt - j + (i - j));
			p_bad %= mod;
			ll p_good = (mod + 1 - p_bad) % mod;
			dp[i][j] = p_bad * dp[i + 1][j + 1] + p_good * dp[i + 1][j];
			dp[i][j] %= mod;
		}
	}
	ll bad_visits = dp[0][0], good_visits = (m - bad_visits + mod) % mod;
	// cout << (bad_visits * (3628800)) % mod << endl;
	for (int i = 1; i <= n; ++i) {
		ll ans = w[i];
		if (a[i]) {
			ans *= good_visits;
			ans %= mod;
			ans *= inverse(good_wt);
			ans %= mod;
			ans += w[i];
			ans %= mod;
		} else {
			ans *= bad_visits;
			ans %= mod;
			ans *= inverse(bad_wt);
			ans %= mod;
			ans = (w[i] - ans + mod) % mod;
		}
		cout << ans << '\n';
	}
}

ll inverse(ll x) {
	return pwr(x, mod - 2);
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