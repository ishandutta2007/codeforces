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
vector<vector<int> > a;
vector<pair<int,int> > ans;
void update(){
	while(a.size()>1&&a.back().size()==a[(int)a.size()-2].size()){
			int tp=(int)a.size()-1;
			for(int i=0;i<a[tp].size();++i)
				ans.push_back(make_pair(a[tp][i],a[tp-1][i]));
			for(auto x:a[tp]) a[tp-1].push_back(x);
			a.pop_back();
		}
}
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i){
		a.push_back(vector<int>({i}));
		update();
	}
	while(a.size()>2){
		int tp=(int)a.size()-1,sz=(int)a[tp].size();
		for(int i=0;i<sz;++i){
			ans.push_back(make_pair(a[tp][i],a[0].back()));
			a[tp].push_back(a[0].back());
			a[0].pop_back();
		}
		update();
	}
	printf("%d\n",(int)ans.size());
	for(auto x:ans)
		printf("%d %d\n",x.first,x.second);
	return 0;
}