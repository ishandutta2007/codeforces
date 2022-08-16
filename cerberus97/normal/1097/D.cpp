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

const int L = 60, K = 1e4 + 10, mod = 1e9 + 7;

ll dp[L][K];

ll solve(ll &n, ll p, int k);
ll pwr(ll x, ll e);

int main() {
	fast_cin();
	ll n; int k;
	cin >> n >> k;
	ll res = 1, sq = sqrt(n);
	for (int i = 2; i <= sq; ++i) {
		if (n % i == 0) {
			res *= solve(n, i, k);
			res %= mod;
		}
	}
	if (n > 1) {
		res *= solve(n, n, k);
		res %= mod;
	}
	cout << res << endl;
}

ll solve(ll &n, ll p, int k) {
	int q = 0;
	while (n % p == 0) {
		n /= p;
		++q;
	}
	for (int j = 0; j <= k; ++j) {
		dp[0][j] = 1;
	}
	for (int i = 1; i <= q; ++i) {
		dp[i][0] = pwr(p, i);
		for (int j = 1; j <= k; ++j) {
			dp[i][j] = (i * dp[i - 1][j]) + dp[i][j - 1];
			dp[i][j] %= mod;
			dp[i][j] *= pwr(i + 1, mod - 2);
			dp[i][j] %= mod;
		}
	}
	return dp[q][k];
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