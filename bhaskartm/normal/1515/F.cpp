#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'


int parent[500005];
int size[500005];
int val[500005];
set<pair<int, int>>se;
int n, m, x;
vector<set<pair<int, int>>>adj;

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
        se.erase({val[a], a});
        se.erase({val[b], b});
        val[a]+=val[b];
        val[a]-=x;
        se.insert({val[a], a});
        for(auto u:adj[b]){
        	adj[a].insert(u);
        }
    }
}


 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m>>x;
	for(int i=1; i<=n; i++){
		make_set(i);
	}
	
	adj.resize(n+1);
	
	for(int i=1; i<=n; i++){
		cin>>val[i];
		se.insert({val[i], i});
	}
	
	for(int i=1; i<=m; i++){
		int u, v;
		cin>>u>>v;
		adj[u].insert({v, i});
		adj[v].insert({u, i});
	}
	
	vector<int>ans;
	for(int i=0; i<n-1; i++){
		auto it=se.end();
		it--;
		int node=(*it).s;
		int node1=find_set(node);

		vector<pair<int, int>>rem;
		for(auto u:adj[node1]){
			int node2=u.f;
			int node3=find_set(node2);
			if(node3==node1){
				rem.pb(u);
				continue;
			}
			int tot=val[node1]+val[node3];
			if(tot<x){
				cout<<"NO";
				return 0;
			}
			union_sets(node1, node3);
			ans.pb(u.s);
			break;
		}
		for(auto u:rem){
			adj[node1].erase(u);
		}
	}
	cout<<"YES"<<endl;
	for(auto u:ans){
		cout<<u<<endl;
	}
	
	
	return 0;
}