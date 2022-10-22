#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 5e5+3, MK = 1001, MOD = 1e9+7;
mt19937_64 rnd = mt19937_64(chrono::steady_clock::now().time_since_epoch().count());
int dp[32][32];
void solve () { //length of array is small
	int d,m,ret=0;
	scanf ("%d %d",&d,&m);
	memset(dp,0,sizeof dp);
	for (int i = 0; i < 30; i++) if ((1 << i) <= d){
		dp[1][i] = (min(1 << (i+1),d+1)-(1<<i))%m;
		ret = (ret+dp[1][i])%m;
	}
	for (int i = 2; i <= 30; i++) {
		for (int j = 0; j < 30; j++) if ((1 << j) <= d){
			int ways = (min(1 << (j+1),d+1)-(1<<j));
			for (int lst = j-1; lst >= 0; lst--) {
				dp[i][j] += dp[i-1][lst] * 1LL * ways % m;
				dp[i][j] %= m;
			}
			ret = (ret+dp[i][j])%m;
		}
	}
	printf ("%d\n",ret);
}
int main() {
	int t;
	scanf ("%d",&t);
	while (t--) solve();
    return 0;
}