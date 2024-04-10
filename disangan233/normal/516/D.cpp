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
const int N=1e5+5;
int n,q,cnt,vis[N],h[N],to[N<<1],w[N<<1],nxt[N<<1],fa[N],siz[N],ans;ll m,f[N][2],g[N];
in void Add(int u,int v,int wi) {nxt[++cnt]=h[u],to[cnt]=v,w[cnt]=wi,h[u]=cnt;}
in void add(int u,int v,int w) {Add(u,v,w);Add(v,u,w);}
void dfs1(int u,int fa)
{
	for(int i=h[u],v;v=to[i],i;i=nxt[i]) if(v^fa)
	{
		dfs1(v,u);ll nw=f[v][0]+w[i];
		if(nw>f[u][1]) f[u][1]=nw; if(nw>f[u][0]) swap(f[u][0],f[u][1]);
	}
}
void dfs2(int u,int fa)
{
	for(int i=h[u],v;v=to[i],i;i=nxt[i]) if(v^fa)
	g[v]=max(g[u],f[v][0]+w[i]==f[u][0]?f[u][1]:f[u][0])+w[i],dfs2(v,u);
}
int find(int x) {return fa[x]^x?fa[x]=find(fa[x]):x;}
in void merge(int u,int v)
{
	u=find(u),v=find(v);if(u==v) return;
	if(siz[u]>siz[v]) swap(u,v);fa[u]=v;siz[v]+=siz[u];ans=max(ans,siz[v]);
}
struct pii{ll a;int b;in bool operator<(pii x)const{return a^x.a?a<x.a:b<x.b;}}p[N];
int main()
{
	n=read();
	for(int i=1,u,v;i<n;i++) u=read(),v=read(),add(u,v,read());
	dfs1(1,0);dfs2(1,0);for(int i=1;i<=n;i++) p[i]={max(f[i][0],g[i]),i};
	sort(p+1,p+n+1);reverse(p+1,p+n+1);q=read();
	while(q--)
	{
		m=read(),ans=1;for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1,vis[i]=0;
		for(int l=1,r=0;l<=n;l++)
		{
			while(r<n&&p[l].a-p[r+1].a<=m)
			{
				int u=p[++r].b;vis[u]=1;
				for(int i=h[u],v;v=to[i],i;i=nxt[i]) if(vis[v]) merge(u,v);
			}
			int t=find(p[l].b);siz[t]--;vis[t]=0;
		}
		write(ans,'\n');
	}
	return ot(),0;
}
//Author: disangan233