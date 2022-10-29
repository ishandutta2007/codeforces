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
		string st;
		cin>>st;
		vector<pair<int, int>>v;
		for(int i=0; i<st.size(); i++){
			if(v.empty()){
				if(st[i]=='0'){
					v.pb({1, 0});
				}
				else{
					v.pb({1, 1});
				}
				continue;
			}
			if((st[i]-'0')==v.back().s){
				int val=v.back().f;
				v.pop_back();
				v.pb({val+1, st[i]-'0'});
			}
			else{
				v.pb({1, st[i]-'0'});
			}
		}
		multiset<pair<int, int>>se;
		multiset<pair<int, int>>se2;
		int pt=0;
		for(auto u:v){
			se.insert({u.f, pt});
			if(u.f>1){
				se2.insert({pt, u.f});
			}
			pt++;
		}
		int ans=0;
		int curr=0;
		int ptt=0;
		
		while(1){
			
			if(se.empty()){
				break;
			}
			
			if(se2.empty()){
				ans+=(((se.size()+1))/2);
				
				break;
			}
			if(v[curr].f>1){
				ans++;
				se.erase({v[curr].f, curr});
				se2.erase({curr, v[curr].f});
				curr++;
				continue;
			}
			else{
				
				auto it=se2.begin();
				int pos=(*it).f;
				int val=(*it).s;
			
				se2.erase(it);
				se.erase({val, pos});
				
				if(val-1>1){
					se2.insert({pos, val-1});
				}
				
				se.insert({val-1, pos});
				se.erase({1, curr});
				curr++;
				v[pos].f=v[pos].f-1;
				ans++;
				continue;
				
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}