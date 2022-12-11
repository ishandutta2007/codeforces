#include<bits/stdc++.h>
using namespace std;
const int N=60,mod=1e9+7;
int n,k,f[N][N][2],C[N][N];
int g(int x,int y){
	long long dat=1ll*C[x][y]*(y+1);
	if(x-y>1)dat*=(x-y);
	return dat%mod;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<=n;i++)C[i][0]=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	if(k>n/2)puts("0"),exit(0);f[0][0][1]=f[1][0][0]=1;
	for(int i=2;i<=n;i++)
		for(int j=0;j<=i/2;j++)
			for(int k=0;k<=i-2;k++)
				for(int l=0;l<=j;l++){
					f[i][j][0]=(f[i][j][0]+1ll*f[k+1][l][1]*f[i-2-k][j-l][1]%mod*g(i-2,k))%mod,
					l<j&&(f[i][j][1]=(f[i][j][1]+1ll*f[k+1][l][0]*f[i-2-k][j-1-l][1]%mod*g(i-2,k))%mod),
					l<j&&(f[i][j][1]=(f[i][j][1]+1ll*(f[k+1][l][0]+f[k+1][l][1])*f[i-2-k][j-1-l][0]%mod*g(i-2,k))%mod);
				}
	printf("%d\n",(f[n][k][0]+f[n][k][1])%mod);
	return 0;
}