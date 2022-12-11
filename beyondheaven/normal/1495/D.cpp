#include<bits/stdc++.h>
typedef long long LL;
const int MaxN = 623;
const LL Mod = 998244353;

int n,m,a[MaxN],b[MaxN];
int dis[MaxN][MaxN];

int main()
{
	scanf("%d%d",&n,&m);
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",a+i,b+i);
		dis[a[i]][b[i]]=dis[b[i]][a[i]]=1;
	}
	for(int i=1;i<=n;++i)dis[i][i]=0;
	
	for(int k=1;k<=n;++k)
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j)
	dis[i][j]=std::min(dis[i][j],dis[i][k]+dis[k][j]);
	
	auto Solve=[&](int x,int y)
	{
		auto check=[&](int o)
		{
			return dis[x][o]+dis[o][y]==dis[x][y];
		};
		
		int cnt=0;
		for(int i=1;i<=n;++i)if(check(i))++cnt;
		
		if(cnt!=dis[x][y]+1)return 0LL;
		
		std::vector<int>p(n+1);
		for(int i=1;i<=m;++i)
		{
			if(dis[a[i]][x]==dis[b[i]][x]+1 
				&& dis[a[i]][y]==dis[b[i]][y]+1)
			++p[a[i]];
			
			if(dis[b[i]][x]==dis[a[i]][x]+1
				&& dis[b[i]][y]==dis[a[i]][y]+1)
			++p[b[i]]; 
		}
		
		LL res=1;
		for(int i=1;i<=n;++i)
		if(!check(i))res=res*p[i]%Mod;
		return res;
	};
	
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j)
	printf("%lld%c",Solve(i,j)," \n"[j==n]);
	return 0;
}