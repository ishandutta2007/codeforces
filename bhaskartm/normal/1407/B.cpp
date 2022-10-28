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
		multiset<int>se;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			se.insert(x);
		}
		vector<int>ans;
		int gc=0;
		int maxi=0;
		int ind=-1;
		for(int i=0; i<n; i++){
			for(auto u:se){
				if(__gcd(gc, u)>maxi){
					maxi=__gcd(gc, u);
					ind=u;
				}
			}
			ans.pb(ind);
			se.erase(se.find(ind));
			gc=maxi;
			maxi=0;
		}
		for(auto u:ans){
			cout<<u<<" ";
		}
		cout<<endl;
	}
	return 0;
}