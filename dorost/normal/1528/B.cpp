/* 	* In the name of GOD *  */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 1012345, M = 998244353;
int s[N];

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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 1; i < N; i++) {
		for (int j = i; j < N; j += i) {
			s[j]++;
			s[j] %= M;
		}
	}
	int n, ans = 0;
	cin >> n;
	ans += s[n];
	for (int i = 1; i < n; i++) {
		ans += s[i] * tav(2, n - i - 1);
		ans %= M;
	}
	cout << ans;
}