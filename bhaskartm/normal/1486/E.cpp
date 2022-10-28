#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

const int N=1e5+5;
int dis[N][51][2];
vector<vector<pair<int, int>>>adj;
//0 good // 1 bad
const int M=1e18;

 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	adj.resize(n+1);
	for(int i=0; i<m; i++){
		int u, v, w;
		cin>>u>>v>>w;
		adj[u].pb({v, w});
		adj[v].pb({u, w});
	}
	priority_queue<pair<int, pair<pair<int, int>, int>>>pq;
	for(int i=1; i<=n; i++){
		for(int j=0; j<=50; j++){
			for(int k=0; k<2; k++){
				dis[i][j][k]=M;
			}
		}
	}
	dis[1][0][0]=0;
	pq.push({0, {{1, 0}, 0}});
	while(!pq.empty()){
		auto uu=pq.top();
		pq.pop();
		int v=uu.s.f.f;
		if(uu.s.s==0){
			for(auto u:adj[v]){
				if(dis[u.f][u.s][1]>-uu.f){
					dis[u.f][u.s][1]=-uu.f;
					pq.push({uu.f, {{u.f, u.s}, 1}});
				}
			}
		}
		else{
			for(auto u:adj[v]){
				int di=(-uu.f)+(u.s+uu.s.f.s)*(u.s+uu.s.f.s);
				if(di<dis[u.f][0][0]){
					dis[u.f][0][0]=di;
					pq.push({-di, {{u.f, 0}, 0}});
				}
			}
		}
	}
	
	for(int i=1; i<=n; i++){
		int mini=M;
		for(int j=0; j<=50; j++){
			mini=min(mini, dis[i][j][0]);
		}
		if(mini==M){
			cout<<-1<<" ";
		}
		else{
			cout<<mini<<" ";
		}
	}
	
	return 0;
}