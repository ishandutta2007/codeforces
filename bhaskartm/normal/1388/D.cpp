#include <bits/stdc++.h>
using namespace std;
 
#pragma optimize("-O3")
#define int long long int

#define pb push_back
#define f first
#define s second
#define endl '\n'
vector<vector<int>>adj;
main() {
	int n;
	cin>>n;
	adj.resize(n+1);
	int a[n+1];
	int b[n+1];
	int ind[n+1];
	for(int i=1; i<=n; i++){
		cin>>a[i];
		ind[i]=0;
	}
	for(int i=1; i<=n; i++){
		cin>>b[i];
	}
	for(int i=1; i<=n; i++){
		if(b[i]==-1){
			continue;
		}
		adj[i].pb(b[i]);
		ind[b[i]]++;
	}
	set<pair<int, int>>se;
	for(int i=1; i<=n; i++){
		se.insert({ind[i], i});
	}
	int ans=0;
	int pos[n];
	int fir=0;
	int las=n-1;
	while(!se.empty()){
		auto it=se.begin();
		int node=(*it).s;
		if(a[node]<=0){
			ans+=a[node];
			pos[las]=node;
			las--;
			se.erase({ind[node], node});
			if(adj[node].size()==0){
				continue;
			}
			int u=adj[node][0];
			ind[u]--;
			se.insert({ind[u], u});
			se.erase({ind[u]+1, u});
		}
		else{
			ans+=a[node];
			pos[fir]=node;
			fir++;
			se.erase({ind[node], node});
			if(adj[node].size()==0){
				continue;
			}
			int u=adj[node][0];
			ind[u]--;
			se.insert({ind[u], u});
			se.erase({ind[u]+1, u});
			a[u]+=a[node];
		}
	}
	cout<<ans<<endl;
	for(int i=0; i<n; i++){
		cout<<pos[i]<<" ";
	}
	return 0;
}