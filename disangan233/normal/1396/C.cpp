#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
	in db gf() {int a=read(),b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi):a);}
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
const int N=1e6+5;
ll n,r1,r2,r3,d,a[N],b[N],c[N],f[N],s[N],mn=1e18;
int main()
{
	n=read(),r1=read(),r2=read(),r3=read(),d=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]*min(r1,r3)+r3;
		c[i]=min(r2+min(min(r1,r2),r3),a[i]*min(r1,r3)+min(r1,r2)+min(min(r1,r2),r3));
		s[i]=s[i-1]+min(b[i],c[i]);
	}
	f[1]=b[1];for(int i=2;i<n;i++) mn=min(mn,f[i-2]-s[i-2]-2*(i-1)*d),f[i]=min(f[i-1]+b[i],mn+s[i]+2*i*d);
	f[n]=f[n-1]+b[n];
	for(int i=0;i<n-1;i++)
	{
		f[n]=min(f[n],f[i]+s[n]-s[i]+2*n*d-2*(i+1)*d);
		f[n]=min(f[n],f[i]+s[n-1]-s[i]+b[n]+n*d-(i+1)*d);
	}
	write(f[n]+(n-1)*d,'\n');
	return ot(),0;
}
//Author: disangan233