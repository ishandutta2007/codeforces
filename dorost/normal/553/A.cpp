/* 	* In the name of GOD 
	* Thanks God */
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 1012, M = 1000 * 1000 * 1000 + 7;
int a[N];

int tav(int x, int n) {
	if (n == 0)
		return 1;
	int ans = tav(x, n / 2);
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
 
int fac(int x) {
	int ans = 1;
	for (int i = 1; i <= x; i++) {
		ans *= i;
		ans %= M;
	}
	return ans;
}
 
int C(int k, int n) {
	return (fac(n) * (inv((fac(n - k) * fac(k)) % M)) % M) % M;
}
 
void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int x = 1, y = 0;
	for (int i = 0; i < n; i++) {
		for (int j = y; j < y + a[i] - 1; j++) {
			x *= (j + 1);
			x %= M;
		}
		y += a[i];
	}
	for (int i = 0; i < n; i++) {
		x *= inv(fac(a[i] - 1));
		x %= M;
	}
	cout << x << '\n';
}

int32_t main() {
	solve();
}