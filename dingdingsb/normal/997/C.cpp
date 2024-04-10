#pragma optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+10,mod=998244353;
int fac[maxn],inv[maxn];//
inline int quick_pow(int base,int b){
	int ret=1;
	while(b){
		if(b&1)(ret*=base)%=mod;
		(base*=base)%=mod,b>>=1;
	}
	return ret;
} 
inline int C(int x,int y){
	//x!/y!(x-y)!
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}//C
signed main(){
	int n,ans=0,tmp=0;
	scanf("%lld",&n);
	fac[0]=1;inv[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%mod;
		inv[i]=quick_pow(fac[i],mod-2);
	}
	for(int i=1;i<=n;i++)
		(ans+=2*quick_pow(3,n*(n-i)+i)*quick_pow(-1,i+1)*C(n,i)%mod+mod)%=mod;
	for(int i=0;i<n;i++){
		int t=-quick_pow(3,i);
		(ans+=3*(C(n,i)*quick_pow(-1,i+1)*(quick_pow(1+t,n)-quick_pow(t,n)+mod)%mod+mod)%mod)%=mod;
	}
	cout<<ans;
}