#pragma GCC optimize(2,3,"Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0,Ny;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in int read()
	{
		int x=0;Ny=1;while(nc=gc(),(nc<48||nc>57)&&nc!=EOF)if(nc==45)Ny=-1;Bi=1;if(nc<0)return nc;
		x=nc-48;while(nc=gc(),47<nc&&nc<58&&nc!=EOF)x=(x<<3)+(x<<1)+(nc^48),Bi++;return x*Ny;
	}
	in db gf() {int a=read(),y=Ny,b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi)*y:a);}
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
#define lb lower_bound
#define ub upper_bound
#define pii pair<int,int>
#define fi first
#define se second
const int N=1e5+5,M=5e2+5;
struct did{int t,x,y;}p[N];
int n,m,ans,mx,f[N];vector<int>g[N];
int main()
{
	m=read(),n=read();for(int i=1;i<=n;i++) f[i]=-1e9;mx=-1e9;
	for(int i=1;i<=n;i++) p[i]={read(),read(),read()};
	p[0]={0,1,1};
	for(int i=0;i<=n;i++)
	{
		for(auto x:g[i]) mx=max(mx,x);
		f[i]=max(f[i],mx);ans=max(ans,f[i]);if(f[i]==-1e9) continue;
		int j=i+1;
		for(;j<=n&&p[j].t-p[i].t<2*m;j++) if(abs(p[j].x-p[i].x)+abs(p[j].y-p[i].y)<=p[j].t-p[i].t) f[j]=max(f[j],f[i]+1);
		if(j<=n) g[j].pb(f[i]+1);
	}
	write(ans,'\n');
	return ot(),0;
}
//Author: disangan233