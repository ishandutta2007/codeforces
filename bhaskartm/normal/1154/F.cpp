#include <bits/stdc++.h>
using namespace std;
int maxi[2005];
int main() {
	int n, m, k;
	cin>>n>>m>>k;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	for(int i=0; i<m; i++){
		int x, y;
		cin>>x>>y;
		if(x>2000){
			continue;
		}
		maxi[x]=max(maxi[x], y);
	}
	sort(arr, arr+n);
	
	vector<int>v;
	for(int i=0; i<k; i++){
		v.push_back(arr[i]);
	}
	
	int dp[k];
	for(int i=0; i<k; i++){
		dp[i]=pow(10, 9);
	}
	
	for(int i=1; i<=1; i++){
		if(maxi[i]==i){
			
			cout<<0;
			return 0;
		}
	}
	
	int pre[k+1];
	pre[0]=0;
	pre[1]=v[0];
	
	for(int i=2; i<=k; i++){
		pre[i]=pre[i-1]+v[i-1];
	}
	dp[0]=v[0];
	
	for(int i=1; i<k; i++){
		dp[i]=min(dp[i], v[i]+dp[i-1]);
		for(int j=1; j<=i+1; j++){
			int val=maxi[j];
			dp[i]=min(dp[i], dp[i-j]+pre[i+1]-pre[i-j+val+1]);
		}
	}
	cout<<dp[k-1]<<endl;
	return 0;
}