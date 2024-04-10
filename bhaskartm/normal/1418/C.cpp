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
		int n;
		cin>>n;
		int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		int dp[n][2];
		for(int i=0; i<n; i++){
			for(int j=0; j<2; j++){
				dp[i][j]=1e9;
			}
		}
		if(n==1 && arr[0]==1){
			cout<<1<<endl;
			continue;
		}
		if(n==1 && arr[0]==0){
			cout<<0<<endl;
			continue;
		}
		if(n==2 && arr[0]==1){
			cout<<1<<endl;
			continue;
		}
		if(n==2 && arr[0]==0){
			cout<<0<<endl;
			continue;
		}
		dp[0][1]=arr[0];
		dp[1][1]=arr[0]+arr[1];
		dp[1][0]=arr[0];
		for(int i=2; i<n; i++){
			dp[i][0]=min(dp[i-1][1], dp[i-2][1]);
			dp[i][1]=min(dp[i-1][0]+arr[i], dp[i-2][0]+arr[i]+arr[i-1]);
		}
		cout<<min(dp[n-1][0], dp[n-1][1])<<endl;
	}
	return 0;
}