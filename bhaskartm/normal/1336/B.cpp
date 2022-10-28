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
		int a, b, c;
		cin>>a>>b>>c;
		vector<int>vec[3];
		
		for(int i=0; i<a; i++){
			int x;
			cin>>x;
			vec[0].pb(x);
		}
		for(int i=0; i<b; i++){
			int x;
			cin>>x;
			vec[1].pb(x);
		}
		for(int i=0; i<c; i++){
			int x;
			cin>>x;
			vec[2].pb(x);
		}
		for(int i=0; i<3; i++){
			sort(vec[i].begin(), vec[i].end());
		}
		int ans=8e18;
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				for(int k=0; k<3; k++){
					if(i==j || i==k || j==k){
						continue;
					}
					for(auto u:vec[i]){
						auto it=lower_bound(vec[j].begin(), vec[j].end(), u);
						if(it==vec[j].end()){
							continue;
						}
						auto it2=upper_bound(vec[k].begin(), vec[k].end(), u);
						if(it2==vec[k].begin()){
							continue;
						}
						it2--;
						int big=(*it);
						int sm=(*it2);
						ans=min(ans, (big-sm)*(big-sm)+(u-sm)*(u-sm)+(u-big)*(u-big));
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}