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
		int n, l, r;
		cin>>n>>l>>r;
		multiset<int>le;
		multiset<int>ri;
		for(int i=0; i<l; i++){
			int x;
			cin>>x;
			le.insert(x);
		}
		for(int i=0; i<r; i++){
			int x;
			cin>>x;
			if(le.find(x)!=le.end()){
				le.erase(le.find(x));
			}
			else{
				ri.insert(x);
			}
		}
		vector<int>v1;
		vector<int>v2;
		for(auto u:le){
			v1.pb(u);
		}
		for(auto u:ri){
			v2.pb(u);
		}
	
		int cn1=0;
		int cn2=0;
		int sz1=v1.size();
		int sz2=v2.size();
		vector<pair<int, int>>c1;
		vector<pair<int, int>>c2;
		for(int i=0; i<sz1; i++){
			if(i==0 || c1.back().f!=v1[i]){
				c1.pb({v1[i], 1});
			}
			else{
				auto u=c1.back();
				c1.pop_back();
				c1.pb({u.f, u.s+1});
			}
		}
		for(auto u:c1){
			cn1+=((u.s/2));
		}
		for(int i=0; i<sz2; i++){
			if(i==0 || c2.back().f!=v2[i]){
				c2.pb({v2[i], 1});
			}
			else{
				auto u=c2.back();
				c2.pop_back();
				c2.pb({u.f, u.s+1});
			}
		}
		for(auto u:c2){
			cn2+=((u.s/2));
		}
		int ans=0;
		if(sz1>sz2){
			int diff=((sz1-sz2)/2);
			ans+=(min(diff, cn1));
			sz1-=(2*(min(diff, cn1)));
		}
		else if(sz2>sz1){
			int diff=((sz2-sz1))/2;
			ans+=min(diff, cn2);
			sz2-=(2*(min(diff, cn2)));
		}
		int diff=abs(sz1-sz2);
		ans+=(diff/2);
		ans+=((sz1+sz2)/2);
		cout<<ans<<endl;
	}
	return 0;
}