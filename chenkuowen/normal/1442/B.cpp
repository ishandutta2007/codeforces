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
const int MOD=998244353;
int main(){
	int T; cin>>T;
	while(T--){
		int n,k,ans=1; scanf("%d%d",&n,&k);
		vector<int> a(n+2),poi(n+2),b(n+2),vis(n+2);
		set<int> s;
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),poi[a[i]]=i;
		for(int i=1;i<=k;++i) scanf("%d",&b[i]),vis[poi[b[i]]]=1;
		for(int i=0;i<=n+1;++i) s.insert(i);
		vis[0]=vis[n+1]=1;
		for(int i=1;i<=k;++i){
			int x=poi[b[i]];
//			printf("<%d>",x);
			auto it=s.find(x);
			int y=*prev(it),z=*next(it);
			ans=1ll*ans*(2-vis[y]-vis[z])%MOD;
			vis[x]=0;
		}
		printf("%d\n",ans);
	}
	return 0;
}