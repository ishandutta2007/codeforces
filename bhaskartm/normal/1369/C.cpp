#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define  pb push_back
#define  f first
#define  s second

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
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		vector<int>sz;
		for(int i=0; i<k; i++){
			int x;
			cin>>x;
			sz.pb(x);
		}
		sort(sz.begin(), sz.end());
		reverse(sz.begin(), sz.end());
		sort(arr, arr+n);
		vector<vector<int>>v;
		v.resize(k);
		int pt2=n-k;
		int pt1=0;
		for(int i=0; i<k; i++){
			for(int j=0; j<sz[i]-1; j++){
				v[i].pb(arr[pt1]);
				pt1++;
			}
			v[i].pb(arr[pt2]);
			pt2++;
		}
		int sum=0;
		for(int i=0; i<k; i++){
			sum+=v[i][0];
			sum+=v[i].back();
		}
		cout<<sum<<endl;
	}
	return 0;
}