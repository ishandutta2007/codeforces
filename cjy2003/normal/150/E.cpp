#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct bian
{
	int nxt,to,w;
}bi[200020];
int n,L,U,head[100010],num;
inline void add(int from,int to,int w){bi[++num]=bian{head[from],to,w};head[from]=num;}
int dis[100010],zson[100010],p[100010],tot,fw[100010];
void dfs1(int v,int fa)
{
	dis[v]=1;
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa)continue;
		fw[u]=bi[i].w;
		dfs1(u,v);
		if(dis[u]>=dis[v])dis[v]=dis[u]+1,zson[v]=u;
	}
}
void dfs2(int v,int fa)
{
	if(zson[v])
	{
		p[zson[v]]=p[v]+1;
		dfs2(zson[v],v);
	}
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa||u==zson[v])continue;
		p[u]=tot;tot+=dis[u];
		dfs2(u,v);
	}
}
int C;
bool flag;
int px,py;
int mx[400040],ad[400040],mxp[400040];
void build(int k,int l,int r)
{
	mx[k]=0xc0c0c0c0;
	if(l==r)return;
	build(k<<1,l,(l+r)>>1);
	build(k<<1|1,((l+r)>>1)+1,r);
}
void add(int k,int l,int r,int ll,int rr,int w)
{
	if(l>rr||r<ll)return ;
	if(l>=ll&&r<=rr)
	{
		mx[k]+=w;ad[k]+=w;
		return ;
	}
	add(k<<1,l,(l+r)>>1,ll,rr,w);
	add(k<<1|1,((l+r)>>1)+1,r,ll,rr,w);
	mx[k]=max(mx[k<<1],mx[k<<1|1])+ad[k];
	if(mx[k<<1]>=mx[k<<1|1])mxp[k]=mxp[k<<1];
	else mxp[k]=mxp[k<<1|1];
}
void upd(int k,int l,int r,int p,pair<int,int>w)
{
	if(l==r)
	{
		if(w.first>mx[k])mx[k]=w.first,mxp[k]=w.second;
		return ;
	}
	w.first-=ad[k];
	if(p<=(l+r)>>1)upd(k<<1,l,(l+r)>>1,p,w);
	else upd(k<<1|1,((l+r)>>1)+1,r,p,w);
	mx[k]=max(mx[k<<1],mx[k<<1|1])+ad[k];
	if(mx[k<<1]>=mx[k<<1|1])mxp[k]=mxp[k<<1];
	else mxp[k]=mxp[k<<1|1];
}
pair<int,int>query(int k,int l,int r,int ll,int rr)
{
	if(l>rr||r<ll)return make_pair(0xc0c0c0c0,l);
	if(l>=ll&&r<=rr)return make_pair(mx[k],mxp[k]);
	auto s=max(query(k<<1,l,(l+r)>>1,ll,rr),query(k<<1|1,((l+r)>>1)+1,r,ll,rr));
	s.first+=ad[k];
	return s;
}
pair<int,int>cur[100010];
void dfs3(int v,int fa)
{
	if(zson[v])
	{
		dfs3(zson[v],v);
		if(fw[zson[v]]>=C)add(1,1,n,p[v]+2,p[v]+dis[v],1);
		else add(1,1,n,p[v]+2,p[v]+dis[v],-1);
	}
	upd(1,1,n,p[v]+1,make_pair(0,v));
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa||u==zson[v])continue;
		dfs3(u,v);
		int uw=fw[u]>=C?1:-1;
		for(int j=1;j<=dis[u];++j)
		{
			cur[j]=query(1,1,n,p[u]+j,p[u]+j);cur[j].first+=uw;
			int l=max(1,L+1-j),r=min(dis[v],U+1-j);
			auto s=query(1,1,n,p[v]+l,p[v]+r);
			if(l<=r&&cur[j].first+s.first>=0)px=s.second,py=cur[j].second,flag=1;
		}
		for(int j=1;j<=dis[u];++j)upd(1,1,n,p[v]+1+j,cur[j]);
	}
	int l=L+1,r=min(U+1,dis[v]);
	auto s=query(1,1,n,p[v]+l,p[v]+r);
	if(l<=r&&s.first>=0)px=v,py=s.second,flag=1;
}
bool check()
{
	flag=0;
	build(1,1,n);
	dfs3(1,0);
	return flag;
}
int main()
{
	scanf("%d %d %d",&n,&L,&U);
	for(int i=1,x,y,w;i<n;++i)
	{
		scanf("%d %d %d",&x,&y,&w);
		add(x,y,w),add(y,x,w);
	}
	dfs1(1,0);
	tot=dis[1];
	dfs2(1,0);
	check();
	int l=0,r=1000000000,mid;
	while(l<r)
	{
		mid=(l+r+1)/2;C=mid;
		if(check())l=mid;
		else r=mid-1;
	}
	printf("%d %d",px,py);
	return 0;
}