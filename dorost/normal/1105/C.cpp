/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234, M = 1000 * 1000 * 1000 + 7;
int dp[N][3], num[3];

int fnum2(int x, int bag) {
	int a = x / 3, b = x % 3;
	if (bag == 0)
		bag = 3;
	return a + (b >= bag);
}

int fnum(int l, int r, int bag) {
	return fnum2(r, bag) - fnum2(l - 1, bag);
}

void solve() {
	int n, l, r;
	cin >> n >> l >> r;
	for (int i = 0; i < 3; i++) {
		num[i] = fnum(l, r, i);
		dp[0][i] = num[i];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				dp[i][j] += (num[(j - k + 3) % 3] * dp[i - 1][k]);
				dp[i][j] %= M;
			}
		}
	}
	cout << dp[n - 1][0];
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}