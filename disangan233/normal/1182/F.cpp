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
ll t,a,b,p,q,len;
in ll calc(ll a,ll b,ll c,ll n)
{
	if(!a||!n) return (n+1)*(b/c);if(n<0) return 0; 
	ll m=(a*n+b)/c;if(a>=c||b>=c) return calc(a%c,b%c,c,n)+(n*(n+1)>>1)*(a/c)+(n+1)*(b/c);
	return n*m-calc(c,c-b-1,a,m-1);
}
in ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b) return x=1,y=0,a;ll d=exgcd(b,a%b,y,x);
	return y-=a/b*x,d; 
}
int main()
{
	t=read();
	while(t--)
	{
		a=read(),b=read(),p=read(),q=read();
		ll l=0,r=q,m,s=p<<1,t=q<<1;
		while(l<r)
		{
			m=(l+r)>>1;ll L=q-m,R=q+m+1;
			calc(s,t-L,t,b)+calc(s,t-R,t,a-1)-calc(s,t-L,t,a-1)-calc(s,t-R,t,b)>0?r=m:l=m+1;
		}
		ll x,y,d=exgcd(s,t,x,y),ans=1e9;s/=d,t/=d;
		if((q-l)%d==0)
		{
			ll v=(q-l)/d*x;v+=(a-v)/t*t;
			while(v>=a) v-=t;while(v<a) v+=t;
			ans=min(ans,v);
		}
		if((q+l)%d==0)
		{
			ll v=(q+l)/d*x;v+=(a-v)/t*t;
			while(v>=a) v-=t;while(v<a) v+=t;
			ans=min(ans,v);
		}
		write(ans,'\n');ot();
	}
	return ot(),0;
}
//Author: disangan233