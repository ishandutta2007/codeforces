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
int T,t,n,m,n1=1e9,n2=-1e9,l[N],r[N],ans[N];
vector<int>e[N];
void dfs(int u,int c)
{
	if(ans[u]) {if(ans[u]^c) write("IMPOSSIBLE"),ot(),exit(0);return;}
	ans[u]=c;for(int v:e[u]) dfs(v,3-c);
}
int main()
{
	t=read();T=read();n=read();m=read();
	for(int i=1;i<=n;i++) l[i]=read(),r[i]=read(),n1=min(n1,r[i]),n2=max(n2,l[i]);
	if(n1+n2<t) n2=t-n1; else if(n1+n2>T) n1=T-n2;
	if(n1<0||n2<0) write("IMPOSSIBLE"),ot(),exit(0);
	for(int i=1,u,v;i<=m;i++) u=read(),v=read(),e[u].pb(v),e[v].pb(u);
	for(int i=1;i<=n;i++)
	{
		if(l[i]<=n1&&n1<=r[i]&&!(l[i]<=n2&&n2<=r[i])) dfs(i,1);
		else if(l[i]<=n2&&n2<=r[i]&&!(l[i]<=n1&&n1<=r[i])) dfs(i,2);
		else if(!(l[i]<=n1&&n1<=r[i])&&!(l[i]<=n2&&n2<=r[i])) write("IMPOSSIBLE"),ot(),exit(0);
	}
	for(int i=1;i<=n;i++) if(!ans[i]) dfs(i,1);
	write("POSSIBLE");write(n1,' ');write(n2,'\n');
	for(int i=1;i<=n;i++) write(ans[i]," \n"[i==n]),(i==n)?0:C--;
	return ot(),0;
}
//Author: disangan233