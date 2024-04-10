#include <iostream>
#include <cstdio>
#define int long long
#define mod 1000000007
using namespace std;
inline int Qpow(int a,int p){
	if (p==0)return 1;
	int t=Qpow(a,p/2);
	t=t*t%mod;
	if (p%2)t=t*a%mod;
	return t;
}
inline int inv(int x){
	return Qpow(x,mod-2);
}
int n,m,a,b,fac[1000005],invfac[1000005],ans;
inline int A(int n,int m){
	return fac[n]*invfac[n-m]%mod;
}
inline int C(int n,int m){
	return fac[n]*invfac[n-m]%mod*invfac[m]%mod;
}
signed main(){
	fac[0]=invfac[0]=1;
	for (int i=1;i<=1000000;i++)
		fac[i]=fac[i-1]*i%mod,invfac[i]=invfac[i-1]*inv(i)%mod;
	cin>>n>>m>>a>>b;
	for (int i=1;i<=n-1;i++){
		if (i>m)break;
		int nowval=C(m-1,i-1);
		nowval=nowval*A(n-2,i-1)%mod;
		if (n-i>=2)nowval=nowval*(Qpow(n,n-i-2)*(i+1)%mod)%mod;
		nowval=nowval*Qpow(m,n-1-i)%mod;
		ans=(ans+nowval)%mod;
	}
	cout<<ans<<endl;
	return 0;
}
//(i+1)*(i+3)*...*(n-1)