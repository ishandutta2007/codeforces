#include <iostream>
#include <cstdio> 
#include <algorithm>
#define int long long
#define mod 998244353
using namespace std;
int n,a[5005],num[5005],f[5005][5005],sum[5005][5005],ans;
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++)
		while(a[num[i]+1]*2<=a[i])num[i]++;
	for (int i=1;i<=n;i++)f[1][i]=1,sum[1][i]=(sum[1][i-1]+f[1][i])%mod;
	for (int i=2;i<=n;i++){
		for (int j=1;j<=n;j++){
			f[i][j]=f[i-1][j]*(num[j]-(i-2));
			f[i][j]=(f[i][j]+sum[i-1][num[j]])%mod;
			sum[i][j]=(sum[i][j-1]+f[i][j])%mod;
			if (i==n)ans=(ans+f[i][j])%mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}