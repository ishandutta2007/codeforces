#pragma GCC optimize(2,3,"Ofast","unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
namespace fast_io
{
    char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0,ny;
    in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
    in ll read()
    {
        ll x=0;ny=1;while(nc=gc(),(nc<48||nc>57)&&nc!=EOF)if(nc==45)ny=-1;Bi=1;if(nc<0)return nc;
        x=nc-48;while(nc=gc(),47<nc&&nc<58&&nc!=EOF)x=(x<<3)+(x<<1)+(nc^48),Bi++;return x*ny;
    }
    in db gf() {int a=read(),y=ny,b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi)*y:a);}
    in int gs(char *s) {char c,*t=s;while(c=gc(),c<32);*s++=c;while(c=gc(),c>32)*s++=c;return s-t;}
    in void ot() {fwrite(sr,1,C+1,stdout);C=-1;}
    in void flush() {if(C>1<<22) ot();}
    template <typename T>
    in void write(T x,char t)
    {
        int y=0;if(x<0)y=1,x=-x;while(z[++Z]=x%10+48,x/=10);
        if(y)z[++Z]='-';while(sr[++C]=z[Z],--Z);sr[++C]=t;flush();
    }
    in void write(char *s) {int l=strlen(s);for(int i=0;i<l;i++)sr[++C]=*s++;sr[++C]='\n';flush();}
};
using namespace fast_io;
#define pb push_back
const int N=2e5+5;
int n,q,tim,dfn[N],fa[N],dep[N],siz[N],son[N],top[N],s[N],t,v[N],w[N];
vector<int>e[N],g[N];in void add(int u,int v) {e[u].pb(v),e[v].pb(u);}
void dfs1(int u)
{
	siz[u]=1;dfn[u]=++tim;
	for(int v:e[u]) if(v^fa[u]) {dep[v]=dep[fa[v]=u]+1,dfs1(v),siz[u]+=siz[v];if(siz[v]>siz[son[u]]) son[u]=v;}
}
void dfs2(int u,int tp)
{
	top[u]=tp;if(son[u]) dfs2(son[u],tp);
	for(int v:e[u]) if(v^fa[u]&&v^son[u]) dfs2(v,v);
}
in int lca(int u,int v)
{
	for(;top[u]^top[v];u=fa[top[u]]) if(dep[top[u]]<dep[top[v]]) swap(u,v);
	return dep[u]<dep[v]?u:v;
}
in void svt(vector<int>&p)
{
	sort(p.begin(),p.end(),[](int a,int b){return dfn[a]<dfn[b];});
	p.erase(unique(p.begin(),p.end()),p.end());vector<int>q=p;
	for(int u:p)
	{
		int d=lca(u,s[t]);
		if(d^s[t])
		{
			while(t&&dep[s[t-1]]>=dep[d]) g[s[t]].pb(s[t-1]),g[s[t-1]].pb(s[t]),t--;
			if(s[t]^d) g[s[t]].pb(d),g[d].pb(s[t]),s[t]=d,q.pb(d);
		}
		s[++t]=u;
	}
	if(t) while(--t) g[s[t]].pb(s[t+1]),g[s[t+1]].pb(s[t]);p=q;
}
struct pii{
	int d,i,x,r;in pii() {}
	in pii(int d,int i,int x) : d(d),i(i),x(x) {r=d?(d-1)/w[x]:-1;}
	in bool operator<(pii x) const {return r==x.r?i<x.i:r<x.r;}
	in pii operator-() const {pii x=*this;x.i*=-1,x.r*=-1;return x;}
}f[N];
in void dijkstra(vector<int>a,vector<int>b,vector<int>p)
{
	priority_queue<pair<pii,int>>q;for(int x:p) f[x].r=f[x].i=n,v[x]=0;
	for(int i=0;i<a.size();i++) f[a[i]]=pii(0,i,a[i]),q.push(make_pair(-f[a[i]],a[i]));
	while(q.size())
	{
		int u=q.top().second;q.pop();if(v[u]) continue; v[u]=1;
		for(int v:g[u])
		{
			pii t=pii(f[u].d+abs(dep[u]-dep[v]),f[u].i,f[u].x);
			if(t<f[v]) f[v]=t,q.push(make_pair(-f[v],v));
		}
	}
	for(int x:b) write(f[x].i+1,' ');sr[++C]='\n';
}
int main()
{
	n=read();for(int i=1;i<n;i++) add(read(),read());
	dep[1]=1;dfs1(1);dfs2(1,1);q=read();
	while(q--)
	{
		int m=read(),k=read();vector<int>a,b,p;
		for(int i=1,x;i<=m;i++) a.pb(x=read()),p.pb(x),w[x]=read();
		for(int i=1,x;i<=k;i++) b.pb(x=read()),p.pb(x);
		svt(p);dijkstra(a,b,p);for(int x:p) g[x].clear();
	}
	return ot(),0;
}
//Author: disangan233
//In my dream's scene,I can see the everything that in Cyaegha.