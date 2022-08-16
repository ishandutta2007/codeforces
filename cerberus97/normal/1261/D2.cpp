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

const int N = 2e5 + 10, mod = 998244353;

ll h[N], fact[N], finv[N];

ll choose(int n, int k);
ll pwr(ll x, ll e);
void mul(ll &x, ll y);

int main() {
	fast_cin();
	fact[0] = finv[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = (i * fact[i - 1]) % mod;
		finv[i] = pwr(fact[i], mod - 2);
	}
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}
	int A = 0;
	for (int i = 0; i < n; ++i) {
		if (h[i] != h[(i + 1) % n]) {
			++A;
		}
	}
	ll ans = 0;
	for (int cnt = 1; cnt <= A; ++cnt) {
		ll temp = choose(A, cnt);
		mul(temp, pwr(k - 2, A - cnt));
		if (cnt % 2 == 1) {
			mul(temp, pwr(2, cnt - 1));
		} else {
			ll temp2 = (pwr(2, cnt) - choose(cnt, cnt / 2) + mod);
			mul(temp2, pwr(2, mod - 2));
			mul(temp, temp2);
		}
		ans = (ans + temp) % mod;
	}
	mul(ans, pwr(k, n - A));
	cout << ans << endl;
}

ll choose(int n, int k) {
	if (k < 0 or k > n) {
		return 0;
	}
	ll ans = fact[n];
	mul(ans, finv[k]);
	mul(ans, finv[n - k]);
	return ans;
}

ll pwr(ll x, ll e) {
	ll res = 1;
	while (e) {
		if (e & 1) {
			mul(res, x);
		}
		mul(x, x);
		e /= 2;
	}
	return res;
}

void mul(ll &x, ll y) {
	x *= y;
	x %= mod;
}