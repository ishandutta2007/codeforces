#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'


const int inf=2e9;
struct edge{
	int a, b;
	int cap, flow;
};
 
int n,src,dest,d[100005],ptr[100005]; 
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
	vector<pair<int, int>>ed;
	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		ed.pb({u, v});
	}
	int lo=0;
	int hi=5000;
	int ans=hi;
	
	while(lo<=hi){
		int mid=(lo+hi)/2;
		n=2+N+m;
		
		src=0;
		dest=N+m+1;
		v.clear();
		v.resize(1e5+5);
		for(int i=0; i<m; i++){
			
			addedge(0, i+1, 1);
		}
		
		for(int i=0; i<m; i++){
			addedge(i+1, m+ed[i].f, 1);
			addedge(i+1, m+ed[i].s, 1);
		}
		
		for(int i=1; i<=n; i++){
			addedge(m+i, dest, mid);
		}
		
		int x=dinic();
		if(x==m){
			ans=mid;
			hi=mid-1;
		}
		else{
			lo=mid+1;
		}
		for(int i=0; i<100005; i++){
			ptr[i]=0;
			d[i]=0;
		}
		v.clear();
		e.clear();
	}
	cout<<ans<<endl;
	n=2+N+m;
	v.clear();

	v.resize(1e5+5);
	
		src=0;
		dest=N+m+1;
		v.clear();
		v.resize(1e5+5);
		for(int i=0; i<m; i++){
			
			addedge(0, i+1, 1);
		}
		
		for(int i=0; i<m; i++){
			addedge(i+1, m+ed[i].f, 1);
			addedge(i+1, m+ed[i].s, 1);
		}
		
		for(int i=1; i<=n; i++){
			addedge(m+i, dest, ans);
		}
		
		int x=dinic();
		int pt=0;
	for(int i=2*m; i<6*m; i=i+4){
		if(e[i].flow==1){
			cout<<ed[pt].f<<" "<<ed[pt].s<<endl;
		}
		else{
			cout<<ed[pt].s<<" "<<ed[pt].f<<endl;
		}
	
		pt++;
	}
	return 0;
}