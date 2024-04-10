#include <bits/stdc++.h>
using namespace std;
#define int long long int

main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int pre[n];
	pre[0]=arr[0];
	for(int i=1; i<n; i++){
		pre[i]=pre[i-1]+arr[i];
	}
	int ans[n];
	for(int i=0; i<n; i++){
		ans[i]=0;
	}
	ans[n-1]=0;
	int maxi=pre[n-1];
	for(int i=n-2; i>=0; i--){
		ans[i]=maxi;
		maxi=max(maxi, pre[i]-ans[i]);
	}
	cout<<ans[0];
	return 0;
}