#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=4e3+3; int p[N]; bitset<N> dp;
int main(){
	int T; scanf("%d",&T);
	while (T--){
	    int n; scanf("%d",&n);
	    rep(i,1,2*n) scanf("%d",&p[i]);
	    int mx=p[1],l=1; dp.reset(); dp[0]=1;
	    rep(i,2,2*n)
	    	if (p[i]>mx) dp|=dp<<i-l,mx=p[i],l=i;
		dp|=dp<<2*n-l+1;
		puts(dp[n]?"YES":"NO");
	}
	return 0;
}