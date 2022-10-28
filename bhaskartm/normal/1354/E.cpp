#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
int color[5005];
bool booly;
int parent[5005];
int size[5005];
void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}
bool dp[5005][5005];
int par[5005][5005];
int cnt1=0;
int cnt2=0;
bool visited[5005];
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
 
 
void dfs(int v, int c){
	cnt1++;
	color[v]=c;
	if(c==0){
		cnt2++;
	}
	visited[v]=true;
	for(auto u: adj[v]){
		if(color[u]==2){
			dfs(u, 1-c);
		}
		else if(color[u]==c){
			booly=true;
		}
		else{
			
		}
	}
}
 
void dfs2(int v, int c){
	visited[v]=true;
	color[v]=c;
	for(auto u:adj[v]){
		if(color[u]==0){
			if(c==1){
				dfs2(u, 2);
			}
			else{
				dfs2(u, 1);
			}
		}
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	booly=false;
	int n, m;
	cin>>n>>m;
	int n1, n2, n3;
	cin>>n1>>n2>>n3;
	for(int i=1; i<=n; i++){
		color[i]=2;
	}
	adj.resize(n+1);
	for(int i=1; i<=n; i++){
		make_set(i);
	}
	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		if(find_set(u)!=find_set(v)){
			union_sets(u, v);
		}
	}
	vector<pair<int, pair<pair<int, int>, pair<int, int>>>>v;
	for(int i=1; i<=n; i++){
		if(!visited[i]){
			cnt1=0;
			cnt2=0;
			
			int node=find_set(i);
			dfs(node, 0);
			if(adj[node].size()==0){
				v.push_back({node, {{1, node}, {0, 0}}});
			}
			else{
				v.push_back({node, {{cnt2, node}, {cnt1-cnt2, adj[node][0]}}});
			}
		}
	}
	
	if(booly){
		cout<<"NO";
		return 0;
	}
	dp[0][v[0].second.first.first]=true;
	dp[0][v[0].second.second.first]=true;
	par[0][v[0].second.first.first]=1;
	par[0][v[0].second.second.first]=2;
	for(int i=1; i<v.size(); i++){
		for(int j=0; j<5005; j++){
			int val1=v[i].second.first.first;
			int val2=v[i].second.second.first;
			if(j>=val1 && dp[i-1][j-val1]==true){
				dp[i][j]=true;
				par[i][j]=1;
			}
			if(j>=val2 && dp[i-1][j-val2]==true){
				dp[i][j]=true;
				par[i][j]=2;
			}
		}
	}
	if(dp[v.size()-1][n2]==false){
		cout<<"NO";
		return 0;
	}
	for(int i=0; i<5005; i++){
		color[i]=0;
		visited[i]=false;
	}
	cout<<"YES"<<endl;
	for(int i=v.size()-1; i>=0; i--){
		int val=par[i][n2];
		
		if(val==1){
			dfs2(v[i].second.first.second, 2);
			n2=n2-v[i].second.first.first;
		}
		else{
			dfs2(v[i].second.second.second, 2);
			n2=n2-v[i].second.second.first;
		}
	}
	
	int cnt3=0;
	for(int i=1; i<=n; i++){
		if(color[i]!=2){
			color[i]=1;
		}
	}
	
	for(int i=1; i<=n; i++){
		if(color[i]==2){
			continue;
		}
		else{
			if(cnt3==n3){
				break;
			}
			color[i]=3;
			cnt3++;
			if(cnt3==n3){
				break;
			}
		}
	}
	for(int i=1; i<=n; i++){
		cout<<color[i];
	}
	return 0;
}