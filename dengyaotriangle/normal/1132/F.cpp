#include<bits/stdc++.h>

using namespace std;

const int maxn=505;

int n;
char a[maxn];
int dp[maxn][maxn];

int main(){
	cin>>n>>(a+1);
	for(int i=1;i<=n;i++)dp[i][i]=1;
	for(int i=n;i>=1;i--){
		for(int j=i+1;j<=n;j++){
			dp[i][j]=dp[i+1][j]+1;
			for(int k=i+1;k<=j;k++){
				if(a[i]==a[k]){
					dp[i][j]=min(dp[i][j],dp[i+1][k-1]+dp[k][j]);
				}
			}
		}
	}
	cout<<dp[1][n];
	return 0;
}