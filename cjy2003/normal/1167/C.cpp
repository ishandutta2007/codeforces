#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[1000010];
int n,m,k,q[1000010],h,t;
int ans[500050];
bool vis[1000010];
void bfs(int v)
{
	h=0,t=1;q[1]=v;vis[v]=1;
	int x,cnt=0;
	while(h<t)
	{
		x=q[++h];
		if(x<=n)++cnt;
		for(auto y:E[x])
			if(!vis[y])vis[y]=1,q[++t]=y;
	}
	for(int i=1;i<=t;++i)
		if(q[i]<=n)ans[q[i]]=cnt;
}
int main()
{
	scanf("%d %d",&n,&m);
	int x;
	for(int i=1;i<=m;++i)
	{
		scanf("%d",&k);
		for(int j=1;j<=k;++j)
		{
			scanf("%d",&x);
			E[x].push_back(i+n);
			E[i+n].push_back(x);
		}
	}
	for(int i=1;i<=n;++i)
		if(!vis[i])bfs(i);
	for(int i=1;i<=n;++i)
		printf("%d ",ans[i]);
	return 0;
}