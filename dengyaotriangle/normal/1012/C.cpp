#include<bits/stdc++.h>

using namespace std;

const int maxn=5005;

long long dp[maxn][maxn/2][3];
int n;
int a[maxn];

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==1){
		cout<<0;return 0;
	}else if(n==2){
		cout<<(a[1]==a[2]);return 0;
	}
	a[n+1]=-100; 
	memset(dp,0x3f,sizeof(dp));
	dp[1][0][0]=0;
	dp[1][1][1]=max(0,a[2]-a[1]+1);
	int s=(n+1)/2;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=s;j++){
			dp[i][j][0]=min(dp[i-1][j][2],dp[i-1][j][0]);
			dp[i][j][2]=dp[i-1][j][1];
			if(j)dp[i][j][1]=min(dp[i-1][j-1][0]+max(0,a[i+1]-a[i]+1)+max(0,a[i-1]-a[i]+1),dp[i-1][j-1][2]+max(0,a[i+1]-a[i]+1)+max(0,min(a[i-2]-1,a[i-1])-a[i]+1)); 
		} 
	} 
	for(int i=1;i<=s;i++){
		cout<<min(dp[n][i][0],min(dp[n][i][1],dp[n][i][2]))<<' ';
	}
	return 0;
}