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

const int N = 1e6 + 10, mod = 998244353;

ll fact[N], finv[N], sum1[N], sum2[N];

ll choose(int n, int k);
ll pwr(ll x, ll e);

ll pwr(ll x, ll e);

int main() {
	fast_cin();
	string s; cin >> s;
	int n = s.length();
	fact[0] = finv[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fact[i] = (i * fact[i - 1]) % mod;
		finv[i] = pwr(fact[i], mod - 2);
	}
	int blanks = count(s.begin(), s.end(), '?');
	sum1[0] = 1;
	sum2[0] = (blanks > 0);
	for (int i = 1; i <= n; ++i) {
		sum1[i] = (sum1[i - 1] + choose(blanks, i)) % mod;
		sum2[i] = (sum2[i - 1] + choose(blanks - 1, i)) % mod;
	}
	ll ans = 0, mx = count(s.begin(), s.end(), ')') + blanks;
	for (int i = 0; i < n; ++i) {
		mx -= 1;
		int idx = -1;
		ll* sum = sum1;
		if (s[i] == '(') {
			idx = mx;
			sum = sum1;
		} else if (s[i] == '?') {
			idx = mx - 1;
			sum = sum2;
		}
		ans += (idx >= 0 ? sum[idx] : 0);
	}
	cout << ans % mod << endl;
}

ll choose(int n, int k) {
	if (k < 0 or k > n) {
		return 0;
	} else {
		ll ans = (fact[n] * finv[k]) % mod;
		return (ans * finv[n - k]) % mod;
	}
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