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
		int n, w;
		cin>>n>>w;
		vector<pair<int, int>>vec;
		for(int i=1; i<=n; i++){
			int x;
			cin>>x;
			vec.pb({x, i});
		}
		sort(vec.begin(), vec.end());
		reverse(vec.begin(), vec.end());
		int tot=0;
		vector<int>ans;
		for(int i=0; i<n; i++){
			if(tot+vec[i].f<=w){
				ans.pb(vec[i].s);
				tot+=vec[i].f;
			}
		}
		if(tot>=((w+1)/2)){
			cout<<ans.size()<<endl;
			sort(ans.begin(), ans.end());
			for(auto u:ans){
				cout<<u<<" ";
			}
			cout<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}
	return 0;
}