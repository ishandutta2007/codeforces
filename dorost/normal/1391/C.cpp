#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int M = 1000 * 1000 * 1000 + 7, N = 1000005;
ll fac[N];

int tav(int x, int y) {
	if (x == 0)
		return 0;
	if (y == 0)
		return 1;
	ll a = tav(x, y / 2) % M;
	a = a * a;
	a %= M;
	if (y % 2) {
		a *= x;
		a %= M;
	}
	return a;
}

int invf(int x) {
	return tav(x, M - 2);
}

int ent(int k, int n) {
	return ((fac[n]) * invf((fac[n - k] * fac[k]) % M)) % M;
}

int32_t main(){
	int n;
	cin >> n;
	fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i;
		fac[i] %= M;
	}
	//  cout << fac[n - 1] << ' ' << inv[0] << ' ' << inv[n - 1] << endl;
	ll ans = fac[n];
	for (int i = 0; i < n; i++) {
		ans -= ent(i, n - 1);
		ans %= M;
		//  cout << ent(i, n - 1) << endl;
	}
	if (ans < 0)
		ans += M;
	cout << ans;
}