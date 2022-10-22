#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100+5;
int dp[N][N][N];
int C[N][N],fac[N];
int mod;
int dfs(int n,int m,int k){
	if(n==0) return (k==0);
	if(m==1) return (k==1?fac[n]:0);
	if(n==1) return (k==0);
	if(k*2>n+1) return 0;
	if(m>n) return (k==0?fac[n]:0);
	if(dp[n][m][k]!=-1) return dp[n][m][k];
	int ans=0;
	for(int l=0;l<n;l++){
		for(int a=0;a<=k;a++)
			ans=(ans+1ll*C[n-1][l]*dfs(l,m-1,a)%mod*dfs(n-l-1,m-1,k-a))%mod;
	}
	dp[n][m][k]=ans;
	return ans;
}
int n,m,k;
int main(){
	int i,j,d;
	cin>>n>>m>>k>>mod;
	for(i=0;i<N;i++)
		for(j=0;j<=i;j++){
			if(j==i||j==0) C[i][j]=1;
			else C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	fac[0]=1;
	for(i=1;i<N;i++) fac[i]=1ll*fac[i-1]*i%mod;
	memset(dp,-1,sizeof(dp));
	cout<<dfs(n,m,k);
	return 0;
}