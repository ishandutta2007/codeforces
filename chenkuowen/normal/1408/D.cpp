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
int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<pair<int,int> > a(n),b(m),c;
	for(int i=0;i<n;++i)
		scanf("%d%d",&a[i].first,&a[i].second);
	for(int i=0;i<m;++i)
		scanf("%d%d",&b[i].first,&b[i].second);
	for(auto x:a)
		for(auto y:b)
			if(x.first<=y.first&&x.second<=y.second)
				c.push_back(make_pair(y.first-x.first+1,y.second-x.second+1));
	sort(c.begin(),c.end());
	int mx=0,ans=(int)2e9;
	for(int i=(int)c.size()-1;i>=0;--i){
		ans=min(ans,c[i].first+mx);
		mx=max(mx,c[i].second);
	}
	ans=min(ans,mx);
	printf("%d\n",ans);
	return 0;
}