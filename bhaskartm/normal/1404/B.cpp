#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define T long double

vector<vector<int>>adj;
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	int it=0;
	while(t--){
		it++;
		int n, a, b, d1, d2;
		cin>>n>>a>>b>>d1>>d2;
		adj.clear();
		adj.resize(n+1);
		for(int i=0; i<n-1; i++){
			int u , v;
			cin>>u>>v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		if(2*d1>=d2){
			cout<<"Alice"<<endl;
			continue;
		}
		queue<int>q;
		int d[n+1];
		for(int i=0; i<=n; i++){
			d[i]=1e9;
		}
		d[a]=0;
		q.push(a);
		while(!q.empty()){
			int v=q.front();
			q.pop();
			for(auto u:adj[v]){
				if(d[v]+1<d[u]){
					d[u]=1+d[v];
					q.push(u);
					continue;
				}
			}
		}
		
		if(d[b]<=d1){
			cout<<"Alice"<<endl;
			continue;
		}
		int maxi=0;
		int ind=-1;
		for(int i=1; i<=n; i++){
			if(d[i]>maxi){
				ind=i;
				maxi=d[i];
			}
		}
		for(int i=1; i<=n; i++){
			d[i]=1e9;
		}
		while(!q.empty()){
			q.pop();
		}
		d[ind]=0;
		q.push(ind);
		while(!q.empty()){
			int v=q.front();
			q.pop();
			for(auto u:adj[v]){
				if(d[v]+1<d[u]){
					d[u]=1+d[v];
					q.push(u);
					continue;
				}
			}
		}
		maxi=0;
		for(int i=1; i<=n; i++){
			maxi=max(maxi, d[i]);
		}
		
		if(maxi<=2*d1){
			cout<<"Alice"<<endl;
			continue;
		}
		else{
			cout<<"Bob"<<endl;
		}
	}
	return 0;
}