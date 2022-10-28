#include <bits/stdc++.h>
using namespace std;
#define pb push_back
vector<bool>vis;
vector<int>man;
vector<vector<int>>G;
int dis[605][605];
int N, M;
int v, e, n, k;
int arr[205];
int canMarry(int u){
	for(auto v:G[u]){
		if(vis[v]){
			continue;
		}
		vis[v]=true;
		if(man[v]==-1 || canMarry(man[v])){
			man[v]=u;
			return 1;
		}
	}
	return 0;
}

int maxMatching(){
	int ans=0;
	for(int i=0; i<N; i++){
		vis.assign(M, false);
		ans+=canMarry(i);
	}
	return ans;
}
vector<vector<pair<int, int>>>adj;

bool f(int t){
	
	bool isp[v][v];
	for(int i=0; i<v; i++){
		for(int j=0; j<v; j++){
			isp[i][j]=false;
			if(dis[i][j]<=t){
				isp[i][j]=true;
			}
		}
	}
	N=n;
	M=v;
	G.clear();
	G.resize(n);
	vis.assign(M, false);
	man.assign(M, -1);
	for(int i=0; i<n; i++){
		int node=arr[i];
		for(int j=0; j<v; j++){
			if(isp[node][j]){
				G[i].push_back(j);
			}
		}
	}
	return (maxMatching()>=k);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	
	
	
	
	cin>>v>>e>>n>>k;
	adj.resize(v);
	
	for(int i=0; i<n; i++){
		cin>>arr[i];
		arr[i]--;
	}
	
	for(int i=0; i<e; i++){
		int u, w, t;
		cin>>u>>w>>t;
		u--;
		w--;
		adj[u].pb({w, t});
		adj[w].pb({u, t});
	}
	
	int lo=0;
	int hi=1731311;
	int ans=-1;
	
	
	
	for(int i=0; i<v; i++){
		for(int j=0; j<v; j++){
			dis[i][j]=1000000000;
		}
		dis[i][i]=0;
		set<pair<int, int>>s;
		bool pro[v];
		for(int j=0; j<v; j++){
			pro[j]=false;
		}
		s.insert({dis[i][i], i});
		while(!s.empty()){
			auto it=s.begin();
			int node=(*it).second;
			if(pro[node]){
				s.erase((*it));
				continue;
			}
			pro[node]=true;
			s.erase((*it));
			for(auto u:adj[node]){
				if(dis[i][node]+u.second<dis[i][u.first]){
					dis[i][u.first]=dis[i][node]+u.second;
					s.insert({dis[i][u.first], u.first});
				}
			}
		}
	}
	
	
	
	while(lo<=hi){
		int mid=(lo+hi)/2;
		if(f(mid)){
			ans=mid;
			hi=mid-1;
		}
		else{
			lo=mid+1;
		}
	}
	cout<<ans;
	return 0;
}