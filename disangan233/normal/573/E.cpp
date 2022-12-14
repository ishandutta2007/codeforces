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
}
using namespace fast_io;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int N=1e5+5,M=375;
int n,m,k,a[N],b[N],p[N],l[M],r[M];ll f[N],ans;
struct B
{
	int L,R,q[M];ll k,b;
	in ll c(int i) {return f[i]+k*a[i]+b;}
	in db s(int i,int j) {return a[i]^a[j]?1.0*(f[i]-f[j])/(a[i]-a[j]):(f[i]>f[j]?-1:1)*1e18;}
	in void build(int x)
	{
		for(int i=l[x];i<=r[x];i++) f[i]+=k*a[i]+b; k=b=L=R=0;
		for(int i=l[x];i<=r[x];q[R++]=p[i],i++)
		while(R-L>1&&s(q[R-2],q[R-1])<s(q[R-1],p[i])) R--;
	}
	in pair<ll,int> ask() {while(R-L>1&&c(q[L])<=c(q[L+1])) L++;return mp(c(q[L]),q[L]);}
}t[M];
int main()
{
	n=read(),m=sqrt(n);
	for(int i=k=1;i<=n;k+=!(i%m),i++) a[i]=f[i]=read(),b[p[i]=i]=k; if(!(n%m)) k--;
	for(int i=1;i<=k;i++)
	{
		l[i]=r[i-1]+1;r[i]=min(i*m,n);
		sort(p+l[i],p+r[i]+1,[](int i,int j){return a[i]<a[j];});
		t[i].build(i);
	}
	while(1)
	{
		pair<ll,int>x=mp(0,0);for(int i=1;i<=k;i++) x=max(x,t[i].ask());
		if(!x.fi) return write(ans,'\n'),ot(),0;
		ans+=x.fi,f[x.se]=-1e18;
		for(int i=1;i<b[x.se];i++) t[i].b+=a[x.se];
		for(int i=l[b[x.se]];i<x.se;i++) f[i]+=a[x.se];
		for(int i=x.se+1;i<=r[b[x.se]];i++) f[i]+=a[i];
		for(int i=b[x.se]+1;i<=k;i++) t[i].k++;
		t[b[x.se]].build(b[x.se]);
	}
	return ot(),0;
}
//Author: disangan233