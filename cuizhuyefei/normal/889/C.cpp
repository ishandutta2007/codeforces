#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline int max(int a, int b) {return a>b ? a : b;}
inline int min(int a, int b) {return a<b ? a : b;}
const int N = 1020000, mo = 1e9+7;
int n,k;
ll f[N],now,fac[N];
inline void exgcd(ll a, ll b, ll &x, ll &y) {
	if (!b) {x=1; y=0; return;}
	exgcd(b,a%b,y,x); y-=a/b*x;
}
inline ll inv(ll a) {ll x,y; exgcd(a,mo,x,y); return x>=0 ? x : x+mo;}
inline ll C(int n, int m) {
	return fac[n]*inv(fac[m]*fac[n-m]%mo)%mo;
}
int main() {
	read(n); read(k); f[1]=1;
	fac[0]=1; rep(i,1,n+1) fac[i]=fac[i-1]*i%mo;
	rep(i,2,k+1) f[i]=(f[i-1]+f[i-1]*(i-2))%mo;
	rep(i,k+2,n+1) {
		f[i]=f[i-1]+(f[i-1]-f[i-k-1]*fac[i-3]%mo*inv(fac[i-k-2])%mo)*(i-2)%mo;
		f[i]%=mo; if (f[i]<0) f[i]+=mo;
	}
//	rep(i,1,n+1) printf("%d : %lld\n",i,f[i]);
	ll ans=f[n+1]; rep(i,1,n-k) (ans+=C(n-1,i-1)*f[i]%mo*fac[n-i]%mo)%=mo;
	printf("%lld",(fac[n]-ans+mo)%mo);
	return 0;
} //5 5		120