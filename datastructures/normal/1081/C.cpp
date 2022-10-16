#include <iostream>
#include <cstdio>
#define mod 998244353
#define int long long
using namespace std;
int n,m,k,f[3005][3005];
signed main(){
	cin>>n>>m>>k;
	f[1][0]=m;
	for (int i=2;i<=n;i++)
		for (int j=0;j<=k;j++){
			f[i][j]=f[i-1][j];
			if (j>0)f[i][j]=(f[i][j]+f[i-1][j-1]*(m-1))%mod;
		}
	cout<<f[n][k]<<endl;
	return 0;
}