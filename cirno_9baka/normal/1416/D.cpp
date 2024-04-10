#include<bits/stdc++.h>
using namespace std;
const int N=500005,E=2000005;
int n,i,m,q,t[N],v[N],p[N],f[N],w[N],k,dfn[N],lat[N],mx[N*4],mxx[N*4],tot,lazy[N*4],c[N][2],qu[N];
struct str{
	int u,v,t;
}g[N];
bool cmp(str a,str b)
{
	return a.t<b.t;
}
int Find(int x)
{
	return f[x]?f[x]=Find(f[x]):x;
}
void dfs(int i)
{
	dfn[i]=k+1;
	if(c[i][0])
	{
		dfs(c[i][0]);
		dfs(c[i][1]);
	}
	else
		++k;
	lat[i]=k;
}
void modify(int i,int l,int r,int x,int y)
{
	if(l==r)
	{
		mx[i]=y;
		mxx[i]=l;
		return;
	}
	int mid=l+r>>1;
	if(mid>=x)
		modify(i<<1,l,mid,x,y);
	else
		modify(i<<1|1,mid+1,r,x,y);
	mx[i]=max(mx[i<<1],mx[i<<1|1]);
	mxx[i]=(mx[i]==mx[i<<1]?mxx[i<<1]:mxx[i<<1|1]);
}
int qmx,qmxx;
void Query(int i,int l,int r,int ll,int rr)
{
	if(l>=ll&&r<=rr)
	{
		if(qmx<=mx[i])
		{
			qmx=mx[i];
			qmxx=mxx[i];
		}
		return;
	}
	int mid=l+r>>1;
	if(mid>=ll)
		Query(i<<1,l,mid,ll,rr);
	if(mid<rr)
		Query(i<<1|1,mid+1,r,ll,rr);
}
void pd(int x)
{
	if(lazy[x]!=0)
	{
		lazy[x<<1|1]=lazy[x<<1]=lazy[x];
		lazy[x]=0;
	}
}
void modify2(int i,int l,int r,int ll,int rr,int x)
{
	if(l>=ll&&r<=rr)
	{
		lazy[i]=x;
		return;
	}
	pd(i);
	int mid=l+r>>1;
	if(mid>=ll)
		modify2(i<<1,l,mid,ll,rr,x);
	if(mid<rr)
		modify2(i<<1|1,mid+1,r,ll,rr,x);
}
int Query2(int i,int l,int r,int x)
{
	if(l==r)
		return lazy[i];
	int mid=l+r>>1;
	pd(i);
	if(mid>=x)
		return Query2(i<<1,l,mid,x);
	else
		return Query2(i<<1|1,mid+1,r,x);
}
int main()
{
	scanf("%d %d %d",&n,&m,&q);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&p[i]);
		w[i]=i;
	}
	for(i=1;i<=m;++i)
		scanf("%d %d",&g[i].u,&g[i].v);
	for(i=1;i<=q;++i)
	{
		scanf("%d %d",&t[i],&v[i]);
		if(t[i]==2)
			g[v[i]].t=q-i+1;
	}
	sort(g+1,g+1+m,cmp);
	tot=n;
	for(i=1;i<=m;++i)
	{
		int x=Find(g[i].u),y=Find(g[i].v);
		if(x!=y)
		{
			c[tot+1][0]=w[x];
			c[tot+1][1]=w[y];
			f[x]=y;
			w[y]=++tot;
			qu[g[i].t]=tot;
		}
	}
	for(i=tot;i>=1;--i)
		if(!dfn[i])
		{
			dfs(i);
			modify2(1,1,n,dfn[i],lat[i],i);
		}
	for(i=1;i<=n;++i)
		modify(1,1,n,dfn[i],p[i]);
	for(i=1;i<=q;++i)
		if(t[i]==2)
		{
			int x=qu[q-i+1];
			if(x)
			{
				modify2(1,1,n,dfn[c[x][0]],lat[c[x][0]],c[x][0]);
				modify2(1,1,n,dfn[c[x][1]],lat[c[x][1]],c[x][1]);
			}
		}
		else
		{
			int x=Query2(1,1,n,dfn[v[i]]);
			qmx=0;
			Query(1,1,n,dfn[x],lat[x]);
			printf("%d\n",qmx);
			modify(1,1,n,qmxx,0);
		}
}