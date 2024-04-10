#include <bits/stdc++.h>
using namespace std;
#define inf 1000000000000000000
#define int long long int
struct edge{
	int a, b;
	int cap, flow;
};
int n, src, dest, d[205], ptr[205];
vector<vector<int>>v;
vector<edge>e;
 
bool bfs(){
	int i;
	queue<int>q;
	for(int i=0; i<n+2; i++){
		d[i]=-1;
	}
	q.push(src);
	d[src]=0;
	while(!q.empty() && d[dest]==-1){
		int u=q.front();
		q.pop();
		for(int i=0; i<v[u].size(); i++){
			int ind=v[u][i], v1=e[ind].b;
			int cap=e[ind].cap, fl=e[ind].flow;
			if(d[v1]==-1 && fl<cap){
				q.push(v1);
				d[v1]=d[u]+1;
			}
		}
	}
	return (d[dest]!=-1);
}
 
int dfs(int u, int curr){
	if(!curr) return 0;
	if(u==dest) return curr;
	for(;ptr[u]<v[u].size(); ++ptr[u]){
		int ind=v[u][ptr[u]], v1=e[ind].b;
		if(d[v1]==d[u]+1 && e[ind].flow<e[ind].cap){
			int pushed=dfs(v1, min(curr, e[ind].cap-e[ind].flow));
			if(pushed>0){
				e[ind].flow+=pushed;
				e[(ind^1)].flow-=pushed;
				return pushed;
			}
		}
	}
	return 0;
}
 
int dinic(){
	int flow=0, i;
	while(bfs()){
		for(int i=0; i<n+2; i++)ptr[i]=0;
		while(int curr=dfs(src, inf))
			flow+=curr;
	}
	return flow;
}
 
void addedge(int x, int y, int cap){
	
	edge e1={x, y, cap, 0};
	edge e2={y, x, 0, 0};
	v[x].push_back((int)e.size());
	
	e.push_back(e1);
	
	v[y].push_back((int)e.size());
	
	e.push_back(e2);
	
}
bool isprime(int x){
	for(int i=2; i*i<=x; i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
}

map<int, pair<int, int>>ma;
vector<vector<int>>adj;
vector<vector<int>>cycles;
vector<int>cycle;
bool vis[205];

void dfs2(int v){
	vis[v]=1;
	for(auto u:adj[v]){
		if(vis[u]==1){
			continue;
		}
		cycle.push_back(u);
		dfs2(u);
	}
}

 main() {
	int N;
	cin>>N;
	adj.resize(N+1);
	int arr[N];
	vector<pair<int, int>>odd;
	vector<pair<int, int>>even;
	
	for(int i=0; i<N; i++){
		cin>>arr[i];
		if(arr[i]%2==0){
			even.push_back({arr[i], i+1});
		}
		else{
			odd.push_back({arr[i], i+1});
		}
	}
	if(even.size()!=odd.size()){
		cout<<"Impossible";
		return 0;
	}
	
	n=N;
	src=0;
	dest=N+1;
	v.resize(N+2);
	for(int i=0; i<even.size(); i++){
		ma[i+1]=even[i];
	}
	
	for(int i=0; i<odd.size(); i++){
		ma[(N/2)+i+1]=odd[i];
	}
	for(int i=1; i<=(N/2); i++){
		
		addedge(0, i, 2);
	}
	for(int i=(N/2)+1; i<=N; i++){
		
		addedge(i, N+1, 2);
	}
	for(int i=1; i<=(N/2); i++){
		for(int j=(N/2)+1; j<=N; j++){
			
			if(isprime(ma[i].first+ma[j].first)){
				
				addedge(i, j, 1);
			}
		}
	}
	
	int val=dinic();
	if(val!=N){
		cout<<"Impossible";
		return 0;
	}
	for(auto u:e){
		if(u.cap==0 || u.a==0 || u.b==N+1 || u.flow==0){
			continue;
		}
		
		adj[ma[u.a].second].push_back(ma[u.b].second);
		adj[ma[u.b].second].push_back(ma[u.a].second);
	}
	for(int i=1; i<=N; i++){
		if(vis[i]==0){
			cycle.clear();
			cycle.push_back(i);
			dfs2(i);
			cycles.push_back(cycle);
		}
	}
	cout<<cycles.size()<<endl;
	for(auto u:cycles){
		cout<<u.size()<<" ";
		for(auto val:u){
			cout<<val<<" ";
		}
		cout<<endl;
	}
	return 0;
}