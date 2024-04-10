#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int

#define pb push_back
#define endl '\n'

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		string s;
		cin>>s;
		int l=0;
		int w=0;
		for(auto u:s){
			if(u=='W'){
				w++;
			}
			else{
				l++;
			}
		}
		if(k>=l){
			cout<<1+2*(n-1)<<endl;
			continue;
		}
		if(w==0){
			cout<<max(1+2*(k-1), 0LL)<<endl;
			continue;
		}
		vector<pair<int, int>>v;
		for(auto u:s){
			if(v.empty()){
				if(u=='W'){
					v.pb({1, 1});
				}
				else{
					v.pb({1, 0});
				}
				continue;
			}
			if((u=='W' && v.back().second==1) || (u=='L' && v.back().second==0)){
				auto uu=v.back();
				v.pop_back();
				int val1=uu.first;
				int val2=uu.second;
				v.pb({val1+1, val2});
			}
			else{
				if(u=='W'){
					v.pb({1, 1});
				}
				else{
					v.pb({1, 0});
				}
			}
		}
		
		vector<int>val1;
		vector<int>val2;
		int ans=0;
		
		for(int i=0; i<v.size(); i++){
			
			if(v[i].second==1){
				ans+=(1+((v[i].first-1)*2));
				continue;
			}
			
			if(i==0 || i==(v.size()-1)){
				val1.pb(v[i].first);
			}
			else{
				val2.pb(v[i].first);
			}
		}
		
		sort(val2.begin(), val2.end());
		
		for(int i=0; i<val2.size(); i++){
			if(k>=val2[i]){
				k-=val2[i];
				ans+=3;
				ans+=(2*(val2[i]-1));
			}
			else{
				ans+=(2*k);
				k=0;
			}
		}
		for(auto u:val1){
			if(k>u){
				k-=u;
				ans+=2*u;
			}
			else{
				ans+=2*k;
				k=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}