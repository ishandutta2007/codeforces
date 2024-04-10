#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

const int N2=1e9;

const int inf=2e15;
struct edge{
	int a, b;
	int cap, flow;
};
 
int n,src,dest,d[13000],ptr[13000]; 
vector<vector<int> > v;
vector<edge> e;
 
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
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, m;
	cin>>N>>m;
	int a[N];
	int b[N];
	int c[N];
	for(int i=0; i<N; i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	
	int l[N];
	int r[N];
	n=2;
	for(int i=0; i<N; i++){
		cin>>l[i]>>r[i];
		n+=(r[i]-l[i]+2);
	}
	src=0;
	dest=n-1;
	int node=1;
	
	v.resize(n+5);
	for(int i=0; i<N; i++){
		addedge(0, node,1e15);
		node+=(r[i]-l[i]+2);
	}
	node=r[0]-l[0]+2;
	for(int i=0; i<N; i++){
		addedge(node, dest, 1e15);
		if(i!=(N-1)){
			node+=(r[i+1]-l[i+1]+2);
		}
	}
	node=1;
	for(int i=0; i<N; i++){
		for(int j=l[i]; j<=r[i]; j++){
			addedge(node, node+1, N2-(a[i]*j*j+b[i]*j+c[i]));
			node++;
		}
		node++;
	}
	
	int pre[N+1];
	pre[0]=0;
	for(int i=1; i<=N; i++){
		pre[i]=pre[i-1]+(r[i-1]-l[i-1]+2);
	}
	
	for(int i=0; i<m; i++){
		int u, v, d;
		cin>>u>>v>>d;
		u--;
		v--;
		for(int j=l[u]-1; j<=r[u]; j++){
			if(l[v]-1<=j-d && j-d<=r[v]){
				addedge(pre[u]+1+j-(l[u]-1), pre[v]+1+(j-d)-(l[v]-1), 1e15);
			}
		}
	}
	int x=dinic();
	
	cout<<N*N2-x;
	return 0;
}