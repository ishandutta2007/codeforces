/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int M = 998244353;
const int N = 201234;
int fac[N];

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

int C(int k, int n) {
	return (fac[n] * (inv((fac[n - k] * fac[k]) % M)) % M) % M;
}

int32_t main() {
	fac[0] = 1;
	for (int i = 1; i < N; i++)
		fac[i] = (fac[i - 1] * i) % M;
	int n;
	cin >> n;
	int ans = 0;
	for (int x = 1; x <= n; x++) {
		if ((n - x) % 2)
			continue;
		ans += C(x - 1, ((n - x) / 2) + x - 1);
		ans %= M;
	}
	int x = ans, y = tav(2, n);
	cout << (x * tav(y, M - 2)) % M;
}