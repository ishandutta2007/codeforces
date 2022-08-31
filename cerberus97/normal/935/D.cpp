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

const int N = 1e5 + 10, mod = 1e9 + 7;

ll a[N], b[N], ctr[N], all[N], dp[N];

ll pwr(ll x, ll e);

int main() {
	ll n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	ctr[n + 1] = 0;
	all[n + 1] = 1;
	for (int i = n; i >= 1; --i) {
		ctr[i] = ctr[i + 1] + (!a[i]) + (!b[i]);
		all[i] = pwr(m, ctr[i]);
	}
	ll Qinv = pwr(pwr(m, ctr[1]), mod - 2);
	dp[n + 1] = 0;
	for (int i = n; i >= 1; --i) {
		if (a[i] and b[i]) {
			if (a[i] < b[i]) {
				dp[i] = 0;
			} else if (a[i] == b[i]) {
				dp[i] = dp[i + 1];
			} else {
				dp[i] = all[i];
			}
		} else if (a[i]) {
			dp[i] = (a[i] - 1) * all[i + 1] + dp[i + 1];
			dp[i] %= mod;
		} else if (b[i]) {
			dp[i] = (m - b[i]) * all[i + 1] + dp[i + 1];
			dp[i] %= mod;
		} else {
			ll temp = ((m * (m - 1)) / 2) % mod;
			dp[i] = temp * all[i + 1] + m * dp[i + 1];
			dp[i] %= mod;
		}
	}
	cout << (dp[1] * Qinv) % mod;
}

ll pwr(ll x, ll e) {
	ll res = 1;
	while (e) {
		if (e & 1) {
			res = (res * x) % mod;
		}
		x = (x * x) % mod;
		e >>= 1;
	}
	return res;
}