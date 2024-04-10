#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct bian
{
	int nxt,to,w;
}bi[200020];
int n,q,head[100010],num,dis[100010],ans;
inline void add(int from,int to,int w){bi[++num]=bian{head[from],to,w};head[from]=num;}
void dfs(int v,int fa,int &x)
{
	if(dis[v]>dis[x])x=v;
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa)continue;
		dis[u]=dis[v]+bi[i].w;
		dfs(u,v,x);
	}
}
struct tree
{
	int rt,dis[100010],zson[100010],tp[100010],f[100010],dep[100010],ed[100010];
	int up[100010][18],mi[100010][18],cnt,sum[100010],id[100010];
	pair<int,int>l[100010];
	void dfs1(int v,int fa)
	{
		f[v]=fa;
		for(int i=head[v],u;i;i=bi[i].nxt)
		{
			u=bi[i].to;
			if(u==fa)continue;
			dep[u]=dep[v]+bi[i].w;
			dfs1(u,v);
			dis[u]+=bi[i].w;
			if(dis[u]>dis[v])dis[v]=dis[u],zson[v]=u;
		}
	}
	void dfs2(int v,int topp)
	{
		tp[v]=topp;
		if(v==topp)l[++cnt]=make_pair(dis[v],v);
		if(zson[v])dfs2(zson[v],topp),ed[v]=ed[zson[v]];
		else ed[v]=v;
		for(int i=head[v],u;i;i=bi[i].nxt)
		{
			u=bi[i].to;
			if(u==f[v]||u==zson[v])continue;
			up[u][0]=tp[v];
			dfs2(u,u);
		}
	}
	void dfs3(int v)
	{
		if(v==tp[v])
		{
			mi[v][0]=id[up[v][0]];
			for(int j=1;j<18;++j)
			{
				up[v][j]=up[up[v][j-1]][j-1];
				mi[v][j]=min(mi[v][j-1],mi[up[v][j-1]][j-1]);
			}
		}
		for(int i=head[v],u;i;i=bi[i].nxt)
		{
			u=bi[i].to;
			if(u==f[v])continue;
			dfs3(u);
		}
	}
	void init()
	{
		dfs1(rt,0);
		dfs2(rt,rt);
		sort(l+1,l+1+cnt);
		reverse(l+1,l+1+cnt);
		for(int i=1;i<=cnt;++i)id[l[i].second]=i,sum[i]=sum[i-1]+l[i].first;
		dfs3(rt);
	}
	int solve(int x,int y)
	{
		int res=sum[min(y,cnt)];
		if(id[tp[x]]<=y)return res;
		int p=tp[x];
		for(int i=17;~i;--i)
			if(mi[p][i]>y)p=up[p][i];
		return res+max(-dep[ed[f[p]]]+dep[ed[x]],dep[ed[x]]-dep[f[p]]-l[y].first);
	}
}t1,t2;
int main()
{
	scanf("%d %d",&n,&q);
	int x,y,w;
	for(int i=1;i<n;++i)
	{
		scanf("%d %d %d",&x,&y,&w);
		add(x,y,w),add(y,x,w);
	}
	dfs(1,0,t1.rt);
	dfs(t1.rt,0,t2.rt);
	t1.init();t2.init();
	while(q--)
	{
		scanf("%d %d",&x,&y);
		x=(x+ans-1)%n+1;y=(y+ans-1)%n+1;y=y*2-1;
		ans=max(t1.solve(x,y),t2.solve(x,y));
		printf("%d\n",ans);
	}
	return 0;
}