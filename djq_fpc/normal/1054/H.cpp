#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<bitset>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
const int maxn=2097152,mod1=490019,mod2=490018;
const int p1=998244353,p2=1004535809,g=3;
int n,m,t,i,j,a[1000005],b[1000005],c[maxn+5],d[maxn+5],e[maxn+5],f[maxn+5],ans;
int rev[maxn+5],inv[maxn+5],w[maxn+5];
long long mul(long long x,long long y,long long mod)
{
    long long t=((long double)x)*y/mod;
    long long s=x*y-t*mod;
    s=(s%mod+mod)%mod;
    return s;
}
int qp(int x,int y,int mod)
{
	int z=1;
	while(y){
		if(y&1){
			z=1ll*z*x%mod;
		}
		x=1ll*x*x%mod;
		y/=2;
	}
	return z;
}
int c2(int x)
{
	return 1ll*x*(x-1)/2%mod2;
}
void init(int mod)
{
	int i;
	w[0]=inv[1]=1;w[1]=qp(g,(mod-1)/maxn,mod);
	fz(i,2,maxn){
		w[i]=1ll*w[i-1]*w[1]%mod;
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	}
}
int getrev(int x)
{
	int len=1,i;
	while(len<=x)len<<=1;
	fz0k(i,len){
		rev[i]=rev[i/2]/2+((i&1)*(len>>1));
	}
	return len;
}
void ntt(int *a,int len,int op,int mod)
{
	int i,j,k;
	fz0k(i,len) if(rev[i]<i) swap(a[i],a[rev[i]]);
	for(i=1;i<len;i<<=1){
		int ys=maxn/i/2;
		for(j=0;j<len;j+=i+i){
			int t=(op==1?0:maxn);
			fz0k(k,i){
				int x=a[k+j],y=1ll*a[j+k+i]*w[t]%mod;
				a[j+k]=(x+y)%mod;
				a[j+k+i]=(x-y+mod)%mod;
				t+=ys*op;
			}
		}
	}
	if(op==-1){
		fz0k(i,len) a[i]=1ll*a[i]*inv[len]%mod;
	}
}
int main()
{
	read(n);read(m);read(t);int it=qp(t,mod2-1,mod1);
	fz0k(i,n){
		int x,p=1ll*i*i%(2*mod2);
		read(x);
		a[p]=(a[p]+1ll*x*qp(it,c2(p)%mod2,mod1))%mod1;
	}
	fz0k(i,m){
		int x,p=1ll*i*i*i%(2*mod2);
		scanf("%d",&x);
		b[p]=(b[p]+1ll*x*qp(it,c2(p)%mod2,mod1))%mod1;
	}
/*	fz0k(i,mod2*2){
		if(a[i]) cerr<<i<<' '<<a[i]<<endl;
	}
	fz0k(i,mod2*2){
		if(b[i]) cerr<<i<<' '<<b[i]<<endl;
	}*/
	int len=getrev(mod2*4);
	init(p1);
	fz0k(i,len){if(i<mod2*2){c[i]=a[i];d[i]=b[i];}else{c[i]=d[i]=0;}}
	ntt(c,len,1,p1);ntt(d,len,1,p1);
	fz0k(i,len) e[i]=1ll*c[i]*d[i]%p1;
	ntt(e,len,-1,p1);
	
	init(p2);
	fz0k(i,len){if(i<mod2*2){c[i]=a[i];d[i]=b[i];}else{c[i]=d[i]=0;}}
	ntt(c,len,1,p2);ntt(d,len,1,p2);
	fz0k(i,len) f[i]=1ll*c[i]*d[i]%p2;
	ntt(f,len,-1,p2);
	
/*	fz0k(i,mod2*2){
		if(e[i]) cout<<i<<' '<<e[i]<<endl;
	}
	cout<<endl;
	fz0k(i,mod2*2){
		if(f[i]) cout<<i<<' '<<f[i]<<endl;
	}*/
	int ip1=qp(p1,p2-2,p2);
	int ip2=qp(p2,p1-2,p1);
	long long ps=1ll*p1*p2;
	fz0k(i,2*mod2){
	    e[i]=(e[i]+e[i+2*mod2])%p1;
	    f[i]=(f[i]+f[i+2*mod2])%p2;
//	    cout<<e[i]<<' '<<f[i]<<' ';
		long long s=(mul(1ll*p2*ip2,e[i],ps)+mul(1ll*p1*ip1,f[i],ps))%ps%mod1;
//		cout<<s<<endl;
		ans=(ans+1ll*s*qp(t,c2(i)%mod2,mod1))%mod1;
	}
	cout<<ans<<endl;
	return 0;
}