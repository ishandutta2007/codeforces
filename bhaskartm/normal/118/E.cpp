#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
vector<vector<int>>graph;
vector<vector<pair<int, int>>>ad;
int U[300005];
int V[300005];
bool isbridge[300005];
int T;
int visited[100005];
int arr[100005];
bool edge[300005];
vector<pair<int, int>>ans;

void dfs(int v){
	visited[v]=true;
	for(auto u:ad[v]){
		if(visited[u.f] && edge[u.s]==false){
			ans.pb({v, u.f});
			edge[u.s]=true;
		}
		if(visited[u.f]==false){
			edge[u.s]=true;
			ans.pb({v, u.f});
			dfs(u.f);
		}
	}
}

int adj(int u,int e){
	return U[e]==u?V[e]:U[e];
}
 
int dfs0(int u,int edge){
	visited[u]=1;
	arr[u]=T++;
	int dbe=arr[u];
	for(auto e:graph[u]){
		int w=adj(u,e);
		if(!visited[w])
			dbe=min(dbe,dfs0(w,e));
		else if(e!=edge)
			dbe=min(dbe,arr[w]);
	}
	if(dbe==arr[u]&&edge!=-1)
		isbridge[edge]=true;
	return dbe;
}

int main() {
	int n, m;
	cin>>n>>m;
	graph.resize(n+1);
	ad.resize(n+1);
	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		graph[u].pb(i);
		graph[v].pb(i);
		U[i]=u;
		V[i]=v;
		ad[u].pb({v, i});
		ad[v].pb({u, i});
	}
	dfs0(1, -1);
	
	for(int i=0; i<m; i++){
		if(isbridge[i]){
			cout<<0;
			return 0;
		}
	}
	
	for(int i=1; i<=n; i++){
		visited[i]=false;
	}
	dfs(1);
	
	for(auto u:ans){
		cout<<u.f<<" "<<u.s<<endl;
	}
	return 0;
}