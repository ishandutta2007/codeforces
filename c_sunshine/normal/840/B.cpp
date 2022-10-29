#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=300005;
#define next next_
int n,m;
int d[maxn];
int u[maxn],v[maxn];
int head[maxn],adj[maxn*2],next[maxn*2],tot;
int ans[maxn];
void addedge(int u,int v)
{tot++;adj[tot]=v;next[tot]=head[u];head[u]=tot;}

int vis[maxn],ID;

int tdfs(int x)
{
	vis[x]=1;
	if(d[x]==-1)d[x]=0,ID=x;
	int res=d[x];
	for(int i=head[x];i;i=next[i])
		if(!vis[adj[i]])
			res^=tdfs(adj[i]);
	return res;
}

int dfs(int x)
{
	vis[x]=1;
	int res=d[x];
	for(int i=head[x];i;i=next[i])
		if(!vis[adj[i]])
		{
			int t=dfs(adj[i]);
			if(t)ans[i/2]=1,res^=1;
		}
	return res;
}

int main()
{
	//freopen("b.in","r",stdin);
	//freopen("b.out","w",stdout);
	scanf("%d%d",&n,&m);tot=1;
	for(int i=1;i<=n;i++)
		scanf("%d",d+i);
	for(int i=1;i<=m;i++)
		scanf("%d%d",u+i,v+i),addedge(u[i],v[i]),addedge(v[i],u[i]);
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			ID=0;
			int t=tdfs(i);
			if((t&1)&&ID==0){puts("-1");return 0;}
			d[ID]=(t&1);
		}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		if(!vis[i])
			dfs(i);
	int k=0;
	for(int i=1;i<=m;i++)k+=ans[i];
	cout<<k<<endl;
	for(int i=1;i<=m;i++)
		if(ans[i])printf("%d ",i);
	cout<<endl;
	return 0;
}