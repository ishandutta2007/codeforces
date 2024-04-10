#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct bian
{
	int to,nxt;
	bool fg;
}bi[1000010];
struct b1
{
	int x,y,w;
	friend bool operator < (b1 a,b1 b)
	{
		return a.w<b.w;
	}
}b[500050];
int n,k,m,head[500010],num;
int depth[500010],f[500010],id[500010],idnum,siz[500010],zson[500010],tp[500010],dy[500050];
int maxi[2000040],ans[500050];
int bf[500050];
bool bj[500050],tj[500050];
int find(int x)
{
	if(bf[x]!=x)return bf[x]=find(bf[x]);
	return x;
}
void add(int from,int to,bool fg)
{
	bi[++num].nxt=head[from];
	head[from]=num;
	bi[num].to=to;
	bi[num].fg=fg;
}
void dfs1(int v,int fa)
{
	siz[v]=1;
	int u;
	for(int i=head[v];i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa)continue;
		f[u]=v,depth[u]=depth[v]+1;
		tj[u]=bi[i].fg;
		dfs1(u,v);
		siz[v]+=siz[u];
		if(siz[u]>siz[zson[v]])zson[v]=u;	
	}
}
void dfs2(int v,int topp)
{
	id[v]=++idnum;tp[v]=topp;dy[idnum]=v;
	if(zson[v])dfs2(zson[v],topp);
	int u;
	for(int i=head[v];i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==f[v]||u==zson[v])continue;
		dfs2(u,u);	
	}
}
void change(int k,int l,int r,int ll,int rr,int w)
{
	if(l>rr||r<ll)return ;
	if(l>=ll&&r<=rr)
	{
		maxi[k]=min(maxi[k],w);
		return ;	
	}
	change(k<<1,l,l+r>>1,ll,rr,w);
	change(k<<1|1,(l+r>>1)+1,r,ll,rr,w);
}
void upd(int x,int y,int w)
{
	while(tp[x]!=tp[y])
	{
		if(depth[tp[x]]<depth[tp[y]])
		{
			change(1,1,n,id[tp[y]],id[y],w);
			y=f[tp[y]];
		}	
		else
		{
			change(1,1,n,id[tp[x]],id[x],w);
			x=f[tp[x]];	
		}
	}
	if(depth[x]<depth[y])change(1,1,n,id[x]+1,id[y],w);
	else change(1,1,n,id[y]+1,id[x],w);
}
void pushdown(int k,int l,int r)
{
	if(l==r)
	{
		ans[dy[l]]=maxi[k];
		return ;	
	}
	maxi[k<<1]=min(maxi[k<<1],maxi[k]);
	maxi[k<<1|1]=min(maxi[k<<1|1],maxi[k]);
	pushdown(k<<1,l,l+r>>1);
	pushdown(k<<1|1,(l+r>>1)+1,r);
}
int main()
{
	scanf("%d %d %d",&n,&k,&m);
	int x,y;
	for(int i=1;i<=n;++i)
		bf[i]=i;
	for(int i=1;i<=k;++i)
	{
		scanf("%d %d",&x,&y);
		add(x,y,1),add(y,x,1);
		bf[find(y)]=find(x);
	}
	for(int i=1;i<=m;++i)
		scanf("%d %d %d",&b[i].x,&b[i].y,&b[i].w);
	sort(b+1,b+1+m);
	for(int i=1;i<=m;++i)
		if(find(b[i].x)!=find(b[i].y))
		{
			bf[bf[b[i].x]]=bf[b[i].y];
			add(b[i].x,b[i].y,0);add(b[i].y,b[i].x,0);bj[i]=1;
		}
	for(int i=1;i<=n;++i)
		if(!depth[i])
		{
			depth[i]=1;
			dfs1(i,0);	
		}
	for(int i=1;i<=n;++i)
		if(depth[i]==1)dfs2(i,i);
	memset(maxi,0x3f,sizeof(maxi));
	for(int i=1;i<=m;++i)
		if(!bj[i])upd(b[i].x,b[i].y,b[i].w);
	pushdown(1,1,n);
//	for(int i=1;i<=n;++i)
//		printf("%d ",ans[i]);
	long long tans=0;
	for(int i=1;i<=n;++i)
		if(tj[i])
		{
			if(ans[i]==0x3f3f3f3f)
			{
				printf("-1");
				return 0;	
			}
			tans+=ans[i];
		}
	printf("%I64d",tans);
	return 0;
}