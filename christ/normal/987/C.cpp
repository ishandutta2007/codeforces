#include <bits/stdc++.h>
using namespace std;
const int MN = 1e5 + 5;

int main () {
	int n;
	scanf ("%d",&n);
	vector<int> s(n+1), c(n+1);
	vector<vector<long long>> dp(n+1,vector<long long>(4,1e18));
	for (int i = 1; i <= n; i++) scanf ("%d",&s[i]);
	long long ret = 1e18;
	for (int i = 1; i <= n; i++) {
		scanf ("%d",&c[i]);
		dp[i][1] = c[i];
		for (int k = 2; k <= 3; k++) {
			for (int j = i-1; j >= 1; j--) if (s[j] < s[i]) {
				dp[i][k] = min(dp[i][k],dp[j][k-1] + c[i]);
			}
		}
		ret = min(ret,dp[i][3]);
	}
	printf ("%lld\n",ret > 1e12 ? -1 : ret);
	return 0;
}