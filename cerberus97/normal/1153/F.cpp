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

const int N = 2e3 + 10, mod = 998244353;

ll choose[N][N], pre_inverse[2 * N];

ll pwr(ll x, ll e);

int main() {
	fast_cin();
	int n, k; ll l;
	cin >> n >> k >> l;
	for (int i = 0; i < N; ++i) {
		choose[i][0] = choose[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			choose[i][j] = (choose[i - 1][j - 1] + choose[i - 1][j]) % mod;
		}
	}
	for (int i = 1; i < 2 * N; ++i) {
		pre_inverse[i] = pwr(i, mod - 2);
	}
	ll ans = 0, p2 = 1;
	for (int j = 1; j <= n; ++j) {
		p2 *= 2;
		p2 %= mod;
		ll sum = 0;
		for (int i = k; i <= j; ++i) {
			ll temp = choose[n][i] * choose[n - i][j - i];
			temp %= mod;
			if ((j - i) % 2) {
				temp = (mod - temp);
			}
			sum += temp;
			sum %= mod;
		}
		for (int t = 0; t <= j; ++t) {
			ll temp = choose[j][t];
			temp *= p2;
			temp %= mod;
			temp *= l;
			temp %= mod;
			temp *= pre_inverse[2 * j - t + 1];
			temp %= mod;
			temp *= sum;
			temp %= mod;
			if ((j - t) % 2) {
				temp = (mod - temp);
			}
			ans += temp;
			ans %= mod;
		}
	}
	cout << ans << endl;
}

ll pwr(ll x, ll e) {
	ll res = 1;
	while (e) {
		if (e & 1) {
			res = (res * x) % mod;
		}
		e /= 2;
		x = (x * x) % mod;
	}
	return res;
}