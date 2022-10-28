#include <bits/stdc++.h>
using namespace std;
map<int, vector<pair<int, int>>>ma;

int size[200005];
int parent[200005];
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

int main() {
	int n, m;
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int u, v, w;
		cin>>u>>v>>w;
		ma[w].push_back({u, v});
		
	}
	for(int i=1; i<=n; i++){
		make_set(i);
	}
	int ans=0;
	for(auto it=ma.begin(); it!=ma.end(); it++){
		int w=(it->first);
		auto vec=(it->second);
		int coun=0;
		for(int i=0; i<vec.size(); i++){
			int u=vec[i].first;
			int v=vec[i].second;
			if(find_set(u)!=find_set(v)){
				coun++;
			}
		}
		int coun2=0;
		for(int i=0; i<vec.size(); i++){
			int u=vec[i].first;
			int v=vec[i].second;
			if(find_set(u)!=find_set(v)){
				coun2++;
				union_sets(u, v);
			}
		}
		ans=ans+(coun-coun2);
	}
	cout<<ans;
	return 0;
}