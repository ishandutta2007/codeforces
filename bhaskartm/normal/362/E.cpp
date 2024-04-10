#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int mxN=55;
const int inf=2e9;

struct Edgee{
	int to, cost, cap, flow, backEdge;
};

struct MCMF{
	int s, t, n;
	vector<Edgee>g[mxN];
	MCMF(int _s, int _t, int _n){
		s=_s, t=_t, n=_n;
	}
	void addEdge(int u, int v, int cost, int cap){
		Edgee e1={v, cost, cap, 0, g[v].size()};
		Edgee e2={u, -cost, 0, 0, g[u].size()};
		g[u].push_back(e1);
		g[v].push_back(e2);
	}
	pair<int, int>minCostMaxFlow(){
		int flow=0;
		int cost=0;
		vector<int>state(n), from(n), from_edge(n), d(n);
		deque<int>q;
		while(true){
			for(int i=0; i<n; i++)
				state[i]=2, d[i]=inf, from[i]=-1;
			state[s]=1; q.clear(); q.push_back(s); d[s]=0;
			while(!q.empty()){
				int v=q.front(); q.pop_front(); state[v]=0;
				for(int i=0; i<(int)g[v].size(); i++){
					Edgee e=g[v][i];
					if(e.flow>=e.cap || d[e.to]<=d[v]+e.cost){
						continue;
					}
					int to=e.to; d[to]=d[v]+e.cost;
					from[to]=v; from_edge[to]=i;
					if(state[to]==1) continue;
					if(!state[to] || (!q.empty() && d[q.front()]>d[to]))
						q.push_front(to);
					else q.push_back(to);
					state[to]=1;
				}
			}
			if(d[t] == inf) break;
			int it=t, addflow=inf;
			while(it!=s){
				addflow=min(addflow, g[from[it]][from_edge[it]].cap-g[from[it]][from_edge[it]].flow);
				it=from[it];
			}
			it=t;
			while(it!=s){
				g[from[it]][from_edge[it]].flow+=addflow;
				g[it][g[from[it]][from_edge[it]].backEdge].flow-=addflow;
				cost+=g[from[it]][from_edge[it]].cost*addflow;
				it=from[it];
			}
			flow+=addflow;
		}
		return {cost, flow};
	}
};


main() {
	int n, k;
	cin>>n>>k;
	int arr[n+1][n+1];
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>arr[i][j];
		}
	}
	int hi=10000000000005;
	int lo=0;
	int ans=0;
	while(lo<=hi){
		int mid=(lo+hi)/2;
		MCMF g(0, n+1, n+2);
		g.addEdge(0, 1, 0, mid);
		g.addEdge(n, n+1, 0, mid);
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(arr[i][j]==0){
					continue;
				}
				g.addEdge(i, j, 0, arr[i][j]);
				g.addEdge(i, j, 1, inf);
			}
		}
		auto val=g.minCostMaxFlow();
		if(val.first<=k && val.second>0){
			lo=mid+1;
			ans=mid;
		}
		else{
			hi=mid-1;
		}
	}
	cout<<ans;
	return 0;
}