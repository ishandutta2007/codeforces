/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int M = 1000 * 1000 * 1000 + 7, N = 1012;
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
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	reverse(a, a + n);
	int x = a[k - 1];
	int s1 = 0, s2 = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == x)
			s1++;
	}
	for (int i = 0; i < k; i++)
		if (a[i] == x)
			s2++;
	cout << C(s2, s1) << '\n';
	
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}