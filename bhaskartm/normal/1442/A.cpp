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
		if(n<=2){
			cout<<"YES"<<endl;
			continue;
		}
		int mini=arr[0];
		for(int i=1; i<n; i++){
			if(arr[i]<arr[i-1]){
				mini-=(arr[i-1]-arr[i]);
			}
		}
		if(mini<0){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}