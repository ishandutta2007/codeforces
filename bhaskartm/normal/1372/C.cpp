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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		vector<int>vals;
		for(int i=0; i<n; i++){
			if(arr[i]!=i+1){
				vals.pb(i);
			}
		}
		if(vals.size()==0){
			cout<<0<<endl;
			continue;
		}
		if(vals.back()-vals[0]==vals.size()-1){
			cout<<1<<endl;
			continue;
		}
		cout<<2<<endl;
		continue;
	}
	return 0;
}