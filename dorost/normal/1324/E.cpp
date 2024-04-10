/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 2012;
int a[N], dp[N][N], n, h, l, r;

int ok(int x) {
	if (x >= h) {
		x -= h;
	}
	return (x >= l && x <= r);
}

int ch(int x) {
	if (x >= h) 
		x -= h;
	return x;
}

int ans(int k, int x) {
	if (dp[k][x] != -1)
		return dp[k][x];
	if (k == n)
		return 0;
	return dp[k][x] = max(ok(ch(x + a[k])) + ans(k + 1, ch(x + a[k])), ok(ch(x + a[k] - 1)) + ans(k + 1, ch(x + a[k] - 1)));
}

int32_t main() {
	cin >> n >> h >> l >> r;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = -1;
		}
	}
	cout << ans(0, 0);
}