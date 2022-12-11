#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,d[100010],rt,f[100010],dep[100010],w[100010];
vector<int>E1[100010];
vector<pair<int,int> >E2[100010];
void dfs(int v,int fa)
{
	dep[v]=dep[fa]+1;
	for(auto u:E1[v])
	{
		if(u==fa)continue;
		f[u]=v;dfs(u,v);
	}
}
int dis[100010];
int bfs(int v)
{
	static int q[100010],h,t;
	memset(dis+1,-1,n<<2);
	h=0,t=1,q[t]=v,dis[v]=w[v];
	while(h<t)
	{
		int x=q[++h];
		for(auto u:E2[x])
			if(dis[u.first]==-1)
			{
				dis[u.first]=dis[x]+u.second+w[u.first];
				q[++t]=u.first;
			}
	}
	int mx=1;
	for(int i=1;i<=n;++i)if(dis[i]>dis[mx])mx=i;
	return mx;
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<n;++i)
	{
		scanf("%d %d",&x,&y);
		E1[x].emplace_back(y);
		E1[y].emplace_back(x);
		++d[x],++d[y];
	}
	for(int i=1;i<=n;++i)if(d[i]!=2){rt=i;break;}
	dfs(rt,0);
	for(int i=1;i<=n;++i)
		if(d[i]!=2)
		{
			if(d[i]>2)w[i]=d[i]-2;
			if(i==rt)continue;
			int x=f[i];
			while(d[x]==2)x=f[x];
			int c=(dep[i]-dep[x]+(d[i]==1)+(d[x]==1))/2;
			E2[i].emplace_back(make_pair(x,c));
			E2[x].emplace_back(make_pair(i,c));
		}
	int p=bfs(rt);
	int q=bfs(p);
	printf("%d\n",dis[q]);
	return 0;
}