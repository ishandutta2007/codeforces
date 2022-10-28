#include <bits/stdc++.h>
using namespace std;
long long int INF;
int main() {
	INF=1000000000000000000;
	int n;
	cin>>n;
	pair<long long int, long long int>arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i].first;
		arr[i].second=i;
	}
	sort(arr, arr+n);
	pair<long long int, long long int> dp[n];
	dp[0]={INF, 0};
	dp[1]={INF, 0};
	dp[2]={arr[2].first-arr[0].first, 3};
	if(n>3){
	dp[3]={arr[3].first-arr[0].first, 4};
	}
	if(n>4){
	dp[4]={arr[4].first-arr[0].first, 5};
	}
	for(int i=5; i<n; i++){
		long long int val1=dp[i-5].first+arr[i].first-arr[i-4].first;
		long long int val2=dp[i-4].first+arr[i].first-arr[i-3].first;
		long long int val3=dp[i-3].first+arr[i].first-arr[i-2].first;
		
		int mini=5;
		if(val2<val1){
			mini=4;
		}
		if(val3<val1 && val3<val2){
			mini=3;
		}
		if(mini==5){
			dp[i]={val1, 5};
		}
		if(mini==4){
			dp[i]={val2, 4};
		}
		if(mini==3){
			dp[i]={val3,3};
		}
		
	}
	int j=n-1;
	int index[n];
	int val=1;
	
	while(j>=0){
		int x=dp[j].second;
		for(int i=0; i<x; i++){
			index[arr[j-i].second]=val;
		}
		val++;
		j=j-x;
		
	}
	
	int maxi=0;
	for(int i=0; i<n;i++){
		maxi=max(maxi, index[i]);
	}
	cout<<dp[n-1].first<<" "<<maxi<<endl;
	for(int i=0; i<n; i++){
		cout<<index[i]<<" ";
	}
	return 0;
}