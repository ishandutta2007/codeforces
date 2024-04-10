#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
#define ld long db
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
}
using namespace fast_io;   
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
const int N=1e5+5;
int n,tot,rt,mn,krt,Rt,Len,h[N],siz[N],d[N],du[N];
vector<int>e[N],g[N];in void add(int u,int v) {e[u].pb(v),e[v].pb(u);du[u]++,du[v]++;}
in void get(int u,int fa)
{
	siz[u]=1;int bl=0;
	for(int v:e[u]) if(v^fa) get(v,u),bl=max(bl,siz[v]),siz[u]+=siz[v];
	bl=max(bl,n-siz[u]);if(bl<mn) mn=bl,rt=u;
}
in void dfs(int u,int fa) {d[u]=d[fa]+1;for(int v:e[u]) if(v^fa) dfs(v,u);}
in void check(int u) 
{
	dfs(u,0);
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<=n;i++) g[d[i]].pb(i);
	for(int i=1;i<=n;i++) for(int j=1;j<g[i].size();j++) if(du[g[i][j]]^du[g[i][0]]) return;
	write(u,'\n');ot();exit(0);
}
in int ask(int u,int fa) 
{
	if(du[u]>2) return 0; if(du[u]==1) return krt=u,1;
	for(int v:e[u]) if(v^fa) {int res=ask(v,u);return !res?0:res+1;}
}
int main()
{
	n=read();for(int i=1;i<n;i++) add(read(),read());
	mn=1e9,get(1,0);check(rt);
	for(int v:e[rt]) 
	{
		int len=ask(v,rt);if(!len) continue;
		if(Rt&&len^Len) {check(krt);break;}
		if(!Rt) Rt=krt,Len=len,check(krt);
	}
	write("-1");
	return ot(),0;
}
//Author: disangan233