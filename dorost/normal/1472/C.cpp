/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N], dp[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	dp[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if (i + a[i] < n) {
			dp[i] = dp[i + a[i]] + a[i];
		} else {
			dp[i] = a[i];
		}
	}
	cout << *max_element(dp, dp + n) << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}