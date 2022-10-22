#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7,N=1<<20|5;
inline int mo1(int x){ return x>=MOD?x-MOD:x; }
inline void mo(int& x){ x>=MOD?x-=MOD:0; }
inline int fpow(int x,int n,int ret=1){
	for(;n;n>>=1,x=1ll*x*x%MOD)
		if(n&1) ret=1ll*ret*x%MOD;
	return ret;
}
int inv[N],fac[N],ifac[N];
inline int comb(int n,int m){
	if(n<m||n<0||m<0) return 0;
	return 1ll*fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
}
struct II{
	II(){
		inv[1]=fac[0]=ifac[0]=1;
		for(int i=1;i<N;++i){
			fac[i]=1ll*fac[i-1]*i%MOD;
			if(i>1) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
			ifac[i]=1ll*ifac[i-1]*inv[i]%MOD;
		}
	}
}__ii;
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n,k; scanf("%d%d",&n,&k);
		int ans=fac[n];
		for(int i=1;(i-1)*k+1<=n;++i)
			ans=(ans+1ll*comb(n-(i-1)*k-1+i,i)*fac[i]%MOD*fac[n-i])%MOD;
		ans=1ll*ans*ifac[n]%MOD;
		printf("%d\n",ans);
	}
	return 0;
}