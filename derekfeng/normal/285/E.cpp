#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
void add(int &a,int b){
	a+=b;
	if(a>=MOD)a-=MOD; 
}
int n,K,C[1003][1003],fac[1003];
int dp[1003][1003][2][2],ans[1003];
int main(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)add(C[i][j],C[i-1][j]),add(C[i][j],C[i-1][j-1]);
	}
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%MOD;
	dp[0][0][1][0]=1;
	for(int i=1;i<=n;i++)for(int j=0;j<=i-1;j++)
		for(int k=0;k<2;k++)for(int l=0;l<2;l++)if(dp[i-1][j][k][l]>0){
			add(dp[i][j][l][0],dp[i-1][j][k][l]);
			if(!k)add(dp[i][j+1][l][0],dp[i-1][j][k][l]);
			if(i<n)add(dp[i][j+1][l][1],dp[i-1][j][k][l]);
		}
	for(int i=0;i<=n;i++){
		for(int j=0;j<2;j++)for(int k=0;k<2;k++)add(ans[i],dp[n][i][j][k]);
		ans[i]=1ll*ans[i]*fac[n-i]%MOD;
	}
	int cur=-1;
	for(int i=K+1;i<=n;i++){
		add(ans[K],(1ll*cur*C[i][K]%MOD*ans[i]%MOD+MOD)%MOD);
		cur*=-1;
	}
	printf("%d",ans[K]);
}