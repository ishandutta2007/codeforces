#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define f first
#define s second
#define double long double

#define inf 1000000000000000000
struct edge{
	int a, b;
	int cap, flow;
};
int n, src, dest, d[55], ptr[55];
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


main() {
	int N, m, x;
	cin>>N>>m>>x;
	vector<pair<pair<int, int>, int>>ed;
	for(int i=0; i<m; i++){
		int u, v, w;
		cin>>u>>v>>w;
		ed.pb({{u, v}, w});
	}
	double lo=1e-6;
	double hi=1000000;
	src=1;
	dest=N;
	n=N;
	double ans=-1;
	v.resize(n+1);
	
	while(hi-lo>=1e-12){
		double mid=(lo+hi)/2;
		for(auto u:ed){
			addedge(u.f.f, u.f.s, floor(u.s/mid));
		}
		int val=dinic();
		
		e.clear();
		v.clear();
		v.resize(n+1);
		for(int i=0; i<55; i++){
			d[i]=0;
			ptr[i]=0;
		}
		if(val>=x){
			ans=mid;
			lo=mid;
		}
		else{
			hi=mid;
		}
	}
	cout<<setprecision(20)<<(x*ans);
	return 0;
}