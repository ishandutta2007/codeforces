#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define f first
#define s second
#define pb push_back
const int N=10000000000;
main() {
	int t;
	cin>>t;
	
	while(t--){
		int n, m;
		cin>>n>>m;
		vector<pair<int, int>>v;
		for(int i=0; i<m; i++){
			int a, b;
			cin>>a>>b;
			v.pb({a, b});
		}
		sort(v.begin(), v.end());
		vector<int>vc;
		for(auto u:v){
			vc.pb(u.f);
		}
		int suf[m];
		suf[m-1]=v[m-1].f;
		for(int i=m-2; i>=0; i--){
			suf[i]=suf[i+1]+v[i].f;
		}
		int maxi=0;
		if(n==1){
			for(int i=0; i<m; i++){
				maxi=max(maxi, v[i].f);
			}
			cout<<maxi<<endl;
			continue;
		}
		if(n<=m){
			maxi=max(maxi, suf[m-n]);
		}
		
		for(int i=0; i<m; i++){
			int id=upper_bound(vc.begin(), vc.end(),v[i].s)-vc.begin();
			
			if(id==m){
				maxi=max(maxi, v[i].f+v[i].s*(n-1));
				continue;
			}
			
			if(id>i){
				if(m-id>=n){
					maxi=max(maxi, suf[m-n]);
					continue;
				}
				maxi=max(maxi, suf[id]+v[i].f+(n-(m-id+1))*v[i].s);
				continue;
			}
			if(id<=i){
				if(m-id>=n){
					maxi=max(maxi, suf[m-n]);
					continue;
				}
				maxi=max(maxi, suf[id]+(n-(m-id))*v[i].s);
			}
			
		}
		cout<<maxi<<endl;
	}
	return 0;
}