#include <bits/stdc++.h>
using namespace std;




int main() {
	int n, m;
	cin>>n>>m;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
		arr[i]=arr[i]%m;
	}
	if(n>m){
		cout<<"YES"<<endl;
		return 0;
	}
	int dp[n][m];
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			dp[i][j]=0;
		}
	}
	
	dp[0][arr[0]]=1;
	for(int i=1; i<n; i++){
		dp[i][arr[i]]=1;
		for(int j=0; j<m; j++){
			if(dp[i-1][j]==1){
				dp[i][(j+arr[i])%m]=1;
				dp[i][j]=1;
			}
			
		}
	}
	
	if(dp[n-1][0]==1){
		cout<<"YES";
	}
	else{
		cout<<"NO";
	}
	return 0;
}