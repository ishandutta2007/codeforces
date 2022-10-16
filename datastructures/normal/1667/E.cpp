#include <iostream>
#include <cstdio>
#define mod 998244353
#define int long long
using namespace std;
int n;
int fac[200005],invfac[200005];
int f[200005],g[200005],sum;
int Qpow(int a,int p){
	if (p==0)return 1;
	int t=Qpow(a,p/2);
	t=t*t%mod;
	if (p&1)t=t*a%mod;
	return t;
}
int C(int n,int m){
	if (m<0||m>n)return 0;
	return fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
int inv(int x){
	return invfac[x]*fac[x-1]%mod;
}
signed main(){
	cin>>n;
	fac[0]=1;
	for (int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	invfac[n]=Qpow(fac[n],mod-2);
	for (int i=n-1;i>=0;i--)invfac[i]=invfac[i+1]*(i+1)%mod;
	for (int i=n;i>=1;i--){
		if (i>1)f[i]=fac[i-1]*fac[n-i]%mod*C((n-1)/2,i-1)%mod;
		else f[i]=fac[n-1];
		g[i]=(f[i]+mod-sum)%mod;
		if (i>1)sum=(sum+f[i]*inv(i-1))%mod;
	}
	for (int i=1;i<=n;i++)printf("%lld ",g[i]);
	printf("\n");
	return 0;
}