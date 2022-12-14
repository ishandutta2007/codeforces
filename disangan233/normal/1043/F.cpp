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
const int N=3e5+5,p=998244353; 
int n,a[N],b[N],fac[N],inv[N],f[N][15];
in int qpow(int a,int b) {int c=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)c=1ll*a*c%p;return c;}
in int c(int n,int m) {return n<m?0:1ll*fac[n]*inv[m]%p*inv[n-m]%p;}
in void M(int &x) {x-=p;x+=x>>31&p;}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read(),b[a[i]]++,f[a[i]][1]++;
		if(a[i]==1) return write("1"),ot(),0;
	}
	fac[0]=1;for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%p;
	inv[n]=qpow(fac[n],p-2);for(int i=n;i;i--) inv[i-1]=1ll*inv[i]*i%p;
	for(int i=1;i<N;i++) for(int j=2*i;j<N;j+=i) b[i]+=b[j];
	for(int i=2;i<=11;i++)
	{
		for(int j=N-1;j;j--)
		{
			f[i][j]=c(b[j],i);
			for(int k=2*j;k<N;k+=j) M(f[i][j]+=p-f[i][k]);
		}
		if(f[i][1]>0) return write(i,'\n'),ot(),0;
	}write("-1");
	return ot(),0;
}
//Author: disangan233