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

main() {
	int x, m;
	cin>>x>>m;
	n=2*x;
	src=0;
	dest=2*x+1;
	v.resize(2*x+2);
	int arr1[x+1];
	int arr2[x+1];
	int val1=0;
	int val2=0;
	for(int i=1; i<=x; i++){
		cin>>arr1[i];
		val1+=arr1[i];
	}
	for(int i=1; i<=x; i++){
		cin>>arr2[i];
		val2+=arr2[i];
	}
	
	for(int i=1; i<=x; i++){
		addedge(i, x+i, inf);
	}
	
	for(int i=1; i<=x; i++){
		addedge(0, i, arr1[i]);
	}
	for(int i=1; i<=x; i++){
		addedge(x+i, 2*x+1, arr2[i]);
	}
	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		addedge(u, v+x, inf);
		addedge(v, u+x, inf);
	}
	
	int ans=dinic();
	if(val1!=val2 || ans!=val1){
		cout<<"NO";
		return 0;
	}
	cout<<"YES"<<endl;
	int fin[x+1][x+1];
	for(int i=0; i<=x; i++){
		for(int j=0; j<=x; j++){
			fin[i][j]=0;
		}
	}
	for(int i=1; i<=x; i++){
		fin[i][i]=e[2*(i-1)].flow;
	}
	for(int i=6*x; i<6*x+4*m; i=i+2){
		fin[e[i].a][e[i].b-x]=e[i].flow;
	}
	for(int i=1; i<=x; i++){
		for(int j=1; j<=x; j++){
			cout<<fin[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}