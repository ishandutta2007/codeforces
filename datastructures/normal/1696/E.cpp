#include <iostream>
#include <cstdio>
#define maxn 500000
#define mod 1000000007
#define int long long
using namespace std;
int n,a[500005],ans;
int fac[500005],invfac[500005];
int Qpow(int a,int p){
	if (p==0)return 1;
	int t=Qpow(a,p/2);
	t=t*t%mod;
	if (p&1)t=t*a%mod;
	return t;
}
int C(int n,int m){
	if (m>n||m<0)return 0;
	return fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
signed main(){
	cin>>n;
	for (int i=0;i<=n;i++)scanf("%lld",&a[i]);
	fac[0]=1;
	for (int i=1;i<=maxn;i++)fac[i]=fac[i-1]*i%mod;
	invfac[maxn]=Qpow(fac[maxn],mod-2);
	for (int i=maxn-1;i>=0;i--)invfac[i]=invfac[i+1]*(i+1)%mod;
	for (int i=0;i<=n;i++)ans=(ans+C(i+a[i],i+1))%mod;
	cout<<ans<<endl;
	return 0;
}