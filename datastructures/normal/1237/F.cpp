#include <iostream>
#include <cstdio>
#include <cstring>
#define mod 998244353
#define int long long
using namespace std;
int n,m,k,a[4005],b[4005],n1,n2;
int C[4005][4005],fac[2005],f[2005],g[2005],ans;
void upd_f(int len){
	for (int i=2000;i>=1;i--)
		for (int j=1;2*j<=len&&j<=i;j++)
			f[i]=(f[i]+f[i-j]*C[len-j][j])%mod;
	return;
}
void upd_g(int len){
	for (int i=2000;i>=1;i--)
		for (int j=1;2*j<=len&&j<=i;j++)
			g[i]=(g[i]+g[i-j]*C[len-j][j])%mod;
	return;
}
signed main(){
	cin>>n>>m>>k;
	for (int i=1;i<=k;i++){
		int xa,xb,ya,yb;
		cin>>xa>>ya>>xb>>yb;
		a[ya]=a[yb]=1;
		b[xa]=b[xb]=1;
	}
	for (int i=1;i<=m;i++)
		if (a[i]==0)n1++;
	for (int i=1;i<=n;i++)
		if (b[i]==0)n2++;
	for (int i=0;i<=4000;i++)C[i][0]=1;
	for (int i=1;i<=4000;i++)
		for (int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	fac[0]=1;
	for (int i=1;i<=2000;i++)fac[i]=fac[i-1]*i%mod;
	f[0]=1;
	for (int i=1;i<=m;i++){
		if (a[i]==1)continue;
		int j=i;
		while(j<=m&&a[j]==0)j++;
		upd_f(j-i);
		i=j-1;
	}
	g[0]=1;
	for (int i=1;i<=n;i++){
		if (b[i]==1)continue;
		int j=i;
		while(j<=n&&b[j]==0)j++;
		upd_g(j-i);
		i=j-1;
	}
	for (int i=0;2*i<=n1&&i<=n2;i++)
		for (int j=0;2*i+j<=n1&&2*j+i<=n2;j++)
			ans=(ans+f[i]*C[n1-2*i][j]%mod*g[j]%mod*C[n2-2*j][i]%mod*fac[i]%mod*fac[j]%mod)%mod;
	cout<<ans<<endl;
	return 0;
}