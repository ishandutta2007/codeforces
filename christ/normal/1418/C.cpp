#include <bits/stdc++.h>
using namespace std;
const int MN = 1e5 + 5;
void solve () {
	int n; scanf ("%d",&n);
	vector<int> a(n+1);
	vector<array<int,2>> dp(n+1);
	dp[0][1] = 0; dp[0][0] = (int)1e9;
	for (int i = 1; i <= n; i++) {
		scanf ("%d",&a[i]);
		dp[i][0] = dp[i-1][1] + a[i];
		if (i > 1) dp[i][0] = min(dp[i][0],dp[i-2][1] + a[i-1] + a[i]);
		dp[i][1] = dp[i-1][0];
		if (i > 1) dp[i][1] = min(dp[i][1],dp[i-2][0]);
	}
	printf ("%d\n",min(dp[n][0],dp[n][1]));
}
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}