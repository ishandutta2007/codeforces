/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012345, M = 1000 * 1000 * 1000 + 7;
ll fac[N];

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

int inv(int x) {
	return tav(x, M - 2);
}

int C(int k, int n) {
	return (fac[n] * (inv((fac[n - k] * fac[k]) % M)) % M) % M;
}

void solve() {
	int x, y;
	cin >> x >> y;
	ll ans = 1;
	for (int i = 2; i * i <= x; i++) {
		int c = 0;
		while (x % i == 0)
			x /= i, c++;
		if (c == 0)
			continue;
		ans *= C(y - 1, c + y - 1);
		ans %= M;
	}
	if (x != 1) {
		ans *= y;
		ans %= M;
	}
	ans *= tav(2, y - 1);
	ans %= M;
	cout << ans << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	fac[0] = 1;
	for (int i = 1; i < N; i++) {
		fac[i] = fac[i - 1] * i;
		fac[i] %= M;
	}
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}