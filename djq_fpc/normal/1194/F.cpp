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
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
using namespace std;
long long n,m,i,j,fac[200005],inv[200005],fi[200005],a[200005],pw[200005],ans,mod=1e9+7,lstx,lsty,tmp;
long long qp(long long x,long long y)
{
	long long z=1;
	while(y){
		if(y&1){
			z=1ll*z*x%mod;
		}
		x=1ll*x*x%mod;
		y/=2;
	}
	return z;
}
long long c(long long x,long long y)
{
	return fac[x]*fi[y]%mod*fi[x-y]%mod;
}
long long solve(long long x,long long y)
{
	while(lstx<x){
		tmp=(tmp*2-c(lstx,lsty)+mod)%mod;
		lstx++;
	}
	while(lsty<y){
		lsty++;
		tmp=(tmp+c(lstx,lsty)+mod)%mod;
	}
	while(lsty>y){
		tmp=(tmp-c(lstx,lsty)+mod)%mod;
		lsty--;
	}
	return tmp;
}
int main()
{
	fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;
	fz(i,2,200000){
		fac[i]=1ll*fac[i-1]*i%mod;
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		fi[i]=1ll*fi[i-1]*inv[i]%mod;
	}
	scanf("%lld%lld",&n,&m);
	pw[0]=1;
	fz1(i,n){
		pw[i]=2ll*pw[i-1]%mod; 
		scanf("%lld",&a[i]);
		a[i]+=a[i-1];
	}
	lstx=1;lsty=0;tmp=1;
	fz1(i,n){
		long long t=min(i,m-a[i]);
		if(t<0)continue;
		ans=(ans+pw[n-i]*solve(i,t))%mod;
	}
	cout<<1ll*ans*qp(pw[n],mod-2)%mod<<endl;
	return 0;
}