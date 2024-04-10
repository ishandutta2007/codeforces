#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define int long long

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=2005,M=1e6+5;
int n,m,dp[M],ans;

struct Node
{
	int x,y;
}a[N],b[N];

signed main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i)
	{
		a[i].x=read();
		a[i].y=read();
	}
	for(int i=1;i<=m;++i)
	{
		b[i].x=read();
		b[i].y=read();
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(a[i].x<=b[j].x&&a[i].y<=b[j].y)
				dp[b[j].x-a[i].x]=max(dp[b[j].x-a[i].x],b[j].y-a[i].y+1);
	ans=1e18;
	for(int i=1000000;i>=0;--i)
	{
		dp[i]=max(dp[i],dp[i+1]);
		ans=min(ans,dp[i]+i);
	}
	printf("%lld\n",ans);
	return 0;
}