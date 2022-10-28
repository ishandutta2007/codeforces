#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int

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
		int arr[2*n];
		for(int i=0; i<2*n; i++){
			cin>>arr[i];
		}
		int maxi=-1;
		vector<int>v;
		for(int i=0; i<2*n; i++){
			if(arr[i]>maxi){
				maxi=arr[i];
				v.pb(1);
			}
			else{
				int val=v.back();
				v.pop_back();
				v.pb(1+val);
			}
		}
		int sz=v.size();
		int dp[sz][2*n+1];
		for(int i=0; i<sz; i++){
			for(int j=0; j<=2*n; j++){
				dp[i][j]=0;
			}
		}
		dp[0][0]=1;
		dp[0][v[0]]=1;
		for(int i=1; i<sz; i++){
			dp[i][v[i]]=1;
			dp[i][0]=1;
			for(int j=0; j<=2*n; j++){
				if(dp[i-1][j]==0){
					continue;
				}
				dp[i][j]=1;
				dp[i][j+v[i]]=1;
			}
		}
		if(dp[sz-1][n]==1){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}