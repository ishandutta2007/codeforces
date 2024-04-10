#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define ll long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
mt19937 rnd(114514);
struct cmllrangwoyongnamespacedanshiwopianbuyongnamespace{
vector<pair<int,ll>> a[200003];
#define pb push_back
#define mp make_pair
#define fi first
#define se second
inline void insert(int id,int p,ll v)
{
	if(a[id].empty()) a[id].pb(mp(p,v));
	else a[id].pb(mp(p,v+a[id].back().se));
	return ;
}
const ll INF=1e18;
inline void modify(int id,int x,int y)
{
	auto it=lower_bound(a[id].begin(),a[id].end(),mp(x,0ll));
	it->fi=y;
	return ;
}
inline void swap(int id,int x)
{
	auto X=lower_bound(a[id].begin(),a[id].end(),mp(x,0ll));
	ll v0=0,v1=0,v2=0;
	if(X!=a[id].begin()) v0=prev(X)->second;
	v1=X->second,v2=next(X)->second,
	X->second=v0+v2-v1;
	return ;
}
inline pair<ll,int> query_(int x,int k)
{
	auto it=upper_bound(a[x].begin(),a[x].end(),mp(k,INF));
	if(it==a[x].begin()) return make_pair(0,-1);
	--it;
	return make_pair(it->se,it-a[x].begin());
}
inline pair<ll,int> query(int x,int l,int r)
{pair<ll,int> A=query_(x,r),B=query_(x,l);
return mp(A.fi-B.fi,A.se-B.se);}
}f0,f1;
int n=read(),m=read();
vector<pair<int,int>> e[200003];
ll dis[200003];
int dep[200003],a[400003],C,dfn[200003];
int lst[200003],l2[400003];
int st[400003][19];
inline void dfs2(int x,int fa)
{
	a[++C]=x,dfn[x]=C;
    for(auto [y,w]:e[x]) if(y!=fa)
        dep[y]=dep[x]+1,dis[y]=dis[x]+w,
        dfs2(y,x),a[++C]=x;
    lst[x]=C;
    return ;
}
inline int pmax(int x,int y){return dep[x]<dep[y]?x:y;}
inline void init(int x)
{
	st[x][0]=a[x];
	for(int i=1; i<=18; ++i) 
		st[x][i]=pmax(st[x][i-1],st[min(x+(1<<(i-1)),C)][i-1]);
	return ;
}
inline int LCA(int l,int r)
{
	l=dfn[l],r=dfn[r];
	if(l>r) swap(l,r);
	int d=l2[r-l+1];
	return pmax(st[l][d],st[min(r-(1<<d)+1,C)][d]);
}
int rt,tot,sz[200003],mx[200003],fa[200003];
bool vis[200003];
int qwq[200003];
inline void getrt(int u,int fa)
{
    sz[u]=1,mx[u]=0;
    for(auto [v,w]:e[u]) if(!vis[v]&&v!=fa)
        getrt(v,u),sz[u]+=sz[v],mx[u]=max(mx[u],sz[v]);
    mx[u]=max(mx[u],tot-sz[u]);
    if(mx[u]<mx[rt]) rt=u;
    return ;
}
inline void dfs1(int u)
{
	vis[u]=1;
	for(auto [v,w]:e[u]) if(!vis[v])
		tot=sz[v]-1,mx[rt=0]=1000000000,getrt(v,0),
		qwq[rt]=qwq[u]+1,fa[rt]=u,dfs1(rt);
	return ;
}
ll ans[200003],pre[200003];
int p[200003];
signed main()
{
	for(int i=2; i<=400000; ++i) l2[i]=l2[i>>1]+1;
	for(int i=1; i<=n; ++i) p[i]=read();
	for(int i=1,u,v,w; i<n; ++i)
		u=read(),v=read(),w=read(),
		e[u].push_back(make_pair(v,w)),
		e[v].push_back(make_pair(u,w));
	tot=n-1,mx[0]=1000000000,getrt(1,0),dfs1(rt),
	dep[1]=1,dfs2(1,0);
	for(int i=C; i>=1; --i) init(i);
	for(int i=1; i<=n; ++i) pre[i]=pre[i-1]+dis[p[i]];
	for(int i=1; i<=n; ++i)
	{
		for(int j=p[i]; j; j=fa[j])
			f1.insert(j,i,dis[LCA(p[i],j)]);
		for(int j=p[i]; fa[j]; j=fa[j])	
			f0.insert(j,i,dis[LCA(p[i],fa[j])]);
	}
	ll ans;
	for(int op,l,r,x,la=0; m--;)
	{
		op=read();
		if(op==1)
		{
			l=(read()^la)-1,r=read()^la,x=read()^la,
			ans=-f1.query(x,l,r).fi;
			for(int j=x; fa[j]; j=fa[j])
			{
				pair<ll,int> F1=f1.query(fa[j],l,r),F0=f0.query(j,l,r);
				if(dfn[fa[j]]<=dfn[x]&&dfn[x]<=lst[fa[j]]) ans-=F1.fi-F0.fi;
				else ans-=1ll*(F1.se-F0.se)*dis[LCA(x,fa[j])];
			}
			ans<<=1,ans+=pre[r]-pre[l],ans+=dis[x]*(r-l),
			printf("%lld\n",ans),la=ans&((1<<30)-1);
		}
		else
		{
			x=read()^la,pre[x]=pre[x]-dis[p[x]]+dis[p[x+1]];
			int A=p[x],B=p[x+1];
			while(qwq[A]>qwq[B])
				f1.modify(A,x,x+1),f0.modify(A,x,x+1),
				A=fa[A];
			while(qwq[A]<qwq[B])
				f1.modify(B,x+1,x),f0.modify(B,x+1,x),
				B=fa[B];
			while(A!=B)
				f1.modify(A,x,x+1),f0.modify(A,x,x+1),
				f1.modify(B,x+1,x),f0.modify(B,x+1,x),
				A=fa[A],B=fa[B];
			while(qwq[A])
				f1.swap(A,x),f0.swap(A,x),A=fa[A];
			f1.swap(A,x),swap(p[x],p[x+1]);
		}
	}
	return 0;
}