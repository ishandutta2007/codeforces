#include <iostream>
#include <cstdio>
#define int long long
#define mod 998244353
using namespace std;
int n,m,a[505],f[505][505],g[505][505];
signed main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++)cin>>a[i];
	for (int i=1;i<=n+1;i++)f[i][i]=f[i][i-1]=g[i][i]=g[i][i-1]=1;
	for (int len=2;len<=n;len++)
		for (int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			int mn=1000000000,pos=0;
			for (int k=i;k<=j;k++)
				if (a[k]<mn)mn=a[k],pos=k;
			g[i][j]=f[i][pos-1]*f[pos+1][j]%mod;
			for (int k=i;k<=j;k++)
				f[i][j]=(f[i][j]+g[i][k]*f[k+1][j])%mod;
		}
	cout<<f[1][n]<<endl;
	return 0;
}