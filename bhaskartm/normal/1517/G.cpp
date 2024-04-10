#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'



const int inf=2e18;
 
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

const int M=1005;
int x[M];
int y[M];
int w[M];
int pt=1;
map<pair<int, int>, int>ma;
int sum=0;
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin>>N;
	n=2*N+2;
	src=0;
	dest=2*N+1;
	
	v.resize(n+5);
	vector<int>v0;
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	for(int i=0; i<N; i++){
		cin>>x[i]>>y[i]>>w[i];
		x[i]+=1e9;
		y[i]+=1e9;
		
		sum+=w[i];
		ma[{x[i], y[i]}]=pt;
		pt++;
		if(x[i]%2==0 && y[i]%2==0){
			v1.pb(i);
		}
		if(x[i]%2==1 && y[i]%2==0){
			v0.pb(i);
		}
		if(y[i]%2==1 && x[i]%2==0){
			v2.pb(i);
		}
		if(y[i]%2==1 && x[i]%2==1){
			v3.pb(i);
		}
	}
	
	
	for(auto u:v0){
		addedge(0, 2*u+1, 1e13);
		//cout<<0<<" "<<2*u+1<<endl;
	}
	
	for(auto u:v3){
		addedge(2*u+2, 2*N+1, 1e13);
		//cout<<2*u+2<<" "<<2*N+1<<endl;
	}
	
	for(int i=0; i<N; i++){
		addedge(2*i+1, 2*i+2, w[i]);
		//cout<<2*i+1<<" "<<2*i+2<<" "<<w[i]<<endl;
	}
	
	
	for(auto u:v0){
		int v11=ma[{x[u]-1, y[u]}];
		int v22=ma[{x[u]+1, y[u]}];
		if(v11!=0){
			addedge(2*u+2, 2*(v11-1)+1, 1e13);
			//cout<<2*u+2<<" "<<2*(v11-1)+1<<endl;
		}
		if(v22!=0){
			addedge(2*u+2, 2*(v22-1)+1, 1e13);
			
		}
	}
	
	for(auto u:v1){
		int v11=ma[{x[u], y[u]-1}];
		int v22=ma[{x[u], y[u]+1}];
		if(v11!=0){
			addedge(2*u+2, 2*(v11-1)+1, 1e13);
			//cout<<2*u+2<<" "<<2*(v11-1)+1<<endl;
		}
		if(v22!=0){
			addedge(2*u+2, 2*(v22-1)+1, 1e13);
			//cout<<2*u+2<<" "<<2*(v22-1)+1<<endl;
		}
	}
	for(auto u:v2){
		int v11=ma[{x[u]-1, y[u]}];
		int v22=ma[{x[u]+1, y[u]}];
		if(v11!=0){
			addedge(2*u+2, 2*(v11-1)+1, 1e13);
			//cout<<2*u+2<<" "<<2*(v11-1)<<endl;
		}
		if(v22!=0){
			addedge(2*u+2, 2*(v22-1)+1, 1e13);
			//cout<<2*u+2<<" "<<2*(v22-1)+1<<endl;
		}
	}
	int x=dinic();
	sum-=x;
	cout<<sum<<endl;
	
	
	return 0;
}