/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234, M = 1000 * 1000 * 1000 + 7;
int dp[N], ps[N];

int32_t main() {
	int t, k;
	cin >> t >> k;
	dp[0] = 1;
	ps[0] = 1;
	for (int i = 1; i < N; i++) {
		dp[i] = dp[i - 1];
		if (i >= k) {
			dp[i] += dp[i - k];
		}
		dp[i] %= M;
		ps[i] = ps[i - 1] + dp[i];
		ps[i] %= M;
	}
	while (t--) {
		int l, r;
		cin >> l >> r;
		int x = ps[r] - ps[l - 1];
		if (x < 0)
			x += M;
		cout << x << '\n';
	}
}