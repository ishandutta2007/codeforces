#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MN = 1e6+3;
ll dp[MN],pma[MN][2];int a[MN];
int main () {
	int n; scanf ("%d",&n); pma[0][0] = pma[0][1] = LLONG_MIN;
	for (int i = 1; i <= n; i++) {
		scanf ("%d",&a[i]);
		pma[i][0] = max(dp[i-1]-a[i],pma[i-1][0]); pma[i][1] = max(dp[i-1]+a[i],pma[i-1][1]);
		dp[i] = max(pma[i][0]+a[i],pma[i][1]-a[i]);
	}
	printf ("%lld\n",dp[n]);
	return 0;
}