/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 301234, M = 998244353;
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

int32_t main() {
	int n;
	cin >> n;
	for (int i = 0; i < n * 2; i++) {
		cin >> a[i];
	}
	sort(a, a + n * 2);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (a[n * 2 - 1 - i] - a[i]);
		ans %= M;
	}
	cout << (ans * C(n, n * 2)) % M;
}