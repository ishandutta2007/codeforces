#include <bits/stdc++.h>
using namespace std;

vector<vector<long long int>>adj;
int main() {
	long long int t;
	cin>>t;
	for(int g=0; g<t; g++){
		long long int n, m, a, b, c;
		cin>>n>>m>>a>>b>>c;
		adj.resize(n+1);
		long long int arr[m];
		for(int i=0; i<m; i++){
			cin>>arr[i];
		}
		for(int i=0; i<m;i++){
			int u, v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		queue<long long int>q;
		long long int da[n+1];
		for(int i=0; i<=n; i++){
			da[i]=pow(10, 9);
		}
		da[a]=0;
		q.push(a);
		bool visited[n+1];
		for(int i=0; i<=n; i++){
			visited[i]=false;
		}
		visited[a]=true;
		while(!q.empty()){
			int v=q.front();
			q.pop();
			visited[v]=true;
			for(auto u: adj[v]){
				if(visited[u]){
					continue;
				}
				if(da[v]+1<da[u]){
					da[u]=da[v]+1;
					q.push(u);
				}
			}
		}
		long long int db[n+1];
		for(int i=0; i<=n; i++){
			db[i]=pow(10, 9);
		}
		db[b]=0;
		q.push(b);
		
		for(int i=0; i<=n; i++){
			visited[i]=false;
		}
		visited[b]=true;
		while(!q.empty()){
			int v=q.front();
			q.pop();
			visited[v]=true;
			for(auto u: adj[v]){
				if(visited[u]){
					continue;
				}
				if(db[v]+1<db[u]){
					db[u]=db[v]+1;
					q.push(u);
				}
			}
		}
		long long int dc[n+1];
		for(int i=0; i<=n; i++){
			dc[i]=pow(10, 9);
		}
		dc[c]=0;
		q.push(c);
		
		for(int i=0; i<=n; i++){
			visited[i]=false;
		}
		visited[c]=true;
		while(!q.empty()){
			int v=q.front();
			q.pop();
			visited[v]=true;
			for(auto u: adj[v]){
				if(visited[u]){
					continue;
				}
				if(dc[v]+1<dc[u]){
					dc[u]=dc[v]+1;
					q.push(u);
				}
			}
		}
		sort(arr, arr+m);
		long long int pre[m+1];
		pre[0]=0;
		for(int  i=1; i<=m; i++){
			pre[i]=pre[i-1]+arr[i-1];
		}
		long long int mini=pow(10, 18);
		for(int i=1; i<=n; i++){
			if(da[i]+db[i]+dc[i]>m){
				continue;
			}
			long long int ans=0;
			ans=ans+2*pre[db[i]]+(pre[da[i]+db[i]+dc[i]]-pre[db[i]]);
			mini=min(mini, ans);
		}
		cout<<mini<<endl;
		adj.clear();
	}
	return 0;
}