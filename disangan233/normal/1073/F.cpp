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
const int N=2e5+5;
int n,tot,mx,d[N],f[N],s1,t1,s2,t2;
vector<int>e[N];in void add(int u,int v) {e[u].pb(v),e[v].pb(u);}
void dfs(int u)
{
	int Mx=0,cnt=0;
	for(int v:e[u]) if(!d[v])
	{
		d[v]=d[u]+1;dfs(v);cnt++;
		if(d[f[v]]>d[f[u]]) Mx=f[u],f[u]=f[v];
		else if(d[f[v]]>d[Mx]) Mx=f[v]; 
	} 
	if(!cnt) f[u]=u;
	else if(cnt>1&&(d[u]>d[mx]||d[u]==d[mx]&&d[f[u]]+d[Mx]>tot)) mx=u,tot=d[f[u]]+d[Mx];
}
void get(int u)
{
	int cnt=0;
	for(int v:e[u]) if(d[v]>d[u]) cnt++,get(v);
	if(!cnt)
	{
		if(d[u]>d[t1]) t2=t1,t1=u;
		else if(d[u]>d[t2]) t2=u;
	}
}
int main()
{
	n=read();for(int i=1;i<n;i++) add(read(),read());
	tot=0;dfs(d[1]=1);
	int u=mx;get(u);s1=t1,s2=t2;memset(d+1,0,4*n);
	d[u]=1;mx=tot=0;dfs(u);int v=mx;t1=t2=0;get(v);
	write(s1,' '),write(t1,'\n');write(s2,' '),write(t2,'\n');
	return ot(),0;
}
//Author: disangan233