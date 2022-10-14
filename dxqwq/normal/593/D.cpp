//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
inline ll read(){
   ll s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const ll INF=0x3f3f3f3f3f3f3f3f;
vector<pair<int,ll>> e[200003];
int dep[200003],sz[200003],son[200003],top[200003],dfn[200003],tot;
ll val_[200003],val[200003];
int eu[200003],ev[200003],f[200003];
inline void dfs1(int x,int fa)
{
	f[x]=fa,sz[x]=1;
    for(auto p:e[x]) if(p.first!=fa)
    {
    	int y=p.first;ll w=p.second;
        dep[y]=dep[x]+1,val_[y]=w,dfs1(y,x),sz[x]+=sz[y];
        (sz[y]>sz[son[x]])&&(son[x]=y);
    }
}
inline void dfs2(int x,int tp)
{
    top[x]=tp,val[dfn[x]=++tot]=val_[x];
    if(son[x]) dfs2(son[x],tp);
    for(auto p:e[x]) if(!dfn[p.first])
    {
    	int y=p.first;
        dfs2(y,y);
	}
}
ll a[1100003];
inline void build(int l,int r,int x)
{
    if(l==r) 
    {
    	a[x]=val[l];
    	return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,x<<1),build(mid+1,r,(x<<1)+1);
    __int128 g=(__int128)a[x<<1]*a[(x<<1)+1];
    a[x]=g>INF?0:g;
    return ;
}
inline void update(int nl,int nr,int pos,ll k,int x=1)
{
    if(nl==nr)
    {
        a[x]=k;
        return ;
    }
    int mid=(nl+nr)>>1;
	if(pos<=mid) update(nl,mid,pos,k,x<<1);
	else update(mid+1,nr,pos,k,(x<<1)+1);
    __int128 g=(__int128)a[x<<1]*a[(x<<1)+1];
    a[x]=g>INF?0:g;
    return ;
}
inline ll query(int nl,int nr,int l,int r,int x=1)
{
    if(nr<l||r<nl) return 1;
    if(l<=nl&&nr<=r) return a[x];
    int mid=(nl+nr)>>1;
    __int128 g=(__int128)query(nl,mid,l,r,x<<1)*query(mid+1,nr,l,r,(x<<1)+1);
    return g>INF?0:g;
}
int n=read(),m=read();
inline ll prod(int x,int y)
{
	__int128 res=1;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])
		{
			res*=query(1,n,dfn[top[y]],dfn[y],1),
			res=res>INF?0:res,
			y=f[top[y]];
		}
		else
		{
			res*=query(1,n,dfn[top[x]],dfn[x],1),
			res=res>INF?0:res,
			x=f[top[x]];
		}
	}
	if(dfn[x]>dfn[y]) swap(x,y);
	if(dfn[x]!=dfn[y]) 
		res*=query(1,n,dfn[x]+1,dfn[y],1),
		res=res>INF?0:res;
	return res;
}
signed main()
{
	ll x,y,w;
	for(int i=1; i<n; ++i)
		eu[i]=read(),ev[i]=read(),
		w=read(),e[eu[i]].pb(mp(ev[i],w)),e[ev[i]].pb(mp(eu[i],w));
	dfs1(1,1),dfs2(1,1),build(1,n,1);
	for(int op; m--;)
	{
		op=read(),x=read(),y=read();
		if(op==1)
		{
			ll w=read(),g=prod(x,y);
			if(g==0) puts("0"); else printf("%lld\n",w/g); 
		}
		else
		{
			int id=(dep[eu[x]]>dep[ev[x]])?dfn[eu[x]]:dfn[ev[x]];
			update(1,n,id,y,1);
		}
	}
	return 0;
}