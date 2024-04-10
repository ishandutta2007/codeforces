/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 301234;
int a[N], dp[N];

void solve() {
	int n, mx = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = max(0, i - 515); j < i; j++) {
			if ((a[j] ^ i) < (a[i] ^ j))
				dp[i] = max(dp[i], dp[j] + 1);
		}
		mx = max(mx, dp[i]);
	}
	cout << mx << '\n';
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