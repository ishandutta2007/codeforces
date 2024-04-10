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

const int N=5+2e3,MOD=998244353;
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
int a[N][N];
struct E{ int x,y,k; };
vector<E> e;
bool cmp(E a,E b){ return a.k<b.k; }
vector<int> merge(vector<int> a,vector<int> b){
	vector<int> c(a.size()+b.size()-1);
	for(int i=0;i<a.size();++i)
		for(int j=0;j<b.size();++j)
			c[i+j]=(c[i+j]+1ll*a[i]*b[j])%MOD;
	return c;
}
struct DSF{
	int fa[N],sz[N],cnt[N]; vector<int> a[N];
	DSF(){ for(int i=0;i<N;++i) fa[i]=i,a[i]=vector<int>({0,1}); }
	int fs(int x){
		if(fa[x]!=x) fa[x]=fs(fa[x]);
		return fa[x];
	}
	bool member(int x,int y){ return fs(x)==fs(y); }
	void merge(int x,int y){
		if(!member(x,y)){
			x=fs(x),y=fs(y);
			fa[x]=y;
			a[y]=::merge(a[y],a[x]);
			cnt[y]=cnt[y]+cnt[x]+1;
			a[x].clear();
		}else cnt[fs(x)]++;
		int sz=(int)a[fs(x)].size()-1;
//		printf("[%d %d]",cnt[fs(x)],sz);
		if(cnt[fs(x)]==1ll*sz*(sz-1)/2)
			mo(a[fs(x)][1]+=1);
	}
}dsf;
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			int x; scanf("%d",&x);
			if(i<j) e.push_back((E){i,j,x});
		}
	sort(e.begin(),e.end(),cmp);
	for(auto x:e)
		dsf.merge(x.x,x.y);
	for(int i=1;i<=n;++i)
		printf("%d ",dsf.a[dsf.fs(1)][i]);
	return 0;
}