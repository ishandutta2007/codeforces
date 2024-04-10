#include <bits/stdc++.h>
using namespace std;
#define int long long int

int arr[2005];
int n, k;

bool f(int x){
	int dp[n];
	for(int i=0; i<n; i++){
		dp[i]=0;
	}
	dp[0]=0;
	for(int i=1; i<n; i++){
		dp[i]=i;
		for(int j=i-1; j>=0; j--){
			if(abs(arr[i]-arr[j])<=(i-j)*x){
				
				dp[i]=min(dp[i], i-j-1+dp[j]);
			}
		}
	}
	
	int ans=2005;
	for(int i=0; i<n; i++){
		ans=min(ans, dp[i]+n-i-1);
	}
	return (ans<=k);
}

main() {
	
	cin>>n>>k;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int l=0;
	int r=2000000000;
	
	int ans=-1;
	while(l<=r){
		int mid=(l+r)/2;
		
		if(f(mid)){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}