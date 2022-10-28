#include <bits/stdc++.h>
using namespace std;
int val[505][505];
int dp[505];
int main() {
	for(int i=0; i<505; i++){
		for(int j=0; j<505; j++){
			val[i][j]=-1;
		}
	}
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	for(int i=0; i<n; i++){
		val[i][i]=arr[i];
	}
	for(int l=2; l<=n; l++){
		for(int i=0; i<=n-l; i++){
			for(int k=i; k<i+l-1; k++){
				if(val[i][k]==val[k+1][i+l-1] && val[i][k]!=-1){
					val[i][i+l-1]=val[i][k]+1;
				}
			}
		}
	}
	for(int i=0; i<505; i++){
		dp[i]=1000;
	}
	
	dp[0]=1;
	for(int i=1; i<n; i++){
		dp[i]=(min(dp[i], 1+dp[i-1]));
		
		if(val[0][i]!=-1){
			dp[i]=1;
			continue;
		}
		for(int l=2; l<=i; l++){
			if(val[i-l+1][i]!=-1){
				
				dp[i]=min(dp[i], 1+dp[i-l]);
			}
		}
	}
	
	cout<<dp[n-1];
	return 0;
}