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
#define fi first
#define se second
const int N=3e5+5;
int n,m,k,s,ans;
vector<pair<int,int>>e[N];in void add(int u,int v,int w) {s+=w;e[u].emplace_back(v,w),e[v].emplace_back(u,w);}
struct T
{
	int rt,f[N][21],p[N][21],d[N],len[N],son[N],top[N],rak[N],l[N],r[N],s[N],t;
	void dfs1(int u,int fa)
	{
		for(auto x:e[u]) if(x.fi^fa) d[x.fi]=d[u]+x.se,dfs1(x.fi,u);
	}
	void dfs2(int u)
	{
		for(auto x:e[u]) if(x.fi^p[u][0])
		{
			int v=x.fi;p[v][0]=u;f[v][0]=x.se;
			for(int i=1;p[v][i-1];i++) p[v][i]=p[p[v][i-1]][i-1],f[v][i]=f[v][i-1]+f[p[v][i-1]][i-1];
			d[v]=d[u]+x.se;dfs2(v);if(len[u]<len[v]+x.se) len[u]=len[son[u]=v]+x.se;
		}
		for(auto x:e[u]) if(x.fi^p[u][0]&&x.fi^son[u]) s[l[++t]=x.fi]=len[x.fi]+x.se;
	}
	in void build(int x)
	{
		dfs1(rt=x,0);for(int i=1;i<=n;i++) if(d[i]>d[rt]) rt=i;
		d[rt]=0;dfs2(rt);s[l[++t]=rt]=len[rt];
		sort(l+1,l+t+1,[&](int i,int j){return s[i]>s[j];});
		for(int i=1;i<=t;i++) r[i]=r[i-1]+s[l[i]];
		for(int i=1;i<=t;i++)
		{
			int u=l[i],p=u;
			while(u) top[u]=p,rak[u]=i,u=son[u];
		}
	}
	in int ask1(int u,int v)
	{
		int l=len[u];
		for(int i=20;~i;i--) if(rak[p[u][i]]>=v) l+=f[u][i],u=p[u][i];
		return r[v-1]+l+f[u][0];
	} 
	in int ask2(int u,int v)
	{
		int l=len[u];
		for(int i=20;~i;i--) if(rak[p[u][i]]>v) l+=f[u][i],u=p[u][i];
		return r[v]-len[p[u][0]]+l+f[u][0];
	} 
	in int ask(int u,int v) {return v=2*v-1,rak[u]<=v?r[v]:max(ask1(u,v),ask2(u,v));}
}t[2];
int main()
{
	n=read(),m=read();
	for(int i=1,u,v;i<n;i++) u=read(),v=read(),add(u,v,read());
	for(int i=1;i<=n;i++) k+=e[i].size()==1u;
	t[0].build(1),t[1].build(t[0].rt);
	while(m--)
	{
		int u=(read()+ans-1)%n+1,v=(read()+ans-1)%n+1;
		write(ans=2*v>=k?s:max(t[0].ask(u,v),t[1].ask(u,v)),'\n');
	}
	return ot(),0;
}
//Author: disangan233