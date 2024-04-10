#include<bits/stdc++.h>
using namespace std;
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
	long long int arr[n+1];
	arr[0]=0;
	long long int mini=pow(10, 13);
	int index=0;
	for(int i=1; i<=n; i++){
		cin>>arr[i];
		if(arr[i]<mini){
			index=i;
			mini=arr[i];
		}
	}
	vector<pair<long long int, pair<int, int>>>edge;
	for(int i=1; i<=n; i++){
		if(i==index){
			continue;
		}
		edge.push_back({arr[i]+arr[index],{index, i}});
	}
	for(int i=0; i<m; i++){
		int u, v;
		long long int w;
		cin>>u>>v>>w;
		edge.push_back({w, {u, v}});
	}
	sort(edge.begin(), edge.end());
	for(int i=1; i<=n; i++){
		make_set(i);
	}
	long long int ans=0;
	for(int i=0; i<edge.size(); i++){
		int u=edge[i].second.first;
		int v=edge[i].second.second;
		long long int w=edge[i].first;
		if(find_set(u)==find_set(v)){
			continue;
		}
		union_sets(u, v);
		ans+=w;
	}
	cout<<ans;
	return 0;
}