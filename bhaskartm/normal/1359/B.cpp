#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define int long long int
#define pb push_back

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--){
		int n, m, x, y;
		cin>>n>>m>>x>>y;
		char arr[n][m];
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin>>arr[i][j];
			}
		}
		int ans=0;
		bool booly=false;
		if(y<2*x){
			booly=true;
		}
		vector<pair<int, int>>v;
		for(int i=0; i<n; i++){
			if(arr[i][0]=='*'){
				v.pb({1, 1});
			}
			else{
				v.pb({1, 0});
			}
			for(int j=1; j<m; j++){
				if(v[v.size()-1].s==1 && arr[i][j]=='*'){
					int val=v[v.size()-1].f;
					v.pop_back();
					v.pb({val+1, 1});
					continue;
				}
				if(v[v.size()-1].s==1 && arr[i][j]=='.'){
					v.pb({1, 0});
					continue;
				}
				if(v[v.size()-1].s==0 && arr[i][j]=='*'){
					v.pb({1, 1});
					continue;
				}
				if(v[v.size()-1].s==0 && arr[i][j]=='.'){
					int val=v[v.size()-1].f;
					v.pop_back();
					v.pb({val+1, 0});
				}
			}
			for(auto u:v){
				if(u.s==1){
					continue;
				}
				int sz=u.f;
				if(booly){
					ans=ans+y*(sz/2)+x*(sz%2);
				}
				else{
					ans=ans+x*sz;
				}
			}
			v.clear();
		}
		cout<<ans<<endl;
	}
	return 0;
}