#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int n,m,i,j,to[25200005],a[1005],mod=2520,ans[25200005],g[1005][11],deg[1005],x,y;
char vis[25200005],vv[1005];
int main()
{
	memset(ans,-1,sizeof(ans));
	scanf("%d",&n);
	rep(i,n)
	{
		scanf("%d",&a[i]);
		a[i]%=mod;
		if(a[i]<0)a[i]+=mod;
	}
	rep(i,n)
	{
		scanf("%d",&deg[i]);
		rep(j,deg[i])
		{
			scanf("%d",&g[i][j-1]);
		}
	}
	rep(i,n)
	{
		for(j=0;j<mod;j++)
		{
			int t=(j+a[i])%mod,nxt=t%deg[i];
			to[(i-1)*mod+j]=(g[i][nxt]-1)*mod+t;
		}
	}
	for(i=0;i<n*mod;i++)if(ans[i]==-1)
	{
		if(vis[i])exit(-1);
		int x=i;
		while(!vis[x])
		{
			vis[x]=1;
			x=to[x];
		}
		if(ans[x]!=-1)
		{
			int mem=x;x=i;
			while(ans[x]==-1)
			{
				ans[x]=ans[mem];
				x=to[x];
			}
			continue;
		}
		int mem=x,cnt=0;
		do
		{
			cnt+=(!vv[x/mod]);
			vv[x/mod]=1;
			x=to[x];
		}
		while(x!=mem);
		do
		{
			ans[x]=cnt;
			vv[x/mod]=0;
			x=to[x];
		}
		while(x!=mem);
		x=i;
		while(x!=mem)
		{
			ans[x]=cnt;
			x=to[x];
		}
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&x,&y);
		y%=mod;
		if(y<0)y+=mod;
		x=(x-1)*mod+y;
		printf("%d\n",ans[x]); 
	}
	return 0;
}