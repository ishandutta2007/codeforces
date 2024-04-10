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
const int N=5e1+5,p=998244353;
#define pb push_back
#define lb lower_bound
int n,m,a[N],b[N],c[N<<1],f[N],g[N],inv[N],ans;
in void M(int &x) {x-=p;x+=x>>31&p;} 
in int qpow(int a,int b) {int c=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)c=1ll*a*c%p;return c;}
int main()
{
	n=read();for(int i=1;i<=n;i++) a[i]=c[++m]=read(),b[i]=c[++m]=read()+1;
	sort(c+1,c+m+1);m=unique(c+1,c+m+1)-c-1;f[0]=inv[0]=inv[1]=1;
	for(int i=2;i<=n;i++) inv[i]=1ll*(p-p/i)*inv[p%i]%p;
	for(int i=1;i<=n;i++) a[i]=lb(c+1,c+m+1,a[i])-c,b[i]=lb(c+1,c+m+1,b[i])-c;
	for(int j=m-1,l;j;j--)
	{
		l=c[j+1]-c[j];g[0]=1;
		for(int i=1;i<=n;i++) g[i]=(l+i-1ll)*g[i-1]%p*inv[i]%p;
		for(int i=n;i;i--) if(a[i]<=j&&j<b[i]) for(int k=i-1,c=1;~k;k--,c++)
		{M(f[i]+=1ll*g[c]*f[k]%p);if(a[k]>j||j>=b[k]) break;}
	}
	ans=f[n];
	for(int i=1;i<=n;i++) ans=1ll*ans*qpow(c[b[i]]-c[a[i]],p-2)%p;write(ans,'\n'); 
	return ot(),0;
}
//Author: disangan233