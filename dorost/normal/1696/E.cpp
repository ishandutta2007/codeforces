/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int M = 1000 * 1000 * 1000 + 7, N = 401234;
int a[N], fac[N];

int tav(int x, int n) {
	ll ans = 1;
	while (n) {
		if (n & 1) 
			ans = (ans * x) % M;
		n >>= 1;
		x = (x * x) % M;
	}
	return ans;
}
 
int inv(int x) {
	return tav(x, M - 2);
}

int C(int n, int k) {
	if (k > n)
		return 0;
	ll ans = fac[n];
	ans *= inv(fac[k]);
	ans %= M;
	ans *= inv(fac[n - k]);
	ans %= M;
	return ans;
}

void solve() {
	fac[0] = 1;
	for (int i = 1; i < N; i++) {
		fac[i] = (fac[i - 1] * i) % M;
	}
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		cin >> a[i];
		ans += C(a[i] + i, i + 1);
		ans %= M;
	}
	cout << ans;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}