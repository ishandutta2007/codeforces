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
const ll INF=-2e18;
int n,k;
ll gk(int x,ll a[],int i,ll f){
	return a[x]+(i-x)/3*f;
}
bool cmp(int x,int y,ll a[],int i,ll f){ //x is better than y
	return gk(x,a,i,f)>gk(y,a,i,f);
}
void opera(ll a[],int n,ll f,int k){
	static ll b[N];
	static ll q[3][N],left[3],right[3];
	for(int i=0;i<3;++i) left[i]=1,right[i]=0;
	for(int i=0;i<n;++i) b[i]=INF;
	for(int i=0;i<n;++i){
		int t=i%3;
		while(left[t]<=right[t]&&q[t][left[t]]<i-3*k) ++left[t];
		while(left[t]<=right[t]&&cmp(i,q[t][right[t]],a,i,f)) --right[t];
		q[t][++right[t]]=i;
		b[i]=gk(q[t][left[t]],a,i,f);
	}
	for(int i=0;i<n;++i) a[i]=b[i];
}
void opera2(ll a[],int n,ll f,int k){
	static ll f1[N],f2[N];
	for(int i=0;i<n;++i){
		f1[i]=f2[i]=a[i];
		for(int j=1;j<10&&i-j>=0;++j)
			f2[i]=max(f2[i],a[i-j]);
	}
	opera(f1,n,f,3*k);
	opera(f2,n,f,3*(k-1));
	for(int i=0;i<n;++i) a[i]=max(f1[i],f2[i]);
}
ll a[N],b[N];
int main(){
	int k; scanf("%d",&k);
	ll f[6];
	for(int i=0;i<6;++i) scanf("%lld",&f[i]);
	a[0]=0; n=1;
	for(int i=5;i>=0;--i){
		for(int j=0;j<10*n;++j) b[j]=INF;
		for(int j=0;j<n;++j) b[j*10]=a[j];
		n*=10;
		opera2(b,n,f[i],k);
		for(int j=0;j<n;++j) a[j]=b[j];
	//	for(int j=0;j<100;++j) printf("[%lld %lld]",(ll)j,a[j]); puts("");
	}
	int q; scanf("%d",&q);
	while(q--){
		int x; scanf("%d",&x);
		printf("%lld\n",a[x]);
	}
	return 0;
}