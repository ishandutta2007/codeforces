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
		vector<vector<int>>vec;
		vec.resize(n+1);
		for(int i=1; i<=n; i++){
			vec[i].pb(0);
		}
		for(int i=1; i<=n; i++){
			int x;
			cin>>x;
			vec[x].pb(i);
		}
		for(int i=1; i<=n; i++){
			vec[i].pb(n+1);
		}
		int ans[n+1];
		for(int i=1; i<=n; i++){
			ans[i]=-1;
		}
		int la=n+1;
		for(int i=1; i<=n; i++){
			if(vec[i].size()==2){
				continue;
			}
			int maxi=0;
			for(int j=0; j<vec[i].size()-1; j++){
				maxi=max(maxi, vec[i][j+1]-vec[i][j]);
			}
			if(maxi>=la){
				continue;
			}
			for(int j=maxi; j<la; j++){
				ans[j]=i;
			}
			la=maxi;
		}
		for(int i=1; i<=n; i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}