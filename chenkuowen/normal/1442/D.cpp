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
const int N=3005;
vector<ll> a[N];
ll f[23][N],ans=0;
int n,k;
void add(ll f[],int x,ll key){
	for(int i=k;i>=x;--i)
		f[i]=max(f[i],f[i-x]+key);
}
void solve(int l,int r,int lev){
	if(l==r){
		for(int i=0;i<a[l].size()&&k-i-1>=0;++i){
			ll key=a[l][i]+f[lev][k-i-1];
			ans=max(ans,key);
//			if(key==5069) printf("[%d %lld %lld]",l,a[l][i],f[lev][k-i-1]);
		}
		ans=max(ans,f[lev][k]);
		return;
	}
	int m=l+r>>1;
	for(int i=0;i<=k;++i) f[lev+1][i]=f[lev][i];
	for(int i=m+1;i<=r;++i) 
		add(f[lev+1],(int)a[i].size(),a[i].back());
	solve(l,m,lev+1);
	for(int i=0;i<=k;++i) f[lev+1][i]=f[lev][i];
	for(int i=l;i<=m;++i)
		add(f[lev+1],(int)a[i].size(),a[i].back());
	solve(m+1,r,lev+1);
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		int m; scanf("%d",&m);
		a[i].resize(m);
		for(int j=0;j<m;++j) scanf("%lld",&a[i][j]);
		for(int j=1;j<m;++j) a[i][j]+=a[i][j-1];
		if(m>k) a[i].resize(k);
	}
	for(int i=0;i<=k;++i) f[1][i]=0;
	solve(1,n,1);
	printf("%lld\n",ans);
	return 0;
}