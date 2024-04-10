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
		int n, k;
		cin>>n>>k;
		int arr[n];
		int sum=0;
		vector<int>v;
		for(int i=0; i<n; i++){
			cin>>arr[i];
			sum+=arr[i];
			v.pb(arr[i]);
		}
		if(k>=(n-1)){
			cout<<sum<<endl;
			continue;
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		int ans=0;
		for(int i=0; i<=k; i++){
			ans+=v[i];
		}
	
		cout<<ans<<endl;
	}
	return 0;
}