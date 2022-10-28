#include <bits/stdc++.h>
using namespace std;
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
		vector<int>ans;
		ans.pb(arr[0]);
		for(int i=1; i<n-1; i++){
			if((arr[i]>arr[i-1] && arr[i]>arr[i+1]) ||(arr[i]<arr[i-1] && arr[i]<arr[i+1])){
				ans.pb(arr[i]);
			}
		}
		ans.pb(arr[n-1]);
		cout<<ans.size()<<endl;
		for(auto u:ans){
			cout<<u<<" ";
		}
		cout<<endl;
	}
	return 0;
}