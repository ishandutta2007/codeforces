/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
const int N=2000,M=N;
int n,m;
int dp[N+1][M+1];
int Sum[N+1][M+1],Sumk[N+1][M+1];
int sum[N+2];
int main(){
	cin>>n>>m;
	for(int i=2;i<=m;i++)dp[1][i]=1,Sum[1][i]=(Sum[1][i-1]+dp[1][i])%mod,Sumk[1][i]=(Sumk[1][i-1]-1ll*i*dp[1][i])%mod;
	for(int i=2;i<=n;i++)for(int j=2;j<=m;j++){
		dp[i][j]=(1ll*(j+1)*Sum[i-1][j]+Sumk[i-1][j]+1)%mod;
		Sum[i][j]=(Sum[i][j-1]+dp[i][j])%mod;
		Sumk[i][j]=(Sumk[i][j-1]-1ll*j*dp[i][j])%mod;
	}
	int ans=0;
	for(int k=2;k<=m;k++){
		for(int j=n;j;j--)sum[j]=(1ll*sum[j+1]+dp[n-j+1][k]-dp[n-j][k])%mod;
		for(int i=1;i<=n;i++)(ans+=1ll*(m-k+1)*(dp[i][k]-dp[i-1][k])%mod*sum[i]%mod)%=mod;
	}
	cout<<(ans+mod)%mod;
	return 0;
}