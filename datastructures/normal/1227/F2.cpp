#include <iostream>
#include <cstdio>
#define mod 998244353
#define int long long
using namespace std;
int n,k,m,h[200005];
int fac[200005],invfac[200005],inv2;
int ans;
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
inline int nxt(register int a){
	return (a==n)?1:(a+1);
}
inline int C(register int n,register int m){
	if (m>n)return 0;
	return fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
inline int work(register int x){
	if (x%2==1)return Qpow(2,x-1);
	return (Qpow(2,x-1)-C(x,x/2)*inv2%mod+mod)%mod;
}
signed main(){
	cin>>n>>k;
	if (k==1){
		puts("0");
		return 0;
	}
	for (register int i=1;i<=n;i++)scanf("%lld",&h[i]);
	for (register int i=1;i<=n;i++)
		if (h[i]!=h[nxt(i)])m++;
	fac[0]=1;
	for (register int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	invfac[n]=inv(fac[n]);
	inv2=inv(2);
	for (register int i=n-1;i>=0;i--)invfac[i]=invfac[i+1]*(i+1)%mod;
	for (register int i=1;i<=m;i++){
		register int now=Qpow(k-2,m-i)*C(m,i)%mod;
		now=now*work(i)%mod;
		ans=(ans+now)%mod;
	}
	ans=ans*Qpow(k,n-m)%mod;
	cout<<ans<<endl;
	return 0;
}