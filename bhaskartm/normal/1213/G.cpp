#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>>adj;
int parent[200005];
long long int size[200005];
long long int ans;
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
        ans=ans-((size[a])*(size[a]-1))/2;
        ans=ans-((size[b])*(size[b]-1))/2;
        ans=ans+((size[a]+size[b])*(size[a]+size[b]-1))/2;
        parent[b] = a;
        size[a] += size[b];
    }
}
 
int main() {
	int n, q;
	cin>>n>>q;
	adj.resize(n+1);
	vector<pair<int, pair<int, int>>>edge;
	for(int i=0; i<n-1; i++){
		int u, v, w;
		cin>>u>>v>>w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
		edge.push_back({w, {u, v}});
	}
	sort(edge.begin(), edge.end());
	vector<pair<int, int>>qu;
	for(int i=0; i<q; i++){
		int x;
		cin>>x;
		qu.push_back({x, i});
	}
	if(n==1){
		for(int i=0; i<q; i++){
			cout<<0<<" ";
		}
		return 0;
	}
	for(int i=1; i<=n; i++){
		make_set(i);
	}
	sort(qu.begin(), qu.end());
	long long int answ[q];
	int index=0;
	for(int i=0; i<q; i++){
		int val=qu[i].first;
		
		while(index<edge.size() && edge[index].first<=val){
			int u=edge[index].second.first;
			int v=edge[index].second.second;
			index++;
			
			union_sets(u, v);
			
		}
		answ[qu[i].second]=ans;
	}
	for(int i=0; i<q; i++){
		cout<<answ[i]<<" ";
	}
	return 0;
}