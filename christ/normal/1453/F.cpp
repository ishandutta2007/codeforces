#include <bits/stdc++.h>
using namespace std;
const int MN = 3e3+5;
int main () {
	int t; scanf ("%d",&t);
	while (t--) {
		int n; scanf ("%d",&n);
		vector<int> a(n+1);
		for (int i = 1; i <= n; i++) scanf ("%d",&a[i]);
		vector<vector<int>> dp(n+1,vector<int>(n+2,1e9)), suf(n+1,vector<int>(n+2,1e9));
		vector<int> bit(n+1);
		auto inc = [&] (int i) {
			for (;i<=n;i+=i&-i)
				bit[i]++;
		};
		auto query = [&] (int i) {
			int ret = 0;
			for (;i;i^=i&-i)
				ret += bit[i];
			return ret;
		};
		dp[n][n+1] = 0;
		suf[n][n+1] = 0;
		for (int j = n; j >= 1; j--) suf[n][j] = 0;
		for (int i = n-1; i >= 1; i--) {
			for (int j = 0; j <= n; j++) bit[j] = 0;
			for (int j = i+1; j <= n; j++) {
				if (a[i] + i >= j) {
					int add = query(n) - query(j-1);
					dp[i][j] = suf[j][a[i] + i + 1] + add;
				}
				inc(a[j] + j);
			}
			suf[i][n+1] = dp[i][n+1];
			for (int j = n; j >= 1; j--) suf[i][j] = min(dp[i][j],suf[i][j+1]);
		}
		int ret = INT_MAX;
		for (int j = 2; j <= n; j++) ret = min(ret,dp[1][j]);
		printf ("%d\n",ret);
	}
	return 0;
}