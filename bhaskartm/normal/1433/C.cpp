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
		int maxi=0;
		int mini=2e9;
		int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
			maxi=max(maxi, arr[i]);
			mini=min(mini, arr[i]);
		}
		if(maxi==mini){
			cout<<-1<<endl;
			continue;
		}
		int pt=-1;
		for(int i=0; i<n; i++){
			if(arr[i]!=maxi){
				continue;
			}
			if(i>0 && arr[i]>arr[i-1]){
				pt=i+1;
				break;
			}
			if(i<n-1 && arr[i]>arr[i+1]){
				pt=i+1;
				break;
			}
		}
		cout<<pt<<endl;
	}
	return 0;
}