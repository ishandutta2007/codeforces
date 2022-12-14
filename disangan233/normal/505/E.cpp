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
const int N=1e5+5;
int n,m,k,c[N];ll p,l,r,mid,a[N],h[N];
struct pii{ll a,b;in bool operator<(pii x)const{return a^x.a?a<x.a:b<x.b;}};
in int check(ll H)
{
	priority_queue<pii>q;
	for(int i=1;i<=n;i++) if(h[i]+m*a[i]>H) q.push({-H/a[i],i}),c[i]=0;
	int cnt=0;
	for(int i=1;q.size()&&i<=m;i++) for(int j=1;q.size()&&j<=k;j++)
	{
		if(-q.top().a<i) return 0;int x=q.top().b;q.pop();
		ll w=(H+(++c[x])*p)/a[x];if(w<m) q.push({-w,x});cnt++;
	}
	for(int i=1;i<=n;i++)
	{
		ll w=H+c[i]*p-m*a[i];if(h[i]<=w) continue;
		w=(h[i]-w-1)/p+1;if(cnt+w>m*k) return 0;cnt+=w;
	}
	return 1;
}
int main()
{
	n=read(),m=read(),k=read(),p=read();
	for(int i=1;i<=n;i++) h[i]=read(),a[i]=read(),l=max(l,a[i]),r=max(r,h[i]+m*a[i]);
	while(l<r) mid=(l+r)>>1,check(mid)?r=mid:l=mid+1;
	write(l,'\n');
	return ot(),0;
}
//Author: disangan233