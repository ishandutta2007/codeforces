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
		vector<pair<int, int>>v;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			if(v.empty() || v.back().f!=x){
				v.pb({x, 1});
			}
			else{
				auto u=v.back();
				v.pop_back();
				v.pb({x, u.s+1});
			}
		}
		int ans=0;
		for(int i=1; i<v.size()-1; i++){
			if(v[i].f==0){
				ans+=v[i].s;
				
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}