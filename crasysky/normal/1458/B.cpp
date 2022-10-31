#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=102; int a[N],b[N],dp[N][N*N];
int main(){
	int n,sa=0,sb=0; scanf("%d",&n);
	rep(i,1,n) scanf("%d%d",&a[i],&b[i]),sa+=a[i],sb+=b[i];
	rep(j,0,n) rep(k,0,sa) dp[j][k]=-1e9; dp[0][0]=0;
	rep(i,1,n)
		per(j,i,1)
			per(k,sa,a[i])
				dp[j][k]=max(dp[j][k],dp[j-1][k-a[i]]+b[i]);
	rep(j,1,n){
		int ans=0;
		rep(k,0,sa) ans=max(ans,min(2*k,sb+dp[j][k]));
		printf("%.10lf ",ans/2.0);
	}
	return 0;
}