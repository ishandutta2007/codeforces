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
const int N=1e2+5,M=3e3+5;
int n,m,f[M];vector<int>v[M];
struct did{
	ll a,b,c,i;
	in bool operator<(did x) const {return b<x.b;}
}a[N];
int main()
{
	n=read();f[0]=0;
	for(int i=1;i<=n;i++) a[i]={read(),read(),read(),i};
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) for(int j=a[i].b-1;j>=a[i].a;j--)
	if(f[j-a[i].a]+a[i].c>f[j]) f[j]=f[j-a[i].a]+a[i].c,v[j]=v[j-a[i].a],v[j].push_back(a[i].i);
	int s=0;for(int i=1;i<M;i++) if(f[i]>f[s]) s=i;
	write(f[s],'\n');write(v[s].size(),'\n');
	for(auto x:v[s]) write(x,' ');
	return ot(),0;
}