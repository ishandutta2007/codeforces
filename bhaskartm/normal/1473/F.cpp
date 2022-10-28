#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")

#define f first
#define s second
#define pb push_back
#define endl '\n'




const int inf=2e9;

struct edge{
	int a, b;
	int cap, flow;
};
 
int n,src,dest,d[3005],ptr[3005]; 
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



int las[105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin>>N;
	int a[N];
	for(int i=0; i<N; i++){
		cin>>a[i];
	}
	int b[N];
	for(int i=0; i<N; i++){
		cin>>b[i];
	}
	n=N+2;
	src=0;
	dest=N+1;
	
	for(int i=0; i<105; i++){
		las[i]=-1;
	}
	v.resize(N+5);
	for(int i=0; i<N; i++){
		int val=a[i];
		for(int x=1; x<=val; x++){
			if(las[x]!=-1 && val%x==0){
				addedge(i+1, las[x]+1, 1e9);
			}
		}
		las[a[i]]=i;
	}
	
	int ans=0;
	for(int i=0; i<N; i++){
		if(b[i]>0){
			ans+=b[i];
		}
		if(b[i]>0){
			addedge(0, i+1, b[i]);
		}
		else{
			addedge(i+1, N+1, -b[i]);
		}
	}
	
	int val=dinic();
	
	cout<<ans-val;
	
	return 0;
}