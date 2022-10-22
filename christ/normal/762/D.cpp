#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using pib = pair<int,bool>;
using ll = long long;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#ifdef fread_unlocked
#define fread fread_unlocked
#define fwrite fwrite_unlocked
#endif
#define mp make_pair
#define lc ind<<1
#define rc ind<<1|1
const int MN = 1e5+5, MK = 6e4 + 5, MOD = 1e9+7, BASE = 31, MASK = (1 << 10) - 1, SQRT = 315;
int a[MN][4];ll dp[MN][4], psa[MN];
int main () {
	int n;
	scanf ("%d",&n);
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= n; j++)
			scanf ("%d",&a[j][i]);
	ll mx3,mx1; dp[0][2] = dp[0][3] = mx3 = mx1 = -1e18;
	for (int i = 1; i <= n; i++) {
		psa[i] = psa[i-1] + a[i][1] + a[i][2] + a[i][3];
		dp[i][1] = max({dp[i-1][1],dp[i-1][2] + a[i][2],dp[i-1][3] + a[i][3] + a[i][2]}) + a[i][1];
		dp[i][2] = max({dp[i-1][1] + a[i][1],dp[i-1][2],dp[i-1][3] + a[i][3]}) + a[i][2];
		dp[i][3] = max({dp[i-1][1]+a[i][1]+a[i][2],dp[i-1][2]+a[i][2],dp[i-1][3]}) + a[i][3];
		dp[i][1] = max(dp[i][1],mx3 + psa[i]);
		dp[i][3] = max(dp[i][3],mx1 + psa[i]);
		mx3 = max(mx3,dp[i-1][3] - psa[i-1]);
		mx1 = max(mx1,dp[i-1][1] - psa[i-1]);
	}
	printf ("%lld\n",dp[n][3]);
	return 0;
}