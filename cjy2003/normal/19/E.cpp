#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct bian
{
	int to,nxt,id;
}bi[20020];
int n,m,head[10010],num,sum1[10010],sum2[10010],depth[10010],f[10010],t1,p;
int ans[10010],cnt;
void add(int from,int to,int id)
{
	bi[++num].nxt=head[from];
	head[from]=num;
	bi[num].to=to;
	bi[num].id=id;
}
void dfs(int v,int fa)
{
//	printf("%d\n",v);
	int u;
	depth[v]=depth[fa]+1;f[v]=fa;
	for(int i=head[v];i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa)continue;
		if(!depth[u])dfs(u,v);
		else if(depth[u]<depth[v])
		{
			if((depth[v]-depth[u]+1)&1)++sum1[v],--sum1[u],++t1,p=bi[i].id;
			else ++sum2[v],--sum2[u];
		}
	}
}
void dfs2(int v,int fa)
{
	int u;
	for(int i=head[v];i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa)continue;
		if(f[u]==v)
		{
			dfs2(u,v),sum1[v]+=sum1[u],sum2[v]+=sum2[u];
			if(sum1[u]==t1&&!sum2[u])ans[++cnt]=bi[i].id;	
		}
		else if(depth[u]<depth[v]&&t1==1&&((depth[v]-depth[u]+1)&1))ans[++cnt]=bi[i].id;
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	int x,y;
	for(int i=1;i<=m;++i)
	{
		scanf("%d %d",&x,&y);
		add(x,y,i);
		add(y,x,i);	
	}
  	for(int i=1;i<=n;++i)
		if(!depth[i])
			dfs(i,0);
	if(!t1)
	{
		printf("%d\n",m);
		for(int i=1;i<=m;++i)
			printf("%d ",i);
		return 0;
	}
//	printf("%d ",t1);
	for(int i=1;i<=n;++i)
		if(!f[i])
			dfs2(i,0);
	sort(ans+1,ans+1+cnt);
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;++i)
		printf("%d ",ans[i]);
	return 0;
}