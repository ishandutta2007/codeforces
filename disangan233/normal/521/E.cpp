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
const int N=2e5+5;
int n,m,vis[N],ins[N],fa[N],dep[N],cx[N],cy[N],q[N],t;
vector<int>e[N];in void add(int u,int v) {e[u].pb(v),e[v].pb(u);}
in int lca(int u,int v)
{
	while(dep[u]>dep[v]) u=fa[u]; while(dep[v]>dep[u]) v=fa[v];
	while(u^v) u=fa[u],v=fa[v];return u;
}
in void print()
{
	write(t,' ');for(int i=1;i<=t;i++) write(q[i]," \n"[i==t]);
	t=0;
}
in void ed(int u,int v) {while(u^v) q[++t]=u,u=fa[u];q[++t]=v;}
in void solve(int a,int b,int c,int d)
{
	if(dep[b]>dep[d]) swap(a,c),swap(b,d);
	int p=lca(a,c);write("YES");
	ed(p,d);reverse(q+1,q+t+1);print();
	ed(d,b);ed(a,p);print();
	q[++t]=d;ed(c,p);print();ot();exit(0);
}
void dfs(int u)
{
	ins[u]=vis[u]=1;
	for(int v:e[u]) if(v^fa[u])
	{
		if(!vis[v]) dep[v]=dep[u]+1,fa[v]=u,dfs(v);
		else if(ins[v]) for(int p=u;p^v;p=fa[p])
		{
			if(cx[p]&&cy[p]) solve(cx[p],cy[p],u,v);
			else cx[p]=u,cy[p]=v;
		}
	}
	ins[u]=0;
}
int main()
{
	n=read(),m=read();for(int i=1;i<=m;i++) add(read(),read());
	for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
	write("NO");
	return ot(),0;
}
//Author: disangan233