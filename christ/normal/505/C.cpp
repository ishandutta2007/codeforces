#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 3e4+3, MOD = 1e9+7;
mt19937_64 rnd = mt19937_64(chrono::steady_clock::now().time_since_epoch().count());
int a[MN], dp[MN][505];
int main() {
	int n,d;
	scanf ("%d %d",&n,&d);
	for (int b; n--;) scanf ("%d",&b), ++a[b];
	int st = max(d-250,1), ed = min(d+250,30000);
	memset(dp,-0x3f,sizeof dp); dp[d][252] = a[d];
	int ret = a[d];
	for (int i = d+1; i <= 30000; i++) {
		for (int len = st; len <= ed; len++) if (i-len >= 0){
			int id = len-d+252;
			ret = max(ret,dp[i][id] = max({dp[i-len][id],dp[i-len][id-1],dp[i-len][id+1]}) + a[i]);
		}
	}
	printf ("%d\n",ret);
    return 0;
}