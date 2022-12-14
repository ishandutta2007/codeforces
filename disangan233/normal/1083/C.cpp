#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0,ny;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in int read()
	{
		int x=0;ny=1;while(nc=gc(),(nc<48||nc>57)&&nc!=EOF)if(nc==45)ny=-1;Bi=1;if(nc<0)return nc;
		x=nc-48;while(nc=gc(),47<nc&&nc<58&&nc!=EOF)x=(x<<3)+(x<<1)+(nc^48),Bi++;return x*ny;
	}
	in db gf() {int a=read(),y=ny,b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi)*y:a);}
	in int gs(char *s) {char c,*t=s;while(c=gc(),c<=32);*s++=c;while(c=gc(),c>32)*s++=c;return s-t;}
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
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define mid ((l+r)>>1)
const int N=2e5+5;
int n,m,tim,c[N],rev[N],d[N],siz[N],son[N],top[N],id[N],fa[N];
vector<int>e[N];in void add(int u,int v) {e[u].pb(v),e[v].pb(u);} 
struct did{int u,v,p;}t[N<<2];
void dfs1(int u)
{
	siz[u]=1;
	for(int v:e[u]) if(v^fa[u]) d[v]=d[fa[v]=u]+1,dfs1(v),siz[u]+=siz[v],siz[v]>siz[son[u]]?son[u]=v:0;
}
void dfs2(int u,int tp)
{
	top[u]=tp,id[u]=++tim;if(son[u]) dfs2(son[u],tp);
	for(int v:e[u]) if(!top[v]) dfs2(v,v);
}
in int lca(int u,int v)
{
	for(;top[u]^top[v];u=fa[top[u]]) if(d[top[u]]<d[top[v]]) swap(u,v);
	return d[u]<d[v]?u:v;
}
in bool I(int u,int v) {return id[v]>=id[u]&&id[v]<=id[u]+siz[u]-1;}
in bool check(int u,int v,int x,int y) {int z=lca(u,v);return I(z,x)&&I(z,y)&&(I(x,u)||I(x,v))&&(I(y,u)||I(y,v));}
in did merge(did x,did y)
{
	if(x.u<0&&x.v<0&&!x.p) return y;
	if(!x.p||!y.p) return {0,0,0};
	if(check(x.u,x.v,y.u,y.v)) return {x.u,x.v,1};
	if(check(x.u,y.v,y.u,x.v)) return {x.u,y.v,1};
	if(check(y.u,y.v,x.u,x.v)) return {y.u,y.v,1};
	if(check(x.u,y.u,x.v,y.v)) return {x.u,y.u,1};
	if(check(x.v,y.v,x.u,y.u)) return {x.v,y.v,1};
	if(check(x.v,y.u,x.u,y.v)) return {x.v,y.u,1};
	return {0,0,0};
}
in void up(int x) {t[x]=merge(t[ls(x)],t[rs(x)]);}
void build(int p,int l,int r)
{
	if(l==r) return t[p]={rev[l],rev[l],1},void();
	build(ls(p),l,mid),build(rs(p),mid+1,r),up(p);
}
void add(int p,int l,int r,int x)
{
	if(l==r) return t[p]={rev[l],rev[l],1},void();
	x<=mid?add(ls(p),l,mid,x):add(rs(p),mid+1,r,x);up(p);
}
int ask(int p,int l,int r,did x)
{
	if(l==r) return l;did T=merge(x,t[ls(p)]);
	return T.p?ask(rs(p),mid+1,r,T):ask(ls(p),l,mid,x);
}
int main()
{
	n=read();for(int i=1;i<=n;i++) rev[c[i]=read()+1]=i;
	for(int i=2;i<=n;i++) add(i,read());
	dfs1(1),dfs2(1,1),build(1,1,n),m=read();
	while(m--)
	{
		int op=read(),u,v;
		if(op==1) u=read(),v=read(),swap(rev[c[u]],rev[c[v]]),swap(c[u],c[v]),add(1,1,n,c[u]),add(1,1,n,c[v]);
		else write(t[1].p?n:ask(1,1,n,{-1,-1,0})-1,'\n');
	}
	return ot(),0;
}
//Author: disangan233