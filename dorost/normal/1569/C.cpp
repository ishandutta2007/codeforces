/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234, M = 998244353;
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
	sort(a, a + n);
	if (a[n - 1] == a[n - 2]) {
		cout << fac(n) << ' ';
		return;
	}
	if (a[n - 1] >= a[n - 2] + 2) {
		cout << 0 << ' ';
		return;
	}
	int x = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == a[n - 2])
			x++;
	}
	int ans = fac(n);
	int x2 = 1;
	for (int i = 1; i <= n; i++) {
		if (i == (x + 1))
			continue;
		x2 *= i;
		x2 %= M;
	}
	cout << (ans - x2 + M) % M << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}