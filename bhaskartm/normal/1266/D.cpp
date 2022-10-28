#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define int long long int 
main() {
	int n, m;
	cin>>n>>m;
	int val[n+1];
	for(int i=0; i<=n; i++){
		val[i]=0;
	}
	for(int i=0; i<m; i++){
		int u, v, w;
		cin>>u>>v>>w;
		val[u]+=w;
		val[v]-=w;
	}
	vector<pair<int, int>>po;
	vector<pair<int, int>>ne;
	for(int i=1; i<=n; i++){
		if(val[i]>0){
			po.pb({val[i], i});
		}
		if(val[i]<0){
			ne.pb({-val[i], i});
		}
	}
	int i=0;
	int j=0;
	vector<pair<pair<int, int>, int>>ans;
	while(i<po.size() && j<ne.size()){
		if(po[i].f>ne[j].f){
			ans.pb({{po[i].s, ne[j].s}, ne[j].f});
			po[i].f-=ne[j].f;
			ne[j].f=0;
			
			j++;
			continue;
		}
		if(po[i].f==ne[j].f){
			ans.pb({{po[i].s, ne[j].s}, ne[j].f});
			ne[j].f=0;
			po[i].f=0;
			i++;
			j++;
			continue;
		}
		if(po[i].f<ne[j].f){
			ans.pb({{po[i].s, ne[j].s}, po[i].f});
			ne[j].f-=po[i].f;
			po[i].f=0;
			
			i++;
			continue;
		}
	}
	cout<<ans.size()<<endl;
	for(auto u:ans){
		cout<<u.f.f<<" "<<u.f.s<<" "<<u.s<<endl;
	}
	
	return 0;
}