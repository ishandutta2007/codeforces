#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
#define mod 998244353
using namespace std;
int Qpow(int a,int p){
	if (p==0)return 1;
	int t=Qpow(a,p/2);
	t=t*t%mod;
	if (p&1)t=t*a%mod;
	return t;
}
int n,fac[1000005],invfac[1000005];
int C(int n,int m){
	return fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
int f[1000005],ans;
signed main(){
	cin>>n;
	fac[0]=1;
	for (int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	invfac[n]=Qpow(fac[n],mod-2);
	for (int i=n-1;i>=0;i--)invfac[i]=invfac[i+1]*(i+1)%mod;
	for (int i=0;i<=n-2;i++)f[i]=C(n,i+1)*fac[i+1]%mod;
	for (int i=n-2;i>=1;i--)f[i]=(f[i]+mod-f[i-1])%mod;
	ans=fac[n]%mod;
	for (int i=1;i<=n-2;i++)ans=(ans+i*f[i])%mod;
	cout<<ans<<endl;
	return 0;
}