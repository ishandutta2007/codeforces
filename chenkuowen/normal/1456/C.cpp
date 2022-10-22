#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
//const ld PI=acosl(-1),EPS=1e-10;
template<class T> inline void dmin(T& x,T y){ y<x?x=y:0; }
template<class T> inline void dmax(T& x,T y){ y>x?x=y:0; }
template<class T> inline void dmin(T& x,vector<T> y){for(auto t:y)t<x?x=t:0;}
template<class T> inline void dmax(T& x,vector<T> y){for(auto t:y)t>x?x=t:0;}
/*
const int N=5+1e5,MOD=998244353;
inline int fpow(int x,int n,int ret=1,int mod=MOD){
	for(;n;n>>=1,x=1ll*x*x%mod)
		n&1?ret=1ll*ret*x%mod:0;
	return ret;
}
inline void mo(int& x){ x>=MOD?x-=MOD:0; }
inline int mo1(int x){ return x>=MOD?x-MOD:x; }
int inv[N],fac[N],ifac[N];
struct IniterFacInv{
	IniterFacInv(){
		fac[0]=ifac[0]=inv[1]=1;
		for(int i=1;i<N;++i){
			fac[i]=1ll*fac[i-1]*i%MOD;
			if(i>1) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
			ifac[i]=1ll*ifac[i-1]*inv[i]%MOD;
		}
	}
}__initer_comb;
inline int comb(int n,int m){
	if(n<0||m<0||n<m) return 0;
	return 1ll*fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
}
inline int rcomb(int n,int m){
	if(n<0||m<0||n<m) return 0;
	return 1ll*ifac[n]*fac[m]%MOD*fac[n-m]%MOD;
}
*/
const int N=5+1e6;
int a[N];
ll s[N];
int main(){
	int n,k,tp=0; scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	ll key2=0;
	for(int i=1;i<=n;++i){
		key2+=1ll*(n-i)*a[i];
		s[i]=s[i-1]+a[i];
//		printf("<%d>",a[i]);
//		if(a[i]>=0) tp=i;
	}
//	tp=n-tp;
//	printf("{%d}",tp);
//	puts("");
	ll ans=-(ll)2e18,key1=0;
	for(int i=0;(i-1)*(k+1)+1<=n;i++){
		int l=(i-1)*(k+1)+1,r=min(i*(k+1),n);
		if(i>0){
			for(int j=l;j<=r;++j){
				key1+=1ll*(i-1)*a[n-j+1];
				key2-=s[n-j];
//			printf("[%d %d %lld %lld %lld]",l,r,key1,key2,1ll*i*s[n-r]);
				ans=max(ans,key1+key2+1ll*i*s[n-j]);
			}
		}
		ans=max(ans,key1+key2+1ll*i*s[n-r]);
	}
	printf("%lld\n",ans);
	return 0;
}