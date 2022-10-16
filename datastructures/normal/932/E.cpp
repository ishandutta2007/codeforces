#include <iostream>
#include <cstdio>
#define int long long
#define mod 1000000007
using namespace std;
int Qpow(int a,int p){
	if (p==0)return 1;
	int t=Qpow(a,p/2);
	t=t*t%mod;
	if (p&1)t=t*a%mod;
	return t;
}
int inv(int x){
	return Qpow(x,mod-2);
}
int n,k,fac[5005],invfac[5005],f[5005],g[5005],ans;
int C(int n,int m){
	if (m<0||m>n)return 0;
	if (n<=k&&m<=k)return fac[n]*invfac[m]%mod*invfac[n-m]%mod;
	int ans=1;
	for (int i=n-m+1;i<=n;i++)ans=ans*i%mod;
	ans=ans*invfac[m]%mod;
	return ans;
}
signed main(){
	cin>>n>>k;
	fac[0]=1;
	for (int i=1;i<=k;i++)fac[i]=fac[i-1]*i%mod;
	invfac[k]=inv(fac[k]);
	for (int i=k-1;i>=0;i--)invfac[i]=invfac[i+1]*(i+1)%mod;
	for (int i=0;i<=k;i++)f[i]=Qpow(i,k);
	for (int i=0;i<=k;i++){
		for (int j=0;j<=i;j++){
			if ((i-j)&1)g[i]=(g[i]+mod-C(i,j)*f[j]%mod)%mod;
			else g[i]=(g[i]+C(i,j)*f[j]%mod)%mod;
		}
	}
	for (int i=1;i<=k;i++)ans=(ans+C(n,i)*g[i]%mod*Qpow(2,n-i))%mod;
	cout<<ans<<endl;
	return 0;
}