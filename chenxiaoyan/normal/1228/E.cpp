#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int qpow(int x,int y){
	int res=1;
	while(y){
		if(y&1)res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return res;
}
int inv(int x){return qpow(x,mod-2);}
const int N=250;
int n,m;
int pw_m[N+1],pw_mm1[N+1],fact[N+1],factinv[N+1];
void init(){
	pw_m[0]=pw_mm1[0]=fact[0]=factinv[0]=1;
	for(int i=1;i<=n;i++)
		pw_m[i]=1ll*pw_m[i-1]*m%mod,
		pw_mm1[i]=1ll*pw_mm1[i-1]*(m-1)%mod,
		fact[i]=1ll*fact[i-1]*i%mod,
		factinv[i]=inv(fact[i]);
}
int C(int x,int y){return 1ll*fact[x]*factinv[x-y]%mod*factinv[y]%mod;}
int dp[N+1][N+1];
int main(){
	cin>>n>>m;
	init();
	dp[0][0]=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		for(int k=0;k<j;k++)
			(dp[i][j]+=1ll*dp[i-1][k]*pw_m[k]%mod*C(n-k,j-k)%mod*pw_mm1[n-j]%mod)%=mod;
		(dp[i][j]+=1ll*dp[i-1][j]*(((pw_m[j]-pw_mm1[j])%mod+mod)%mod)%mod*pw_mm1[n-j]%mod)%=mod;
//		printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
	}
	cout<<dp[n][n];
	return 0;
}
/*1
2 2
*/
/*2
123 456789
*/