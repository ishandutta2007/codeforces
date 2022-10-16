#include <iostream>
#include <cstdio>
#define int long long
#define mod 1000000007
using namespace std;
int n,k,f[405][405],dp[405][405],d[405][405],g[405];
int fac[10005],invfac[10005];
inline int Qpow(register int a,register int p){
	if (p==0)return 1;
	register int t=Qpow(a,p/2);
	t=t*t%mod;
	if (p%2==1)t=t*a%mod;
	return t;
}
inline int inv(register int a){
	return Qpow(a,mod-2);
}
inline int C(register int n,register int m){
	if (m>n)return 0;
	if (n<=10000)return fac[n]*invfac[m]%mod*invfac[n-m]%mod;
	register int ans=1;
	for (register int i=n-m+1;i<=n;i++)ans=ans*i%mod;
	ans=ans*invfac[m]%mod;
	return ans;
}
signed main(){
//	freopen("1516E.in","r",stdin);
//	freopen("1516E.out","w",stdout);
	cin>>n>>k;
	f[0][0]=1;
	for (register int i=1;i<=min(n,2*k);i++)
		for (register int j=1;j<=i;j++)
			f[i][j]=(f[i-1][j-1]+(i-1)*f[i-1][j])%mod;
	for (register int i=1;i<=min(n,2*k);i++)
		for (register int j=0;j<=i;j++)
			dp[i][j]=f[i][i-j];
	fac[0]=1;
	for (register int i=1;i<=10000;i++)fac[i]=fac[i-1]*i%mod;
	invfac[10000]=inv(fac[10000]);
	for (register int i=9999;i>=0;i--)invfac[i]=invfac[i+1]*(i+1)%mod;
	for (register int i=1;i<=min(n,2*k);i++)
		for (register int j=1;j<=i;j++){
			for (register int l=0;l<=i;l++){
				if ((i-l)%2==0)d[i][j]=(d[i][j]+dp[l][j]*C(i,l)%mod)%mod;
				else d[i][j]=(d[i][j]-dp[l][j]*C(i,l)%mod+mod)%mod;
			}
		}
	g[0]=1;
	for (register int j=1;j<=k;j++)
		for (register int i=1;i<=min(n,2*k);i++)
			g[j]=(g[j]+d[i][j]*C(n,i))%mod;
	for (register int i=1;i<=k;i++){
		if (i>1)g[i]=(g[i]+g[i-2])%mod;
		cout<<g[i]<<' ';
	}
	cout<<endl;
	return 0;
}