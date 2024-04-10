#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,dp[65][100005],id[65][100005];
long long a[100005];
struct str{
	long long a;
	int x;
}b[65][100005];
bool cmp(str a,str b)
{
	if(a.a==b.a)
		return a.x<b.x;
	return a.a<b.a;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	for(i=1;i<=n;++i)
		for(j=0;j<=61;++j)
		{
			b[j][i].a=(a[i]&(1ll<<j)-1);
			b[j][i].x=i;
		}
	for(i=1;i<=61;++i)
	{
		sort(b[i]+1,b[i]+1+n,cmp);
		for(j=1;j<=n;++j)
			id[i][b[i][j].x]=j;
	}
	for(i=1;i<=n;++i)
		dp[0][i]=1<<30;
	for(i=1;i<=61;++i)
	{
		int s=0;
		for(j=1;j<=n;++j)
			s+=(a[j]>>i-1)&1;
		int las=1;
		while(las<=n&&(((a[b[i][las].x]>>i-1)&1)^1))
			++las;
		for(j=1;j<=n+1;++j)
			dp[i][j]=1<<30;
		for(j=1;j<=n+1;++j)
		{
			dp[i][las]=min(dp[i][las],dp[i-1][j]+s);
			s-=(a[b[i-1][j].x]>>i-1)&1;
			s+=((a[b[i-1][j].x]>>i-1)&1)^1;
			if((a[b[i-1][j].x]>>i-1)&1)
				las=id[i][b[i-1][j].x]+1;
		}
		s=0;
		for(j=1;j<=n;++j)
			s+=((a[j]>>i-1)&1)^1;
		las=1;
		for(j=1;j<=n+1;++j)
		{
			dp[i][las]=min(dp[i][las],dp[i-1][j]+s);
			s-=((a[b[i-1][j].x]>>i-1)&1)^1;
			s+=(a[b[i-1][j].x]>>i-1)&1;
			if(((a[b[i-1][j].x]>>i-1)&1)^1)
				las=id[i][b[i-1][j].x]+1;
		}
	}
	cout<<dp[61][n+1];
}