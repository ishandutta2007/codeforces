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
		int val=0;
		int pre[n];
		for(int i=0; i<n; i++){
			pre[i]=0;
		}
		for(int i=1; i<n-1; i++){
			if((arr[i]>arr[i-1] && arr[i]>arr[i+1]) || (arr[i]<arr[i-1] && arr[i]<arr[i+1])){
				val++;
				pre[i]=1;
			}
		}
		int mini=val;
		if(n<=3){
			cout<<0<<endl;
			continue;
		}
		if(pre[1]){
			mini=min(mini, val-1);
		}
		if(pre[n-2]){
			mini=min(mini, val-1);
		}
		for(int i=1; i<n-1; i++){
			int num1=pre[i-1]+pre[i]+pre[i+1];
			if(i==1 || i==n-2){
				mini=min(mini, val-num1);
				continue;
			}
			if(arr[i+1]>arr[i-1] && arr[i+2]<arr[i+1] && arr[i-2]>arr[i-1]){
				mini=min(mini, val-num1+1);
				continue;
			}
			if(arr[i+1]<arr[i-1] && arr[i+2]>arr[i+1] && arr[i-1]>arr[i-2]){
				mini=min(mini, val-num1+1);
				continue;
			}
			mini=min(mini, val-num1);
		}
		cout<<mini<<endl;
	}
	return 0;
}