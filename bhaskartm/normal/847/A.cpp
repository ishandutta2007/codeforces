#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
int in[1005];
int l[1005];
int r[1005];
vector<vector<int>>adj;
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	
	
	adj.resize(n+1);
	int cnt=0;
	for(int i=1; i<=n; i++){
		cin>>l[i]>>r[i];
		if(l[i]!=0){
			adj[l[i]].pb(i);
			in[i]++;
		}
		if(r[i]!=0){
			adj[i].pb(r[i]);
		}
	}
	
	vector<pair<int, int>>v;
	for(int i=1; i<=n; i++){
		if(in[i]!=0){
			continue;
		}
		int node=i;
		while(1){
			if(adj[node].size()==0){
				break;
			}
			node=adj[node][0];
		}
		v.pb({node, i});
	}
	
	for(int i=0; i<v.size()-1; i++){
		r[v[i].f]=v[i+1].s;
		l[v[i+1].s]=v[i].f;
	}
	for(int i=1; i<=n; i++){
		cout<<l[i]<<" "<<r[i]<<endl;
	}
	
	
	
	return 0;
}