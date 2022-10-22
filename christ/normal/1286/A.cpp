#include<bits/stdc++.h>
using namespace std;
const int MN = 1e5+2, MOD = 1e9+7;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define all(x) (x).begin(),(x).end()
bool in[MN];
int dp[105][105][2];
int main () {
	int n;
	scanf ("%d",&n);
	vector<int> a(n);
	for (auto &au : a) scanf ("%d",&au), in[au] = 1;
	int cntodd=0,cnteven=0;
	for (int i = 1; i <= n; i++) if (!in[i]) (i&1?cntodd:cnteven)++;
	int sofar = 0;
	memset(dp,0x3f,sizeof dp);
	dp[0][0][0] = dp[0][0][1] = 0;
	for (int i = 1; i <= n; i++) {
		sofar += a[i-1] == 0;
		for (int j = max(0,sofar-cnteven); j <= min(sofar,cntodd); j++) {
			if (a[i-1]) {
				dp[i][j][a[i-1]&1] = min(dp[i-1][j][a[i-1]&1],dp[i-1][j][!(a[i-1]&1)]+1);
			} else {
				dp[i][j][0] = min(dp[i-1][j][0],dp[i-1][j][1]+1);
				if (j) {
					dp[i][j][1] = min(dp[i-1][j-1][1],dp[i-1][j-1][0]+1);
				}
			}
		}
	}
	int best = MN;
	for (int j = 0; j <= sofar; j++) best = min({best,dp[n][j][0],dp[n][j][1]});
	printf ("%d\n",best);
	return 0;
}