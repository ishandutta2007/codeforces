#include <bits/stdc++.h>
using namespace std;
#define inf 1000000000000000000
#define int long long int
struct edge{
	int a, b;
	int cap, flow;
};
int n, src, dest, d[105], ptr[105];
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
	vector<map<int, int>>ma;
	int m;
	cin>>n>>m;
	ma.resize(n+1);
	int arr[n+1];
	for(int i=1; i<=n; i++){
		cin>>arr[i];
	}
	set<int>s;
	for(int i=1; i<=n; i++){
		vector<int>f;
		int val=arr[i];
		for(int x=2; x*x<=val; x++){
			while(val%x==0){
				f.push_back(x);
				val=val/x;
			}
		}
		if(val>1){
			f.push_back(val);
		}
		for(auto u:f){
			ma[i][u]++;
			s.insert(u);
		}
	}
	vector<int>vec;
	for(auto it=s.begin(); it!=s.end(); it++){
		vec.push_back((*it));
	}
	vector<pair<int, int>>ed;
	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		if(v%2==0){
			int temp=v;
			v=u;
			u=temp;
		}
		ed.push_back({u, v});
	}
	src=0;
	dest=n+1;
	v.resize(n+2);
	int tab[n+1][vec.size()];
	for(int i=0; i<vec.size(); i++){
		for(int j=1; j<=n; j++){
			tab[j][i]=ma[j][vec[i]];
		}
	}
	int ans=0;
	for(int i=0; i<vec.size(); i++){
		for(int j=2; j<=n; j=j+2){
			addedge(0, j, tab[j][i]);
		}
		for(int j=1; j<=n; j=j+2){
			addedge(j, n+1, tab[j][i]);
		}
		for(auto u:ed){
			addedge(u.first, u.second, inf);
		}
		ans+=dinic();
		e.clear();
		v.clear();
		v.resize(n+2);
		for(int j=0; j<105; j++){
			d[j]=0;
			ptr[j]=0;
		}
	}
	cout<<ans;
	return 0;
}