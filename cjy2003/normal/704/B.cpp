#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const long long inf=0x3f3f3f3f3f3f3f3f;
inline void upd(long long &x,long long y){x>y?x=y:0;}
int n,s,e,x[5050],a[5050],b[5050],c[5050],d[5050];
long long dp[5050][5050];
int main()
{
	scanf("%d %d %d",&n,&s,&e);
	for(int i=1;i<=n;++i)scanf("%d",&x[i]);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	for(int i=1;i<=n;++i)scanf("%d",&c[i]);
	for(int i=1;i<=n;++i)scanf("%d",&d[i]);
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	int t=0;
	for(int i=0;i<n;++i)
	{
		for(int j=0,k=j+t;j<=n;++j,++k)
			if(dp[i][j]!=inf)
			{
				if(i+1==s)
				{
					if(k)upd(dp[i+1][j],dp[i][j]+x[i+1]+c[i+1]);
					upd(dp[i+1][j+1],dp[i][j]-x[i+1]+d[i+1]);
				}
				else if(i+1==e)
				{
					if(j)upd(dp[i+1][j-1],dp[i][j]+x[i+1]+a[i+1]);
					upd(dp[i+1][j],dp[i][j]-x[i+1]+b[i+1]);
				}
				else
				{
					if(j)upd(dp[i+1][j],dp[i][j]+a[i+1]+d[i+1]);
					if(k)upd(dp[i+1][j],dp[i][j]+b[i+1]+c[i+1]);
					if(j&&k)upd(dp[i+1][j-1],dp[i][j]+2*x[i+1]+a[i+1]+c[i+1]);
					upd(dp[i+1][j+1],dp[i][j]-2*x[i+1]+b[i+1]+d[i+1]);
				}
			/*	if(i+1==s)
				{
					if(k)upd(dp[i+1][j],dp[i][j]+1ll*(x[i+1]-x[i])*(j+k)+c[i+1]);
					upd(dp[i+1][j+1],dp[i][j]+1ll*(x[i+1]-x[i])*(j+k)+d[i+1]);
				//	--t;
				}
				else if(i+1==e)
				{
					if(j)upd(dp[i+1][j-1],dp[i][j]+1ll*(x[i+1]-x[i])*(j+k)+a[i+1]);
					upd(dp[i+1][j],dp[i][j]+1ll*(x[i+1]-x[i])*(j+k)+b[i+1]);
				//	++t;
				}
				else
				{
					if(j)upd(dp[i+1][j],dp[i][j]+1ll*(j+k)*(x[i+1]-x[i])+a[i+1]+d[i+1]);
					if(k)upd(dp[i+1][j],dp[i][j]+1ll*(j+k)*(x[i+1]-x[i])+b[i+1]+c[i+1]);
					if(j&&k)upd(dp[i+1][j-1],dp[i][j]+1ll*(j+k)*(x[i+1]-x[i])+a[i+1]+c[i+1]);
					upd(dp[i+1][j+1],dp[i][j]+1ll*(j+k)*(x[i+1]-x[i])+b[i+1]+d[i+1]);
				}*/
			}
		if(i+1==s)--t;
		if(i+1==e)++t;
		if(!t&&i!=n-1)dp[i+1][0]=inf;
	}
	printf("%lld",dp[n][0]);
	return 0;
}