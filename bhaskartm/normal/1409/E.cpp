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
		int n, k;
		cin>>n>>k;
		map<int, int>m;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			m[x]++;
		}
		for(int i=0; i<n; i++){
			int y;
			cin>>y;
		}
		vector<pair<int, int>>v;
		vector<int>vc;
		v.pb({0, 0});
		vc.pb(0);
		for(auto it=m.begin(); it!=m.end(); it++){
			v.pb({(it->first), v.back().s+(it->second)});
			vc.pb(it->first);
		}
		int maxi=0;
		int tot=0;
		int sz=v.size();
		if(sz==1){
			cout<<n<<endl;
			continue;
		}
		
		for(int i=sz-2; i>=0; i--){
			int xc=v[i].f-k;
			
			auto it=lower_bound(vc.begin(), vc.end(), xc);
			int val1;
			int ind=it-vc.begin();
			if(it==vc.begin()){
				val1=v[i].s;
			}
			else{
				val1=v[i].s-(v[ind-1].s);
			}
			
			int node=i+1;
			it=upper_bound(vc.begin(), vc.end(), v[node].f+k);
			it--;
			ind=(it-vc.begin());
			
			int val2=v[ind].s-v[i].s;
			
			
			if(val2>maxi){
				maxi=val2;
			}
			tot=max(tot, maxi+val1);
		}
		cout<<tot<<endl;
	}
	return 0;
}