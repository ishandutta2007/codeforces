#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
inline void upmax(int &x,int y){x<y?x=y:0;}
int t,n,m,a[13][2020],p[1<<12],cur[1<<12],lb[1<<12],dp[1<<12],pre[1<<12];
bool vis[1<<12];
vector<int>f[1<<12];
vector<int>all;
int main()
{
	for(int i=0;i<12;++i)lb[1<<i]=i+1;
	for(int i=1;i<1<<12;++i)lb[i]=lb[i&-i];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		memset(vis,0,sizeof(vis));
		for(int i=0;i<1<<n;++i)
			if(!vis[i])
			{
				int x=i;p[i]=i;
				for(int j=1;j<n;++j)
				{
					x<<=1;
					if(x>>n&1)x^=1<<n,x^=1;
					if(x!=i)vis[x]=1,p[x]=i;
				}
				all.push_back(i);
				for(int j=(i-1)&i;j!=i;j=(j-1)&i)
					if(!vis[j])f[i].push_back(j);
			}
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				scanf("%d",&a[i][j]);
		memset(pre,0,sizeof(pre));
		for(int i=1;i<=m;++i)
		{
			for(int j=1;j<1<<n;++j)cur[j]=cur[j-(j&-j)]+a[lb[j&-j]][i];
			for(int j=1;j<1<<n;++j)
				if(vis[j])upmax(cur[p[j]],cur[j]);
			for(int j=1;j<1<<n;++j)cur[j]=cur[p[j]];
			memcpy(dp,pre,sizeof(dp));
			for(auto j:all)
				for(int k=(j-1)&j;k!=j;k=(k-1)&j)upmax(dp[j],pre[k]+cur[j^k]);
			for(int j=1;j<1<<n;++j)pre[j]=dp[p[j]];
		}
		printf("%d\n",dp[(1<<n)-1]);
		for(auto u:all)f[u].clear();
		all.clear();
	}
	return 0;
}