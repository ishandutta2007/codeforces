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
const int N=5+4e5;
struct E{ int x,y,k; };
vector<E> e;
bool cmp(E x,E y){ return x.k<y.k; }
int top_node=0,n,m,a[N],b[N];
struct DSF{
	int fa[N];
	DSF(){ for(int i=0;i<N;++i) fa[i]=i; }
	int fs(int x){
		if(fa[x]!=x) fa[x]=fs(fa[x]);
		return fa[x];
	}
	bool member(int x,int y){ return fs(x)==fs(y); }
	void merge(int x,int y){
		if(!member(x,y))
			fa[fs(x)]=fs(y);
	}
}dsf;
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i) scanf("%d",&b[i]);
	for(int i=1;i<=m;++i){
		int tp; scanf("%d",&tp);
		for(int k=0;k<tp;++k){
			int x; scanf("%d",&x);
			e.push_back((E){i+n,x,a[i]+b[x]});
		}
	}
	sort(e.begin(),e.end(),cmp);
	reverse(e.begin(),e.end());
	ll ans=0;
	for(auto x:e){
//		printf("|%d %d %d|",x.x,x.y,x.k);
		if(!dsf.member(x.x,x.y)){
			dsf.merge(x.x,x.y);
		}else ans+=x.k;
	}
	printf("%lld\n",ans);
	return 0;
}