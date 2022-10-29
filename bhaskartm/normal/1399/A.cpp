#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define pb push_back
#define f first
#define s second

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
		sort(arr, arr+n);
		bool che=1;
		for(int i=0; i<n-1; i++){
			if(arr[i+1]>1+arr[i]){
				che=0;
			}
		}
		if(che){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}