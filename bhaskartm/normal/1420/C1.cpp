#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, q;
		cin>>n>>q;
		int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		int dp[n][2];
		int pre[n][2];
		for(int i=0; i<n; i++){
			for(int j=0; j<2; j++){
				dp[i][j]=-1e18;
				pre[i][j]=-1e18;
			}
		}
		dp[0][0]=arr[0];
		pre[0][0]=dp[0][0];
		for(int i=1; i<n; i++){
			dp[i][0]=arr[i];
			dp[i][0]=max(dp[i][0], arr[i]+pre[i-1][1]);
			dp[i][1]=-arr[i]+pre[i-1][0];
			pre[i][1]=max(pre[i-1][1], dp[i][1]);
			pre[i][0]=max(pre[i-1][0], dp[i][0]);
		}
		int maxi=0;
		for(int i=0; i<n; i++){
			maxi=max(maxi, dp[i][0]);
		}
		cout<<maxi<<endl;
		
	}
	return 0;
}