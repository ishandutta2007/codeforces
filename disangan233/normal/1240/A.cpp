// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register int
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in ll read()
	{
		ll x=0,y=1;while(nc=gc(),(nc<48||nc>57)&&nc!=-1)if(nc==45)y=-1;Bi=1;
		x=nc-48;while(nc=gc(),47<nc&&nc<58)x=(x<<3)+(x<<1)+(nc^48),Bi++;return x*y;
	}
	in db gf() {re a=read(),b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi):a);}
	in int gs(char *s) {char c,*t=s;while(c=gc(),c<32);*s++=c;while(c=gc(),c>32)*s++=c;return s-t;}
	in void ot() {fwrite(sr,1,C+1,stdout);C=-1;}
	in void flush() {if(C>1<<22) ot();}
	template <typename T>
	in void write(T x,char t)
	{
		re y=0;if(x<0)y=1,x=-x;while(z[++Z]=x%10+48,x/=10);
		if(y)z[++Z]='-';while(sr[++C]=z[Z],--Z);sr[++C]=t;flush();
	}
	in void write(char *s) {re l=strlen(s);for(re i=0;i<l;i++)sr[++C]=*s++;sr[++C]='\n';flush();}
}
using namespace fast_io;
const int N=3e5+5;
ll t,x,k,a,y,b,n,m,p[N];
in int check(re n)
{
	ll ans=0;
	ll na=n/x,nb=n/y,nab=n/(x*y/__gcd(x,y));na-=nab;nb-=nab;
	for(re i=1;i<=nab;i++) ans+=p[i]*(a+b)/100;
	for(re i=nab+1;i<=nab+na;i++) ans+=p[i]*(a)/100;
	for(re i=nab+na+1;i<=nab+na+nb;i++) ans+=p[i]*(b)/100;
	return ans>=k;
}
int main()
{
	t=read();
	while(t--)
	{
		n=read();for(re i=1;i<=n;i++) p[i]=read();
		a=read();x=read();b=read();y=read();k=read();
		if(a<b) swap(a,b),swap(x,y);
		re l=1,r=n,ans=n;sort(p+1,p+n+1,greater<int>());
		if(!check(r)) {write("-1");continue;}
		while(l<=r)
		{
			re mid=(l+r)>>1;
			if(check(mid)) r=mid-1,ans=mid;
			else l=mid+1;
		}
		write(ans-min(ans%(x*y/__gcd(x,y)),min(ans%x,ans%y)),'\n');
	}
	return ot(),0;
}
//Author: disangan233
//In my dream's scene,I can see the everything that in Cyaegha.