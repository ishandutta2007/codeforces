/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

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
	int a = tav(x, n / 2);
	a = a * a;
	a %= M;
	if (n % 2) 
		a *= x;
	a %= M;
	return a;
}

int inv(int x) {
	return tav(x, M - 2);
}

int fac(int x) {
	int a = 1;
	for (int i = 1; i <= x; i++) {
		a *= i;
		a %= M;
	}
	return a;
}

int C(int n, int k) {
	if (n < k)
		return 0;
	int x = (fac(n) * inv((fac(k) * fac(n - k)) % M)) % M;
	return x;
}

void solve() {
	int n, x, pos, f = 0, s = 0;
	cin >> n >> x >> pos;
	int l = 0, r = n, mid;
	while (l < r) {
		mid = (l + r) / 2;
		if (mid == pos) 
		    l = mid + 1;
		if (mid < pos) {
			l = mid + 1;
			f++;
		}
		if (mid > pos) {
			r = mid;
			s++;
		}
	}
	int ans = fac((n - 1) - (f + s));
	ans %= M;
	ans *= C(x - 1, f);
	ans %= M;
	ans *= fac(f);
	ans %= M;
	ans *= C(n - x, s);
	ans %= M;
	ans *= fac(s);
	ans %= M;
	cout << ans;
}

int32_t main() {
	solve();
}