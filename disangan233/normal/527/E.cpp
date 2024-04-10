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
const int N=1e5+5,M=1e6+5;
int n,m,c=1,d[N],k,to[M],vi[M],h[N],nxt[M];
vector<int>p;
in void Add(int u,int v) {nxt[++c]=h[u],to[c]=v,h[u]=c;}
in void add(int u,int v) {d[u]++,d[v]++;Add(u,v);Add(v,u);}
in void dfs(int u)
{
	for(int &i=h[u];i;i=nxt[i]) if(!vi[i])
	{
		vi[i]=vi[i^1]=1;int v=to[i];dfs(v);
		if((++k)&1) write(u,' '),write(v,'\n');
		else write(v,' '),write(u,'\n');
	}
}
int main()
{
	n=read(),m=read();for(int i=1;i<=m;i++) add(read(),read());
	for(int i=1;i<=n;i++) if(d[i]&1) p.pb(i);
	for(int i=0;i<p.size();i+=2) add(p[i],p[i+1]),m++;
	if(m&1) add(1,1),m++;write(m,'\n');dfs(1);
	return ot(),0;
}
//Author: disangan233