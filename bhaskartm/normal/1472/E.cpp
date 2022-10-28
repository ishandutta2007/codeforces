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
		int h[n];
		int w[n];
		map<int, int>ma;
		set<int>se;
		int pt=0;
		for(int i=0; i<n; i++){
			cin>>h[i]>>w[i];
			se.insert(h[i]);
			se.insert(w[i]);
		}
		for(auto u:se){
			ma[u]=pt;
			pt++;
		}
		for(int i=0; i<n; i++){
			h[i]=ma[h[i]];
			w[i]=ma[w[i]];
		}
		vector<vector<pair<int, int>>>vec;
		vec.resize(2*n+5);
		for(int i=0; i<n; i++){
			vec[h[i]].pb({w[i], i});
			vec[w[i]].pb({h[i], i});
		}
		int ans[n];
		for(int i=0; i<n; i++){
			ans[i]=-2;
		}
		int ind=-1;
		int mini=10000000;
		for(int i=0; i<2*n+5; i++){
			for(auto u:vec[i]){
				if(u.f>mini){
					ans[u.s]=ind;
				}
			}
			for(auto u:vec[i]){
				if(u.f<mini){
					mini=u.f;
					ind=u.s;
				}
			}
		}
		for(int i=0; i<n; i++){
			cout<<ans[i]+1<<" ";
		}
		cout<<endl;
		
	}
	return 0;
}