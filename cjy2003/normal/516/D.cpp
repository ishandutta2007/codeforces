#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct bian
{
	int nxt,to,w;
}bi[200020];
int n,q,head[100010],num,f[100010],ans;
long long lim,dis[100010],mx1[100010],mx2[100010];
pair<long long,int>p[100010];
int siz[200020];
bool vis[100010];
int find(int x)
{
	if(x!=f[x])return f[x]=find(f[x]);
	return x;
}
inline void add(int from,int to,int w)
{
	bi[++num]=bian{head[from],to,w};
	head[from]=num;
}
void dfs1(int v,int fa)
{
	f[v]=fa;
	long long now;
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa)continue;
		dfs1(u,v);
		now=mx1[u]+bi[i].w;
		if(now>mx1[v])mx2[v]=mx1[v],mx1[v]=now;
		else if(now>mx2[v])mx2[v]=now;
	}
}
void dfs2(int v,long long up)
{
	dis[v]=max(up,mx1[v]);
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==f[v])continue;
		if(mx1[u]+bi[i].w==mx1[v])dfs2(u,max(up,mx2[v])+bi[i].w);
		else dfs2(u,max(up,mx1[v])+bi[i].w);
	}
}
void ins(int x)
{
	for(int i=head[x],y;i;i=bi[i].nxt)
	{
		y=bi[i].to;
		if(vis[y])siz[find(y)]+=siz[find(x)],f[find(x)]=find(y);
	}
}
void del(int x){--siz[find(x)];}
int main()
{
	scanf("%d",&n);
	int x,y,w;
	for(int i=1;i<n;++i)
	{
		scanf("%d %d %d",&x,&y,&w);
		add(x,y,w),add(y,x,w);
	}
	dfs1(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;++i)p[i]=make_pair(dis[i],i);
	sort(p+1,p+1+n);
	scanf("%d",&q);
	for(int t=1;t<=q;++t)
	{
		scanf("%lld",&lim);
		int r=n;ans=0;
		for(int i=1;i<=n;++i)siz[i]=1,f[i]=i,vis[i]=0;
		for(int i=n;i;--i)
		{
			while(p[r].first-p[i].first>lim)del(p[r].second),--r;
			ins(p[i].second);vis[p[i].second]=1;
			ans=max(ans,siz[find(p[i].second)]);
		}
		printf("%d\n",ans);
	}
	return 0;
}