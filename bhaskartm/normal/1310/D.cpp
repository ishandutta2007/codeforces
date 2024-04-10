#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin>>n>>k;
	srand (time(NULL));
	int arr[n][n];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>arr[i][j];
		}
	}
	int mini=2e9;
	for(int g=0; g<10000; g++){
		int color[n];
		for(int i=0; i<n; i++){
			int x=rand();
			if(x%2==0){
				color[i]=1;
			}
			else{
				color[i]=0;
			}
		}
		int dp[n][k+1];
		for(int i=0; i<n; i++){
			for(int j=0; j<k+1; j++){
				dp[i][j]=2e9;
			}
		}
		dp[0][0]=0;
		for(int i=1; i<=k; i++){
			for(int j=0; j<n; j++){
				for(int k=0; k<n; k++){
					if(j==k || color[j]==color[k]){
						continue;
					}
					dp[j][i]=min(dp[j][i], dp[k][i-1]+arr[k][j]);
				}
			}
		}
		mini=min(mini, dp[0][k]);
	}
	cout<<mini;
	return 0;
}