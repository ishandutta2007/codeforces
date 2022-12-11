#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,q;
namespace graph
{
	struct bian
	{
		int nxt,to;
	}bi[400040];	
	int head[200020],num,dfn[200020],low[200020],dfnum,bl[200020],cnt,st[200020],tp;
	inline void add(int from,int to){bi[++num]=bian{head[from],to};head[from]=num;}
	void tarjan(int v,int fb)
	{
	//	printf("%d\n",v);
		dfn[v]=low[v]=++dfnum;st[++tp]=v;
		for(int i=head[v],u;i;i=bi[i].nxt)
		{
			u=bi[i].to;
			if((i+1)/2==(fb+1)/2)continue;
			if(!dfn[u])
			{
				tarjan(u,i);
				low[v]=min(low[v],low[u]);
			}
			else low[v]=min(low[v],dfn[u]);
		}
		if(dfn[v]==low[v])
		{
			bl[v]=++cnt;
			while(st[tp]!=v)bl[st[tp--]]=cnt;
			--tp;
		}
	}
}using namespace graph;
namespace tree
{
	vector<int>E[200020];
	int dep[200020],tp[200020],f[200020],siz[200020],zson[200020],rt[200020];
	pair<int,int>tag[200020];
	void push(int x,int c,int d)
	{
		if(!d)return ;
		if(!tag[x].first)tag[x]=make_pair(c,d);
		else
		{
			if(tag[x].first!=c)
			{
				printf("No");
				exit(0);
			}
			tag[x].second=max(tag[x].second,d);
		}
	}
	void dfs1(int v,int fa)
	{
		dep[v]=dep[fa]+1,f[v]=fa,siz[v]=1,rt[v]=rt[fa];
		for(auto u:E[v])
		{
			if(u==fa)continue;
			dfs1(u,v);
			siz[v]+=siz[u];
			if(siz[u]>siz[zson[v]])zson[v]=u;
		}
	}
	void dfs2(int v,int topp)
	{
		tp[v]=topp;
		if(zson[v])dfs2(zson[v],topp);
		for(auto u:E[v])
		{
			if(u==f[v]||u==zson[v])continue;
			dfs2(u,u);
		}
	}
	inline int lca(int x,int y)
	{
		while(tp[x]!=tp[y])
		{
			if(dep[tp[x]]<dep[tp[y]])y=f[tp[y]];
			else x=f[tp[x]];
		}
		return dep[x]<dep[y]?x:y;
	}
	void dfs3(int v,int fa)
	{
		for(auto u:E[v])
		{
			if(u==fa)continue;
			dfs3(u,v);
			if(tag[u].second>1)push(v,tag[u].first,tag[u].second-1);
		}
	}
}using namespace tree;
int main()
{
	scanf("%d %d %d",&n,&m,&q);
	int x,y,l;
	for(int i=1;i<=m;++i)
	{
		scanf("%d %d",&x,&y);
		add(x,y),add(y,x);
	}
	for(int i=1;i<=n;++i)
		if(!dfn[i])tarjan(i,0);
	for(int i=1;i<=n;++i)
		for(int j=head[i];j;j=bi[j].nxt)
		{
			x=bi[j].to;
			if(bl[i]!=bl[x])E[bl[i]].push_back(bl[x]);
		}
	for(int i=1;i<=n;++i)if(!dep[i])rt[0]=i,dfs1(i,0);
	for(int i=1;i<=n;++i)if(dep[i]==1)dfs2(i,i);
	for(int i=1;i<=q;++i)
	{
		scanf("%d %d",&x,&y);
		x=bl[x],y=bl[y];
		if(rt[x]!=rt[y])
		{
			printf("No");
			return 0;
		}
		l=lca(x,y);
		push(x,1,dep[x]-dep[l]);
		push(y,2,dep[y]-dep[l]);
	}
	for(int i=1;i<=n;++i)if(dep[i]==1)dfs3(i,0);
	printf("Yes");
	return 0;
}