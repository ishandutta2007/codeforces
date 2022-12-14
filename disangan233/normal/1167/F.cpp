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
#define pb push_back
const int N=5e5+3,p=1e9+7;
int n,ans,a[N],b[N],c[N],t[N];
in void M(int &x) {x-=p;x+=x>>31&p;}
in void add(int x,int y) {for(;x<=n;x+=x&-x)M(t[x]+=y);}
in int ask(int x) {int y=0;for(;x;x-=x&-x)M(y+=t[x]);return y;} 
int main()
{
	n=read();for(int i=1;i<=n;i++) a[i]=b[i]=read();sort(b+1,b+n+1);
	for(int i=1;i<=n;i++) c[i]=lower_bound(b+1,b+n+1,a[i])-b;
	for(int i=1;i<=n;i++) M(ans+=1ll*a[i]*(n-i+1)%p*ask(c[i])%p),add(c[i],i);
	memset(t+1,0,4*n);
	for(int i=n;i;i--) M(ans+=1ll*a[i]*i%p*ask(c[i])%p),add(c[i],n-i+1);
	for(int i=1;i<=n;i++) M(ans+=1ll*a[i]*i%p*(n+1-i)%p);
	write(ans,'\n'); 
	return ot(),0;
}
//Author: disangan233