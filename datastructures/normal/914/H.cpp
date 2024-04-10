#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int n,d,mod;
int C[205][205],f[205][205],sum[205][205],ans;
signed main(){
	cin>>n>>d>>mod;
	for (int i=0;i<=n;i++)C[i][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	f[1][0]=sum[1][0]=1;
	for (int i=2;i<=n;i++)
		for (int j=1;j<=i-1;j++){
			for (int k=1;k<i;k++)
				f[i][j]=(f[i][j]+f[i-k][j-1]*sum[k][min(d-1,k-1)]%mod*C[i-2][k-1])%mod;
			sum[i][j]=(sum[i][j-1]+f[i][j])%mod;
		}
	for (int i=1;i<=n;i++)
		for (int j=0;j<=d;j++)
			for (int k=0;j+k<=d;k++)
				if (j!=1)ans=(ans+f[i][j]*f[n-i+1][k])%mod;
	cout<<ans*n*(n-1)*2%mod<<endl;
	return 0;
}