#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct bian
{
	int to,nxt;
}bi[200020];
int n,m,head[100010],num=1,depth[100010],f[100010],cnt[100010],sum[100010],fb[100010],ans[100010],res;
void add(int from,int to)
{
	bi[++num].nxt=head[from];
	head[from]=num;
	bi[num].to=to;
}
void dfs1(int v,int fa)
{
	int u;
	for(int i=head[v];i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa)continue;
		if(!depth[u])fb[u]=i,depth[u]=depth[v]+1,f[u]=v,dfs1(u,v);
		else if(depth[u]<depth[v])++cnt[v],--cnt[u];
	}
}
void dfs2(int v,int fa)
{
	int u;
	for(int i=head[v];i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa)continue;
		if(f[u]==v)dfs2(u,v),cnt[v]+=cnt[u];
	}
	if(cnt[v]>=2)++sum[v];
}
void dfs3(int v,int fa)
{
	int u;
	for(int i=head[v];i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa)continue;
		if(f[u]==v)sum[u]+=sum[v],dfs3(u,v);
		else if(depth[v]>depth[u]&&sum[v]-sum[u]==0)
		{
			ans[++res]=i/2;
			int x=v;
			while(x!=u)ans[++res]=fb[x]/2,x=f[x];
		}
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	int x,y;
	for(int i=1;i<=m;++i)
	{
		scanf("%d %d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;++i)
		if(!depth[i])depth[i]=1,dfs1(i,0);
	for(int i=1;i<=n;++i)
		if(!f[i])dfs2(i,0);
	for(int i=1;i<=n;++i)
		if(!f[i])dfs3(i,0);
	sort(ans+1,ans+1+res);
	printf("%d\n",res);
	for(int i=1;i<=res;++i)
		printf("%d ",ans[i]);
	return 0;
}