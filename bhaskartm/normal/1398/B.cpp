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
		string s;
		cin>>s;
		vector<pair<int, int>>v;
		if(s[0]=='0'){
			v.pb({1, 0});
		}
		else{
			v.pb({1, 1});
		}
		for(int i=1; i<s.size(); i++){
			if((s[i]-'0')==v.back().s){
				auto node=v.back();
				v.pop_back();
				v.pb({node.f+1, node.s});
				continue;
			}
			v.pb({1, (s[i]-'0')});
		}
		vector<int>vec;
		for(auto u:v){
			if(u.s==1){
				vec.pb(u.f);
			}
		}
		sort(vec.begin(), vec.end());
		reverse(vec.begin(), vec.end());
		int ans=0;
		for(int i=0; i<vec.size(); i=i+2){
			ans+=vec[i];
		}
		cout<<ans<<endl;
	}
	
	return 0;
}