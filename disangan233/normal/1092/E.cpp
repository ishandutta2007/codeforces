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
	in ll read()
	{
		ll x=0;ny=1;while(nc=gc(),(nc<48||nc>57)&&nc!=EOF)if(nc==45)ny=-1;Bi=1;if(nc<0)return nc;
		x=nc-48;while(nc=gc(),47<nc&&nc<58&&nc!=EOF)x=(x<<3)+(x<<1)+(nc^48),Bi++;return x*ny;
	}
	in db find() {int a=read(),y=ny,b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi)*y:a);}
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
const int N=1e3+5;
int n,m,mx,rt,fa[N],Fa[N];vector<pii>vec;
int find(int x) {return Fa[x]^x?Fa[x]=find(Fa[x]):x;}
vector<int>e[N],E[N];in void add(int u,int v,int op=1) {e[u].pb(v),e[v].pb(u);if(op)Fa[find(u)]=find(v);}
void dfs(int u,int p,int d) {fa[u]=p;if(d>mx) mx=d,rt=u;for(int v:e[u]) if(v^p) dfs(v,u,d+1);}
in pii ask(int u)
{
	mx=0;dfs(u,0,1);mx=0;dfs(rt,0,1);
	int p=rt;for(int i=1;i<=mx>>1;i++) p=fa[p];return {mx-1,p};
}
in int check(int u)
{
    for(int i=1;i<=n;i++) {E[i].clear();for(int x:e[i]) E[i].pb(x);}
    for(auto [l,v]:vec) if(find(u)^find(v)) add(u,v,0);
	int ans=ask(u).fi;for(int i=1;i<=n;i++) e[i].swap(E[i]);
	return ans;
} 
int main()
{
	n=read(),m=read();for(int i=1;i<=n;i++) Fa[i]=i;
	for(int i=1;i<=m;i++) add(read(),read());
	for(int i=1;i<=n;i++) if(find(i)==i) vec.pb(ask(i));
	int mn=check(1),p=1;for(int i=2;i<=n;i++) {int x=check(i);if(x<mn) mn=x,p=i;}
	write(mn,'\n');
	for(auto [l,v]:vec) if(find(p)^find(v)) write(p,' '),write(v,'\n'); 
	return ot(),0;
}
//Author: disangan233