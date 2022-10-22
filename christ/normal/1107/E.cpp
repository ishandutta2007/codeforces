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
const int MN = 1e6 + 2, LOG = 17, INF = 1e8;
char s[105];
ll a[105], dp[105][105], dp2[105][105];
void solve (int l, int r) {
	ll &ret = dp[l][r];
	int cnt = 1; memset(dp2,-0x3f,sizeof dp2); dp2[l][1] = 0; ret = a[1] + dp[l+1][r];
 	for (int i = l+1; i <= r; i++) if (s[i] == s[l]) {
		++cnt;
		for (int take = 2; take <= cnt; take++) {
			for (int lst = i-1; lst >= l; lst--) if (s[lst] == s[l]) {
				dp2[i][take] = max(dp2[i][take],dp2[lst][take-1] + dp[lst+1][i-1]);
			}
			ret = max(ret,dp2[i][take] + a[take] + dp[i+1][r]);
		}
	}
}
int main () { 
	int n;
	scanf ("%d",&n);
	scanf ("%s",s+1);
	for (int i = 1; i <= n; i++) {
		scanf ("%lld",&a[i]);
		for (int j = 1; j < i; j++) a[i] = max(a[i],a[j] + a[i-j]);
	}
	for (int len = 1; len <= n; len++) {
		for (int l = 1; l <= n - len + 1; l++) {
			int r = l + len - 1;
			solve(l,r);
		}
	}
	printf ("%lld\n",dp[1][n]);
    return 0;
}
/*
Take some subset of 1s such that
a[cnt] + sum(solve(middle)) + solve(i+1,r) is maximal
*/