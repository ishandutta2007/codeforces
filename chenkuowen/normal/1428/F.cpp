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
char a[N];
ll sum=0;
struct K{ int l,r,k; };
K merge(K x,K y){
	return (K){min(x.l,y.l),max(x.r,y.r),max(x.k,y.k)};
}
struct STK{
	K a[N];
	int t;
	STK(){ t=0; }
	int size(){ return t; }
	void opera(K x,int type){
		sum+=1ll*(x.r-x.l+1)*x.k*type;
	}
	void push(K x){
		opera(x,1);
		a[++t]=x;
	}
	K top(){ return a[t]; }
	void pop(){ 
		opera(a[t],-1);
		--t; 
	}
	void print(){
		for(int i=1;i<=t;++i) printf("[%d %d %d]",a[i].l,a[i].r,a[i].k);
		puts("");
	}
}stk;
int find(int l,int r){
	int ret=0;
	for(int x=l;x<=r;++x){
		int y=x;
		for(;y<=r;++y)
			if(a[y]=='0') break;
		ret=max(ret,y-x);
	}
//	printf("<%d %d %d>",l,r,ret);
	return ret;
}
int main(){
	int n; scanf("%d",&n);
	scanf("%s",a+1);
	ll cnt=0,ans=0;
	for(int i=n;i>=1;--i){
		if(a[i]=='0'){
			for(int j=cnt;j>=1;--j)
				stk.push((K){i+j,i+j,j});
			stk.push((K){i,i,0});
			cnt=0;
		}else{
			++cnt;
			if(stk.size()>0&&cnt>stk.top().k){
				K k=stk.top(); stk.pop();
				k.k=cnt;
				while(stk.size()>0&&cnt>stk.top().k)
					k=merge(k,stk.top()),stk.pop();
				stk.push(k);
			}
		}
//		printf("[%lld %lld]",cnt,sum);
//		stk.print();
		ll k1=1ll*cnt*(cnt+1)/2+sum,k2=0;
		ans+=k1;
//		for(int j=i;j<=n;++j)
//			k2+=find(i,j);
//		printf("{%lld %lld}",k1,k2);
	}
	printf("%lld\n",ans);
	return 0;
}