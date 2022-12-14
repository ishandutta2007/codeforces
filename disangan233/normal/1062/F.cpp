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
const int N=3e5+5;
int n,m,ans,vis[N],d[N],f[N],q[N];vector<int>e[N];
struct did{int u,v;}ed[N];
in void add(int u,int v) {e[u].pb(v),d[v]++;}
in void solve(int p,int u,int s)
{
	int op=0;for(int v:e[u]) if(d[v]==1) {op=1;break;}
	op?vis[p]=1:f[p]+=s; 
}
in void topsort()
{
	int l=0,r=0;for(int i=1;i<=n;i++) if(!d[i]) q[++r]=i;
	while(l<r)
	{
		int u=q[++l];if(l==r) f[u]+=n-r;if(l+1==r) solve(u,q[r],n-r);
		for(int v:e[u]) if(!(--d[v])) q[++r]=v;
	}
}
int main()
{
	n=read(),m=read();for(int i=1,u,v;i<=m;i++) ed[i]={read(),read()},add(ed[i].u,ed[i].v);
	topsort();for(int i=1;i<=n;i++) e[i].clear();
	for(int i=1;i<=m;i++) add(ed[i].v,ed[i].u);
	topsort();for(int i=1;i<=n;i++) if(!vis[i]&&f[i]>=n-2) ans++;
	write(ans,'\n');
	return ot(),0;
}
//Author: disangan233