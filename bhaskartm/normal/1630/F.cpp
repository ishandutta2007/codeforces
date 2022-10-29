#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

#define MAX 200005
#define NIL 0
#define INF (1<<28) 



vector<vector<int>>G;
int n, m, match[MAX], dist[MAX];

bool bfs(){
	int i, u, v, len;
	queue<int>Q;
	for(int i=1; i<=n; i++){
		if(match[i]==NIL){
			dist[i]=0;
			Q.push(i);
		}
		else{
			dist[i]=INF;
		}
	}
	dist[NIL]=INF;
	while(!Q.empty()){
		u=Q.front();
		Q.pop();
		if(u!=NIL){
			len=G[u].size();
			for(i=0; i<len; i++){
				v=G[u][i];
				if(dist[match[v]]==INF){
					dist[match[v]]=dist[u]+1;
					Q.push(match[v]);
				}
			}
		}
	}
	return (dist[NIL]!=INF);
}

bool dfs(int u){
	int i, v, len;
	if(u!=NIL){
		len=G[u].size();
		for(i=0; i<len; i++){
			v=G[u][i];
			if(dist[match[v]]==dist[u]+1){
				if(dfs(match[v])){
					match[v]=u;
					match[u]=v;
					return true;
				}
			}
		}
		dist[u]=INF;
		return false;
	}
	return true;
}

int hopcroft_karp(){
	int matching=0, i;
	while(bfs())
		for(i=1; i<=n; i++)
			if(match[i]==NIL && dfs(i))
				matching++;
	return matching;
}
 
int arr[MAX];
int ind[MAX];
const int M=5e4+5;
vector<vector<int>>di;


 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	di.resize(M);
	
	for(int i=1; i<M; i++){
		for(int j=2*i; j<M; j+=i){
			di[j].pb(i);
		}
	}
	
	while(t--){
		
		int num;
		
		cin>>num;
		
		for(int i=1; i<=num; i++){
			cin>>arr[i];
			ind[arr[i]]=i;
		}
		n=2*num;
		m=2*num;
		for(int i=0; i<=n+m; i++){
			dist[i]=0;
			match[i]=0;
		}
		G.clear();
		G.resize(n+1);
		for(int i=1; i<=num; i++){
			for(auto u:di[arr[i]]){
				if(ind[u]==0){
					continue;
				}
				G[num+i].pb(ind[u]+3*num);
				G[num+i].pb(ind[u]+2*num);
				G[i].pb(ind[u]+2*num);
				//cout<<num+i<<" "<<ind[u]+3*num<<endl;
				//cout<<num+i<<" "<<ind[u]+2*num<<endl;
				//cout<<i<<" "<<ind[u]+2*num<<endl;
			}
			G[num+i].pb(2*num+i);
			//cout<<num+i<<" "<<2*num+i<<endl;
		}
		
		
		for(int i=1; i<=num; i++){
			ind[arr[i]]=0;
		}
		
		cout<<hopcroft_karp()-num<<endl;
	}
	return 0;
}