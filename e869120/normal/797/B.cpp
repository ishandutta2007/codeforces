#include<bits/stdc++.h>
using namespace std;
long long dp[100009][2],n,a[100009],p=(1LL<<60);
int main(){
	cin>>n;for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<=n;i++){dp[i][0]=-(1LL<<60);dp[i][1]=-(1LL<<60);}
	dp[0][0]=0;
	for(int i=0;i<n;i++){
		dp[i+1][0]=max(dp[i+1][0],dp[i][0]);
		dp[i+1][1]=max(dp[i+1][1],dp[i][1]);
		dp[i+1][(0LL+a[i]+p)%2]=max(dp[i+1][(0LL+a[i]+p)%2],dp[i][0]+a[i]);
		dp[i+1][(1LL+a[i]+p)%2]=max(dp[i+1][(1LL+a[i]+p)%2],dp[i][1]+a[i]);
	}
	long long maxn=-p;for(int i=0;i<=n;i++)maxn=max(maxn,dp[i][1]);
	cout<<maxn<<endl;
	return 0;
}