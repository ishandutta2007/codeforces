#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define MAX 20001
#define NIL 0
#define INF (1<<28)

vector<int>G[MAX];
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

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin>>N>>M;
	n=N;
	m=N;
	vector<pair<int, pair<int,  int>>>ed;
	for(int i=0; i<M; i++){
		int u, v, w;
		cin>>u>>v>>w;
		ed.pb({w, {u, v}});
	}
	sort(ed.begin(), ed.end());
	int lo=1;
	int hi=ed.size();
	int ans=-1;
	while(lo<=hi){
		int mid=(lo+hi)/2;
		for(int i=1; i<MAX; i++){
			G[i].clear();
			dist[i]=0;
			match[i]=0;
		}
		for(int i=0; i<mid; i++){
			G[ed[i].s.f].pb(n+ed[i].s.s);
		}
		int val=hopcroft_karp();
		if(val==n){
			hi=mid-1;
			ans=ed[mid-1].f;
		}
		else{
			lo=mid+1;
		}
	}
	cout<<ans;
	return 0;
}