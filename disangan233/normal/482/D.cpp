#pragma GCC optimize(2,3,"Ofast","unroll-loops")
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
const int N=1e5+5,p=1e9+7; 
int n,m,t,f[N][2],g[N][4];
vector<int>e[N];in void add(int u,int v) {e[u].pb(v),e[v].pb(u);}
in void M(int &x) {x-=p;x+=x>>31&p;}
void dfs(int u)
{
	sort(e[u].begin(),e[u].end());f[u][0]=0,f[u][1]=1;int mul=1;
	for(int v:e[u]) 
	{
		dfs(v);int f0=f[u][0],f1=f[u][1];
		M(f[u][0]+=1ll*f0*f[v][0]%p);M(f[u][0]+=1ll*f1*f[v][1]%p);
		M(f[u][1]+=1ll*f0*f[v][1]%p);M(f[u][1]+=1ll*f1*f[v][0]%p);
	}
	reverse(e[u].begin(),e[u].end());M(f[u][0]<<=1),M(f[u][1]<<=1);g[u][0]=1,g[u][1]=0;
	for(int v:e[u])
	{
		int t=g[u][1];M(g[u][1]+=1ll*g[u][0]*f[v][1]%p);
		M(g[u][0]+=1ll*t*f[v][1]%p);mul=1ll*mul*(f[v][0]+1)%p;
	}
	M(f[u][0]+=p-g[u][1]);M(f[u][1]+=p-mul);
}
int main()
{
	t=1;
	while(t--)
	{
		n=read();for(int i=1;i<=n;i++) e[i].clear();
		for(int i=2;i<=n;i++) e[read()].pb(i);
		dfs(1);write(1ll*(f[1][0]+f[1][1])%p,'\n');
	}
	return ot(),0;
}
//Author: disangan233