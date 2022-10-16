#include <iostream>
#include <cstdio>
#include <cstring>
#define mod 998244353
using namespace std;
int Qpow(int a,int p){
	if (p==0)return 1;
	int t=Qpow(a,p/2);
	t=1ll*t*t%mod;
	if (p&1)t=1ll*t*a%mod;
	return t; 
}
int n;
int fac[1000005],invfac[1000005];
char s[1000005];
int C(int n,int m){
	if (m<0||m>n)return 0;
	return 1ll*fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
int n0[1000005],x[1000005],n1[1000005],y[1000005],ans;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	fac[0]=1;
	for (int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	invfac[n]=Qpow(fac[n],mod-2);
	for (int i=n-1;i>=0;i--)invfac[i]=1ll*invfac[i+1]*(i+1)%mod;
	for (int i=1;i<=n;i++)n0[i]=n0[i-1]+(s[i]=='('),x[i]=x[i-1]+(s[i]=='?');
	for (int i=n;i>=1;i--)n1[i]=n1[i+1]+(s[i]==')'),y[i]=y[i+1]+(s[i]=='?');
	for (int i=1;i<=n;i++){
		ans=(ans+1ll*x[i]*C(x[i]-1+y[i+1],y[i+1]-n0[i]+n1[i+1]-1)%mod)%mod;
		ans=(ans+1ll*n0[i]*C(x[i]+y[i+1],y[i+1]-n0[i]+n1[i+1])%mod)%mod;
	}
	cout<<ans<<endl;
	return 0;
}