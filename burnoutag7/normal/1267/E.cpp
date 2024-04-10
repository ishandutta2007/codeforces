/*********************
*  Author: xuziyuan  * 
*********************/

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

const LL MOD=1e9+7;

int n,m,a[110][110],dp[110][110][110],ai,aj,ak,ans=1e9;
pii pre[110][110][110];
vector <int> ans2;

int main()
{
	cin>>n>>m;
	rep(i,m) rep(j,n) cin>>a[i][j];
	rep(i,n-1)
	{
		rep(j,105) rep(k,105) dp[i][j][k]=-1e9;
		dp[i][0][0]=0;
		rep(j,m)
		{
			rep(k,j+1)
			{
				if(dp[i][j][k]==-1e9) continue;
				if(dp[i][j+1][k]<dp[i][j][k]+a[j][i]-a[j][n-1])
				{
					dp[i][j+1][k]=dp[i][j][k]+a[j][i]-a[j][n-1];
					pre[i][j+1][k]=mpr(j,k);
				}
				if(dp[i][j+1][k+1]<dp[i][j][k])
				{
					dp[i][j+1][k+1]=dp[i][j][k];
					pre[i][j+1][k+1]=mpr(j,k);
				}
			}
		}
		rep(k,m+1) if(dp[i][m][k]>=0&&ans>k)
		{
			ans=k;
			ai=i;
			aj=m;
			ak=k;
		}
	}
	cout<<ans<<endl;
	while(!(aj==0&&ak==0))
	{
		int tmp=pre[ai][aj][ak].fi,tmp2=pre[ai][aj][ak].se;
		if(tmp==aj-1&&tmp2==ak-1) ans2.pb(aj);
		aj=tmp;
		ak=tmp2;
	}
	rep(i,ans2.size()) cout<<ans2[i]<<' ';
	cout<<endl;
	return 0;
}