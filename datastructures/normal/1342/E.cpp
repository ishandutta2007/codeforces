#include <iostream>
#include <cstdio>
#define int long long
#define mod 998244353
using namespace std;
int n,k,fac[200005],invfac[200005],ans;
inline int Qpow(register int a,register int p){
	if (p==0)return 1;
	register int t=Qpow(a,p/2);
	t=t*t%mod;
	if (p%2)t=t*a%mod;
	return t;
}
inline int inv(register int a){
	return Qpow(a,mod-2);
}
inline int C(register int n,register int m){
	if (m>n)return 0;
	return fac[n]*invfac[n-m]%mod*invfac[m]%mod;
}
signed main(){
	cin>>n>>k;
	fac[0]=1;
	for (register int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	invfac[n]=inv(fac[n]);
	for (register int i=n-1;i>=0;i--)invfac[i]=invfac[i+1]*(i+1)%mod;
	if (k==0){
		cout<<fac[n]<<endl;
		return 0;
	}
	if (k>=n){
		puts("0");
		return 0;
	}
	k=n-k;
	for (register int i=1;i<=k;i++){
		if ((k-i)%2==0)ans=(ans+C(k,i)*Qpow(i,n)%mod)%mod;
		else ans=(ans+mod-C(k,i)*Qpow(i,n)%mod)%mod;
	}
	ans=ans*C(n,k)%mod*2%mod;
	cout<<ans<<endl;
	return 0;
}