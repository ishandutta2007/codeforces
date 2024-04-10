/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int M = 1000 * 1000 * 1000 + 7;

int tav(int x, int n) {
	if (n == 0)
		return 1;
	ll ans = tav(x, n / 2);
	ans = ans * ans;
	ans %= M;
	if (n % 2) {
		ans *= x;
		ans %= M;
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	ll x, k;
	cin >> x >> k;
	if (x == 0) {
		cout << 0 << '\n';
		return 0;
	}
	ll ans = x;
	ans %= M;
	ans *= tav(2, k + 1);
	ans %= M;
	ans -= tav(2, k);
	ans %= M;
	ans += M;
	ans %= M;
	ans += 1;
	ans %= M;
	cout << ans;
}