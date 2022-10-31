#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define fi first
#define se second
using namespace std;
const int N=1e2+2,INF=1e9;
int p[N],dp[N][N][N][2]; bool tg[N];
void upd(int i,int j,int k,int t1,int t2,int o=0){
	int j2=j,k2=k; if (!o){ if (!t2) --j2; else --k2; }
	if (j2>=0&&k2>=0){
		int &x=dp[i][j][k][t2];
		x=min(x,dp[i-1][j2][k2][t1]+(t1!=t2));
	}
}
int main(){
	int n; scanf("%d",&n); int c0=n/2,c1=(n+1)/2;
	rep(i,1,n){
		scanf("%d",&p[i]);
		if (p[i]){ if (p[i]&1) --c1; else --c0; }
	}
	rep(i,1,n) rep(j,0,n) rep(k,0,n) dp[i][j][k][0]=dp[i][j][k][1]=INF;
	if (p[1]&1) dp[1][0][0][1]=0;
	else if ((p[1]&1)==0&&p[1]) dp[1][0][0][0]=0;
	else dp[1][1][0][0]=dp[1][0][1][1]=0;
	rep(i,2,n)
		rep(j,0,i)
			rep(k,0,i){
				rep(t,0,1){
					if (p[i]) upd(i,j,k,t,p[i]&1,1);
					else upd(i,j,k,t,0),upd(i,j,k,t,1);
				}
			}
	printf("%d\n",min(dp[n][c0][c1][0],dp[n][c0][c1][1]));
	return 0;
}