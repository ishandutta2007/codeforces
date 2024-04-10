#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define f first
#define s second
#define pb push_back

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	if(n==1){
		cout<<arr[0];
		return 0;
	}
	int sum=0;
	for(int i=0; i<n; i=i+2){
		sum+=arr[i];
	}
	int maxi=sum;
	int pre[n];
	int suf[n];
	pre[0]=arr[0];
	pre[1]=arr[1];
	for(int i=2; i<n; i++){
		pre[i]=arr[i]+pre[i-2];
	}
	suf[n-1]=arr[n-1];
	suf[n-2]=arr[n-2];
	for(int i=n-3; i>=0; i--){
		suf[i]=suf[i+2]+arr[i];
	}
	for(int i=0; i<n-1; i++){
		maxi=max(maxi, pre[i]+suf[i+1]);
	}
	cout<<maxi;
	return 0;
}