/* 	* In the name of GOD 
	* Thanks God */
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234, M = 1000 * 1000 * 1000 + 7;
int dp[N];

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
 
int ans(int x) {
	if (dp[x] != -1) 
		return dp[x];
	if (x == 0)
		return 1;
	if (x == 1)
		return 1;
	if (x == 2)
		return 2;
	return dp[x] = (ans(x - 1) + ans(x - 2)) % M;
}

int32_t main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < N; i++)
		dp[i] = -1;
	int a = 2 * ans(m);
	a %= M;
	a += 2 * ans(n) - 2;
	a %= M;
	cout << a;
}