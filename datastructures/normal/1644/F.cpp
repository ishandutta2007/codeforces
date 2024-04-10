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
int n,k,fac[200005],invfac[200005],f[200005],g[200005],sumg[200005];
int ans[200005];
int work(int n){
	int m=min(n,k);
	for (int i=0;i<=m;i++)f[i]=Qpow(i,n)*invfac[i]%mod;
	for (int i=0;i<=m;i++){
		if (i&1)g[i]=(mod-invfac[i])%mod;
		else g[i]=invfac[i];
		if (i>0)sumg[i]=(sumg[i-1]+g[i])%mod;
		else sumg[i]=g[i];
	}
	int ans=0;
	for (int i=0;i<=m;i++)ans=(ans+f[i]*sumg[m-i])%mod;
	return ans;
}
signed main(){
	cin>>n>>k;
	if (n==1||k==1){
		cout<<1<<endl;
		return 0;
	}
	fac[0]=1;
	for (int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	invfac[n]=Qpow(fac[n],mod-2);
	for (int i=n-1;i>=0;i--)invfac[i]=invfac[i+1]*(i+1)%mod;
	for (int i=1;i<n;i++)ans[i]=work((n+i-1)/i);
	for (int i=n-1;i>=1;i--){
		for (int j=2*i;j<n;j+=i)
			ans[i]=(ans[i]+mod-ans[j])%mod;
		ans[i]--;
	}
	cout<<ans[1]<<endl;
	return 0;
}