#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,p[401],dp[401][401][401],q[401][401],h[401],t[401],x,y,c,r;
long long ans;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&p[i]);
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=n;++j)
			h[j]=t[j]=1,q[j][1]=i;
		for(int j=i+1;j<=n;++j)
		{
			dp[i][j][0]=p[j]-p[i];
			for(int k=0;k<n;++k)
			{
				while(h[k]<=t[k]&&p[j]-p[q[k][h[k]]]>=dp[i][q[k][h[k]]][k])++h[k];
				if(h[k]<=t[k])dp[i][j][k+1]=min(dp[i][q[k][h[k]]][k],p[j]-p[q[k][h[k]]-1]);
				else dp[i][j][k+1]=p[j]-p[j-1];
			}
			for(int k=0;k<n;++k)
				q[k][++t[k]]=j;
		}
	}
	while(m--)
	{
		scanf("%d %d %d %d",&x,&y,&c,&r);
	//	printf("%d\n",dp[x][y][r]);
		ans=max(ans,1ll*dp[x][y][r]*c);
	}
	printf("%I64d",ans);
	return 0;
}