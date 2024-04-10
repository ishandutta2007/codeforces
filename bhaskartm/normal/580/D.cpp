#include <bits/stdc++.h>
using namespace std;
#define int long long int
 main() {
	int n, m, k;
	cin>>n>>m>>k;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int cost[n][n];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cost[i][j]=0;
		}
	}
	for(int i=0; i<k; i++){
		int x, y, c;
		cin>>x>>y>>c;
		x--;
		y--;
		cost[x][y]=c;
	}
	int dp[1LL<<n][n];
	for(int i=0; i<(1<<n); i++){
		for(int j=0; j<n; j++){
			dp[i][j]=0;
		}
	}
	for(int i=0; i<n; i++){
		dp[(1LL<<i)][i]=arr[i];
	}
	for(int i=0; i<(1LL<<n); i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<n; k++){
				if(((i & (1<<k))==0) && ((i & (1<<j))==(1<<j))){
					
					dp[i+(1<<k)][k]=max(dp[i+(1<<k)][k], dp[i][j]+arr[k]+cost[j][k]);
				}
			}
		}
	}
	
	int maxi=0;
	for(int i=0; i<(1LL<<n); i++){
		if(__builtin_popcount(i)!=m){
			continue;
		}
		for(int j=0; j<n; j++){
			maxi=max(maxi, dp[i][j]);
		}
	}
	cout<<maxi;
	return 0;
}