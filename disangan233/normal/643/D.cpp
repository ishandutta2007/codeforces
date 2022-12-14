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
int n,q,c[N],f[N];ll a[N],g[N];
multiset<ll>s[N],t;
in ll ask(int i) {return a[i]-(a[i]/(c[i]+2))*(c[i]+1);}
in ll qson(int i) {return a[i]/(c[i]+2);}
in void add(int i,int o) {if(s[i].size()) t.insert((o?*(--s[i].end()):*s[i].begin())+qson(i));} 
in void del(int i,int o) {if(s[i].size()) t.erase(t.find((o?*(--s[i].end()):*s[i].begin())+qson(i)));} 
in void solve(int u,int v)
{
	set<int>h={u,f[u],f[f[u]],v,f[v]},d,fd;
	for(int i:h) if(i) d.insert(i);fd=d;
	for(int i:d) if(f[i]) fd.insert(f[i]);
	for(int i:fd) del(i,1),del(i,0);
	for(int i:d) s[f[i]].erase(s[f[i]].find(g[i]));
	for(int i:d) 
	{
		g[i]-=ask(i);
		for(int j:d) if(f[j]==i) g[i]-=qson(j);
	}c[f[u]]--,f[u]=v,c[v]++;
	for(int i:d)
	{
		g[i]+=ask(i);
		for(int j:d) if(f[j]==i) g[i]+=qson(j); 
	}
	for(int i:d) s[f[i]].insert(g[i]);
	for(int i:fd) add(i,1),add(i,0);
}
int main()
{
	n=read(),q=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) c[f[i]=read()]++;
	for(int i=1;i<=n;i++) g[i]+=ask(i),g[f[i]]+=qson(i);
	for(int i=1;i<=n;i++) s[f[i]].insert(g[i]);
	for(int i=1;i<=n;i++) add(i,1),add(i,0); 
	while(q--)
	{
		int op=read(),x,y;
		if(op==1) x=read(),y=read(),solve(x,y);
		else if(op==2) x=read(),write(g[x]+qson(f[x]),'\n');
		else write(*t.begin(),' '),write(*(--t.end()),'\n');
    } 
	return ot(),0;
}
//Author: disangan233