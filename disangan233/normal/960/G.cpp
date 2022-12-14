#pragma GCC optimize(2,3,"Ofast")
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
	in int gs(char *s) {char c,*t=s;while(c=gc(),c<32);*s++=c;while(c=gc(),c>32)*s++=c;return s-t;}
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
#define init(x,n) static int x[N];memset(x,0,4*n);
const int N=4e5+5,p=998244353,G=3;
int n,m,k,ans,len,L,a[N],fac[N],inv[N];
in void M(int &x) {if(x>=p)x-=p;}
in int qpow(int x,int y) {int z=1;for(;y;y>>=1,x=(ll)x*x%p) if(y&1) z=(ll)x*z%p;return z;}
in void read(int *a,int n) {for(int i=0;i<n;i++) a[i]=read();}
in void print(int *a,int n) {for(int i=0;i<n;i++) write(a[i]," \n"[i==n-1]);}
namespace poly
{
	int rev[N],ny[N],omg[N],_omg[N];
	in void calrev(int len,int L)
	{
		for(int i=1;i<=len;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(L-1));
		omg[0]=1;omg[1]=qpow(G,(p-1)/len);
		for(int i=2;i<=len;i++) omg[i]=((ll)omg[1]*omg[i-1])%p;
		for(int i=0;i<len;i++) _omg[i]=omg[len-i];
	}
	in void ntt(int *a,int n,int op)
	{
		for(int i=0;i<n;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);int *w=(op==1)?omg:_omg;
		for(int i=1;i<n;i<<=1) for(int j=0;j<n;j+=(i<<1)) for(int k=0,x,y;k<i;k++)
		x=a[j+k],y=(ll)w[n/(i<<1)*k]*a[j+k+i]%p,a[j+k]=((ll)x+y)%p,a[j+k+i]=((ll)x-y+p)%p;
		if(op==1) return; int inv=qpow(n,p-2);for(int i=0;i<n;i++) a[i]=(ll)a[i]*inv%p;
	}
	in void mul(int *a,int *b,int n)
	{
		init(x,len);memcpy(x,a,4*len);init(y,len);memcpy(y,b,4*len);
		ntt(x,len,1);ntt(y,len,1);for(int i=0;i<len;i++) a[i]=(ll)x[i]*y[i]%p;
		ntt(a,len,-1);memset(a+n,0,4*(len>>1));
	}
}
in int c(int n,int m) {return 1ll*fac[n]*inv[m]%p*inv[n-m]%p;}
void solve(int n)
{
	if(!n) return a[0]=1,void(); if(n==1) return a[0]=0,a[1]=1,void();
	if(n&1) {solve(n-1);for(int i=n;~i;i--) a[i]=(a[i]*(n-1ll)+a[i-1])%p;return;}
	solve(n>>1);int m=(n>>1)+1;L=ceil(log2(2*m-1));poly::calrev(len=1<<L,L);init(b,m<<1);init(c,m<<1);
	for(int i=0;i<m;i++) b[i]=1ll*qpow(m-1,i)*inv[i]%p,c[i]=1ll*a[m-i-1]*fac[m-i-1]%p;
	poly::mul(c,b,m);for(int i=0;i<m;i++) b[i]=1ll*c[m-i-1]*inv[i]%p;
	poly::mul(a,b,len);memset(a+n+1,0,4*(len-n-1));
}
int main()
{
	n=read(),m=read(),k=read(),fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(int i=2;i<=max(n,m+k);i++) inv[i]=1ll*(p-p/i)*inv[p%i]%p;
	for(int i=2;i<=max(n,m+k);i++) inv[i]=1ll*inv[i]*inv[i-1]%p,fac[i]=1ll*fac[i-1]*i%p;
	solve(n-1);write(1ll*c(m+k-2,m-1)*a[m+k-2]%p,'\n');
	return ot(),0;
}
//Author: disangan233
//In my dream's scene,I can see the everything that in Cyaegha.