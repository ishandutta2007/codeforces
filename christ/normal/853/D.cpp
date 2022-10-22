#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using pil = pair<int,ll>;
using ld = long double;
using ui = unsigned int;
using ull = unsigned long long;
using ui128 = __uint128_t;
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define lc ind<<1
#define rc ind<<1|1
const int MN = 3e5 + 2, LOG = 17, INF = 1e8;
int dp[MN][42], a[MN];
int main () { 
	int n;
	scanf ("%d",&n);
	for (int i = 1; i <= n; i++) scanf ("%d",&a[i]), a[i] /= 100;
	memset(dp,0x3f,sizeof dp); dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int lst = 0; lst <= 40; lst++) {
			if (lst + 2 <= 40 && a[i] == 20) dp[i][lst+2] = min(dp[i][lst+2],dp[i-1][lst] + 2000);
			if (lst + 1 <= 40 && a[i] == 10) dp[i][lst+1] = min(dp[i][lst+1],dp[i-1][lst] + 1000);
			for (int take = 0; take <= lst; take++) {
				if (take <= 10 && a[i] == 10) dp[i][lst-take] = min(dp[i][lst-take],dp[i-1][lst] + 1000 - take * 100);
				if (take <= 20 && a[i] == 20) dp[i][lst-take] = min(dp[i][lst-take],dp[i-1][lst] + 2000 - take * 100);
			}
		}
	}
	int res = INT_MAX;
	for (int i = 0; i <= 40; i++) res = min(res,dp[n][i]);
	printf ("%d\n",res);
    return 0;
}