#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
int n,m,mod;
ll C[505][505],f[505][2],g[505][505][2];
int gs(int x){
	return x*(x+1)/2;
}
int main(){
	cin>>n>>m>>mod;
	for (int i=0;i<=n;i++)C[i][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++){
			C[i][j]=C[i-1][j-1]+C[i-1][j];
			if (C[i][j]>=mod)C[i][j]-=mod;
		}
	f[0][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++){
			f[i][0]=(f[i][0]+(i+1)*f[j-1][0]%mod*f[i-j][0]%mod*C[i-1][j-1])%mod;
			f[i][1]=(f[i][1]+(i+1)*f[j-1][0]%mod*f[i-j][1]%mod*C[i-1][j-1]+(i+1)*f[j-1][1]%mod*f[i-j][0]%mod*C[i-1][j-1])%mod;
			f[i][1]=(f[i][1]+(gs(j-1)+gs(i-j))*f[j-1][0]%mod*f[i-j][0]%mod*C[i-1][j-1])%mod;
		}
	g[0][0][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=i;j++){
			g[i][j][0]=g[i-1][j][0],g[i][j][1]=g[i-1][j][1];
			for (int k=1;k<=j;k++){
				if (k<i){
					g[i][j][0]=(g[i][j][0]+g[i-k-1][j-k][0]*f[k][0]%mod*C[j][k])%mod;
					g[i][j][1]=(g[i][j][1]+g[i-k-1][j-k][0]*f[k][1]%mod*C[j][k]+g[i-k-1][j-k][1]*f[k][0]%mod*C[j][k])%mod;
				}
				else{
					g[i][j][0]=(g[i][j][0]+f[k][0])%mod;
					g[i][j][1]=(g[i][j][1]+f[k][1])%mod;
				}
			}
		}
	cout<<g[n][m][1]<<endl;
	return 0;
}