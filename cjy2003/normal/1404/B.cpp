#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int T,n,a,b,da,db;
vector<int>E[100010];
int dep[100010];
void dfs(int v,int fa)
{
	dep[v]=dep[fa]+1;
	for(auto u:E[v])
		if(u!=fa)dfs(u,v);
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d %d %d",&n,&a,&b,&da,&db);
		for(int i=1,x,y;i<n;++i)
		{
			scanf("%d %d",&x,&y);
			E[x].emplace_back(y);
			E[y].emplace_back(x);
		}
		if(2*da>=db)puts("Alice");
		else
		{
			dfs(a,0);
			if(dep[b]<=da+1)puts("Alice");
			else
			{
				int p=0;
				for(int i=1;i<=n;++i)if(dep[i]>dep[p])p=i;
				dfs(p,0);
				int mx=0;
				for(int i=1;i<=n;++i)mx=max(mx,dep[i]);
				--mx;
				if(mx<=2*da)puts("Alice");
				else puts("Bob");
			}
		}
		for(int i=1;i<=n;++i)E[i].clear();
	}
	return 0;
}