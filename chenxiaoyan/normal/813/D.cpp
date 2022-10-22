/*









 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=5000,A_I=100000;
int n;
int a[N+1];
int dp[N+1][N+1];
int now1[A_I+2],now2[7];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<=n;i++){
		for(int j=1;j<=n;j++)now1[a[j]]=now2[a[j]%7]=0;
		for(int j=1;j<i;j++)now1[a[j]]=max(now1[a[j]],dp[i][j]),now2[a[j]%7]=max(now2[a[j]%7],dp[i][j]);
		for(int j=i+1;j<=n;j++)
			dp[i][j]=dp[j][i]=max(dp[i][0],max(max(now1[a[j]-1],now1[a[j]+1]),now2[a[j]%7]))+1,
			now1[a[j]]=max(now1[a[j]],dp[i][j]),now2[a[j]%7]=max(now2[a[j]%7],dp[i][j]);
	}
//	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)cout<<dp[i][j]<<(j<n?" ":"\n");
	cout<<*max_element(*dp,dp[n]+n+1);
	return 0;
}
/*1
4
1 2 4 5
*/
/*2
6
62 22 60 61 48 49
*/