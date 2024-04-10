#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
//const ld PI=acosl(-1),EPS=1e-10;
template<class T> inline void chmin(T& x,T y){ y<x?x=y:T(); }
template<class T> inline void chmax(T& x,T y){ y>x?x=y:T(); }
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
int main(){
	int T; scanf("%d",&T);
	while(T--){
		vector<ld> a,b;
		int n; scanf("%d",&n);
		for(int i=1;i<=n+n;++i){
			ld x,y; scanf("%Lf%Lf",&x,&y);
			if(x==0) a.push_back(fabsl(y));
			else b.push_back(fabsl(x));
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		ld ans=0;
		for(int i=0;i<n;++i)
			ans+=sqrtl(a[i]*a[i]+b[i]*b[i]);
		printf("%.14Lf\n",ans);
	}
	return 0;
}