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
const int MN = 1e5 + 2, LOG = 17, INF = 1e8;
ll dp[21][MN];int freq[MN], a[MN];ll add;
void brr (int k, int l, int r, int dl, int dr) {
	int mid = (l + r) / 2; int des = 1;
	for (int i = mid; i >= l && i > dr; i--) add += freq[a[i]]++;
	for (int i = min(mid,dr); i >= dl; i--) {
		add += freq[a[i]]++;
		if (add + dp[k-1][i-1] < dp[k][mid]) {
			des = i;
			dp[k][mid] = dp[k-1][i-1] + add;
		}
	}
	for (int i = mid; i >= l && i > dr; i--) add -= --freq[a[i]];
	for (int i = min(mid,dr); i >= dl; i--) add -= --freq[a[i]];
	for (int i = min(dr,l-1); i > des; i--) {
		add += freq[a[i]]++;
	}
	if (l < mid) brr(k,l,mid-1,dl,des);
	for (int i = min(dr,l-1); i > des; i--) {
		add -= --freq[a[i]];
	}
	for (int i = max(l,dr+1); i <= mid; i++) {
		add += freq[a[i]]++;
	}
	if (mid < r) brr(k,mid+1,r,des,dr);
	for (int i = max(l,dr+1); i <= mid; i++) {
		add -= --freq[a[i]];
	}
}
void solve () { 
	int n,K;
	scanf ("%d %d",&n,&K);
	memset(dp,0x3f,sizeof dp);
	dp[0][0] = 0; for (int i = 1; i <= n; i++) scanf ("%d",a+i);
	for (int k = 1; k <= K; k++) {
		memset(freq,0,sizeof freq); add = 0;
		brr(k,1,n,1,n);
	}
	printf ("%lld\n",dp[K][n]);
}
int main () { 
	int _t = 1;
	//scanf ("%d",&_t);
	for (int cs = 1; cs <= _t; cs++) solve();
    return 0;
}
//