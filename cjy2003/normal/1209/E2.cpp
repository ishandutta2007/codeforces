#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
inline void upmax(int &x,int y){x<y?x=y:0;}
int t,n,m,a[13][2020],p[1<<12],dp[1<<12];
bool vis[1<<12];
vector<int>f[12];
pair<int,int>pos[2020];
bool cmp(pair<int,int>x,pair<int,int>y){return x.first>y.first;}
int main()
{
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
			}
		for(int i=0;i<n;++i)
			for(int j=0;j<1<<n;++j)
				if(j>>i&1)f[i].push_back(j);
		for(int i=0;i<n;++i)
			for(int j=1;j<=m;++j)
				scanf("%d",&a[i][j]);
		for(int i=1;i<=m;++i)
		{
			int mx=0;
			for(int j=0;j<n;++j)mx=max(mx,a[j][i]);
			pos[i]=make_pair(mx,i);
		}
		sort(pos+1,pos+1+m,cmp);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n&&i<=m;++i)
		{
			for(int j=0;j<n;++j)
				for(auto k:f[j])upmax(dp[k],dp[k^(1<<j)]+a[j][pos[i].second]);
			for(int j=1;j<1<<n;++j)upmax(dp[p[j]],dp[j]);
			for(int j=1;j<1<<n;++j)dp[j]=dp[p[j]];
		}
		printf("%d\n",dp[(1<<n)-1]);
		for(int i=0;i<n;++i)f[i].clear();
	}
	return 0;
}