#include <iostream>
#include <cstdio>
#define mod 998244353
#define int long long
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
int n,m,k,x,ans,fac[5005],invfac[5005],S[5005][5005];
int C(int n,int m){
	if (m<0||m>n)return 0;
	int ans=1;
	for (int i=n-m+1;i<=n;i++)ans=ans*i%mod;
	return ans*invfac[m]%mod;
}
signed main(){
	cin>>n>>m>>k;
	if (m==1){
		cout<<Qpow(n,k)<<endl;
		return 0;
	}
	x=inv(m-1);
	S[0][0]=1;
	for (int i=1;i<=5000;i++)
		for (int j=1;j<=5000;j++)
			S[i][j]=(S[i-1][j-1]+S[i-1][j]*j)%mod;
	fac[0]=1;
	for (int i=1;i<=5000;i++)fac[i]=fac[i-1]*i%mod;
	invfac[5000]=inv(fac[5000]);
	for (int i=4999;i>=0;i--)invfac[i]=invfac[i+1]*(i+1)%mod;
	for (int j=0;j<=k;j++){
		int qwq=S[k][j]*fac[j]%mod*C(n,j)%mod;
		int awa=Qpow(x,j)*Qpow(x+1,n-j)%mod;
		ans=(ans+qwq*awa)%mod;
	}
	ans=ans*Qpow(m-1,n)%mod*Qpow(inv(m),n)%mod;
	cout<<ans<<endl;
	return 0;
}