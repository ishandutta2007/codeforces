#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1010,mod=1e9+7;
int n,dp[2][N][N];
int main(){
	scanf("%d",&n);
	for(int i=n;i>=0;i--){
		for(int j=i;j>=0;j--){
			dp[0][i][j]=(max(dp[0][i+1][j],dp[1][i+1][j])+max(dp[0][i][j+1],dp[1][i][j+1]))%mod;
			if(i<n)dp[1][i][j]=dp[0][i+1][j]+max(dp[0][i][j+1],dp[1][i][j+1])+1;
			if(j<i)dp[1][i][j]=max(dp[1][i][j],dp[0][i][j+1]+max(dp[0][i+1][j],dp[1][i+1][j])+1);
			dp[1][i][j]%=mod;
		}
	}
	printf("%d",max(dp[0][0][0],dp[1][0][0]));
	return 0;
}