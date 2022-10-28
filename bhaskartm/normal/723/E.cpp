#include <bits/stdc++.h>
using namespace std;
int deg[250];
int vis[250];
struct Edge;
typedef list<Edge>::iterator iter;

struct Edge
{
	int next_vertex;
	iter reverse_edge;
	
	Edge(int next_vertex)
		:next_vertex(next_vertex)
		{}
};

const int max_vertices=250;
int num_vertices;
list<Edge> adj[max_vertices];

vector<int>path;

void find_path(int v){
	vis[v]=1;
	while(adj[v].size()>0){
		int vn=adj[v].front().next_vertex;
		adj[vn].erase(adj[v].front().reverse_edge);
		adj[v].pop_front();
		find_path(vn);
	}
	path.push_back(v);
}

void add_edge(int a, int b){
	adj[a].push_front(Edge(b));
	iter ita=adj[a].begin();
	adj[b].push_front(Edge(a));
	iter itb=adj[b].begin();
	ita->reverse_edge=itb;
	itb->reverse_edge=ita;
}

int main() {
	int t;
	cin>>t;
	while(t--){
		map<pair<int, int>, int>ma;
		int n, m;
		cin>>n>>m;
		for(int i=0; i<m; i++){
			int u, v;
			cin>>u>>v;
			
			deg[u]++;
			deg[v]++;
			add_edge(u, v);
			ma[{u, v}]=1;
			ma[{v, u}]=1;
		}
		int cnt=0;
		for(int i=1; i<=n; i++){
			if(deg[i]%2==0){
				
				cnt++;
			}
		}
		
		cout<<cnt<<endl;
		set<int>s;
		vector<int>left;
		for(int i=1; i<=n; i++){
			if(deg[i]%2==1){
				s.insert(i);
			}
		}
		while(!s.empty()){
			auto it=s.begin();
			int node=(*it);
			s.erase(node);
			int node2=0;
			for(auto it=s.begin(); it!=s.end(); it++){
				node2=(*it);
				if(ma[{node, node2}]==0){
					break;
				}
			}
			add_edge(node, node2);
			
			s.erase(node2);
		}
		
		for(int i=1; i<=n; i++){
			if(!vis[i]){
				find_path(i);
			}
		}
		
		vector<pair<int, int>>ans;
		set<pair<int, int>>s2;
		for(int i=0; i<path.size()-1; i++){
			int u=path[i];
			int v=path[i+1];
			if(ma[{u, v}]==1){
				s2.insert({u, v});
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				if(s2.find({i, j})!=s2.end() && s2.find({j, i})!=s2.end()){
					s2.erase({i ,j});
				}
			}
		}
		for(auto u:s2){
			cout<<u.first<<" "<<u.second<<endl;
		}
		path.clear();
		for(int i=0; i<250; i++){
			deg[i]=0;
			vis[i]=0;
		}
		for(int i=1; i<=n; i++){
			while(!adj[i].empty()){
				adj[i].pop_front();
			}
		}
	}
	return 0;
}