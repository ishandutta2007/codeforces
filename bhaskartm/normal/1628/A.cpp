#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define T long double



 
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--){
		
		int n;
		vector<vector<int>>vec;
		cin>>n;
		int arr[n];
		vec.resize(n+1);
		for(int i=0; i<n; i++){
			cin>>arr[i];
			vec[arr[i]].pb(i);
		}
		
		for(int i=0; i<=n; i++){
			reverse(vec[i].begin(), vec[i].end());
		}
		
		
		int pt=0;
		vector<int>ans;
		while(pt<n){
			int num=pt;
			int fin=0;
			for(int i=0; i<=n; i++){
				fin++;
				bool che=1;
				while(1){
					if(vec[i].empty()){
						che=0;
						break;
					}
					if(vec[i].back()<pt){
						vec[i].pop_back();
						continue;
					}
					num=max(num, vec[i].back());
					break;
				}
				if(!che){
					break;
				}
			}
			ans.pb(fin);
			pt=num+1;
		}
		cout<<ans.size()<<endl;
		for(auto u:ans){
			cout<<u-1<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}