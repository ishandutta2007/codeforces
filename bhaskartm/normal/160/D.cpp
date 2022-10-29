#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define int long long int
vector<vector<pair<int, pair<int, int>>>>edge;
vector<vector<int>>graph;
int U[100005];
int V[100005];
bool isbridge[100005];
int T;
int visited[100005];
int arr[100005];
int size[100005];
int parent[100005];
int value[100005];
 
void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}
 
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
 
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
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
 
 main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		make_set(i);
	}
	
	edge.resize(1000005);
	for(int i=0; i<m; i++){
		int u, v, w;
		cin>>u>>v>>w;
		edge[w].pb({i, {u, v}});
	}
	
	for(int i=1; i<=1000000; i++){
		
		if(edge[i].size()==0){
			continue;
		}
		
		set<int>cg;
		set<int>ce;
		for(auto u:edge[i]){
			if(find_set(u.s.f)==find_set(u.s.s)){
				value[u.f]=2;
			}
			if(value[u.f]!=2){
				ce.insert(u.f);
				cg.insert(find_set(u.s.s));
				cg.insert(find_set(u.s.f));
			}
		}
		if(cg.size()==0){
			continue;
		}
		graph.resize(cg.size());
		map<int, int>mg;
		vector<int>vg;
		map<int, int>me;
		vector<int>ve;
		vg.resize(cg.size());
		ve.resize(ce.size());
		int cnt=0;
		for(auto it=cg.begin(); it!=cg.end(); it++){
			mg[(*it)]=cnt;
			vg[cnt]=(*it);
			cnt++;
		}
		
		cnt=0;
		for(auto it=ce.begin(); it!=ce.end(); it++){
			me[(*it)]=cnt;
			ve[cnt]=(*it);
			cnt++;
		}
		
		for(auto u:edge[i]){
			if(value[u.f]==2){
				continue;
			}
			graph[mg[parent[u.s.f]]].pb(me[u.f]);
			graph[mg[parent[u.s.s]]].pb(me[u.f]);
			U[me[u.f]]=mg[parent[u.s.f]];
			V[me[u.f]]=mg[parent[u.s.s]];
		}
		
		for(int i=0; i<cg.size(); i++){
			if(!visited[i]){
				dfs0(i, -1);
			}
		}
		
		for(int k=0; k<ce.size(); k++){
			if(isbridge[k]==1){
				
				value[ve[k]]=0;
			}
			else{
				value[ve[k]]=1;
			}
		}
		T=0;
		for(int k=0; k<cg.size(); k++){
			visited[k]=0;
			arr[k]=0;
		}
		graph.clear();
		for(int k=0; k<ce.size(); k++){
			isbridge[k]=0;
			U[k]=0;
			V[k]=0;
		}
		for(auto u:edge[i]){
			union_sets(u.s.f, u.s.s);
		}
		
	}
	for(int i=0; i<m; i++){
		if(value[i]==2){
			cout<<"none"<<endl;
		}
		if(value[i]==0){
			cout<<"any"<<endl;
		}
		if(value[i]==1){
			cout<<"at least one"<<endl;
		}
	}
	
	return 0;
}