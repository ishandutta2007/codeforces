/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 401234, M = 1000 * 1000 * 1000 + 7;
int a[N], b[N], w[N];
bool vis[N];

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
		vis[i] = false;
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		w[a[i] - 1] = b[i] - 1;
	}
	int ans = n;
	for (int i = 0; i < n; i++) {
		if (vis[i]) {
			continue;
		}
		int x = i, nu = 1;
		while (w[i] != x) {
			i = w[i];
			vis[i] = true;
			nu++;
		}
		ans -= (nu) - 1;
		i = x;
	}
	cout << tav(2, ans) << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}