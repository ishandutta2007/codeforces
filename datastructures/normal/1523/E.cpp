#include <iostream>
#include <cstdio>
#define int long long
#define mod 1000000007
using namespace std;
int t,n,k,ans;
int fac[100005],invfac[100005];
inline int Qpow(register int a,register int p){
	if (p==0)return 1;
	register int t=Qpow(a,p/2);
	t=t*t%mod;
	if (p%2==1)t=t*a%mod;
	return t;
}
inline int inv(register int x){
	return Qpow(x,mod-2);
}
inline int C(register int n,register int m){
	if (m>n||m<0)return 0;
	return fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
signed main(){
	fac[0]=1;
	for (register int i=1;i<=100000;i++)fac[i]=fac[i-1]*i%mod;
	invfac[100000]=inv(fac[100000]);
	for (register int i=99999;i>=0;i--)invfac[i]=invfac[i+1]*(i+1)%mod;
	cin>>t;
	while(t--){
		cin>>n>>k;
		ans=0;
		for (register int i=1;(i-1)*k+1<=n;i++)ans=(ans+C(n-(i-1)*(k-1),i)*inv(C(n,i))%mod)%mod;
		cout<<(ans+1)%mod<<endl;
	}
	return 0;
}