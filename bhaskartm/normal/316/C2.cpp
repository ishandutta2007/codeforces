#include <bits/stdc++.h>
using namespace std;

const int mxN=6405;
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

int main() {
	int N, M;
	cin>>N>>M;
	MCMF g(0, N*M+1, N*M+2);
	
	int arr[N+1][M+1];
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cin>>arr[i][j];
		}
	}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			if((i+j)%2==0){
				g.addEdge(0, (i-1)*(M)+j, 0, 1);
			}
			else{
				g.addEdge((i-1)*M+j, M*N+1, 0, 1);
			}
		}
	}
	
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			if((i+j)%2==1){
				continue;
			}
			if(i+1<=N){
				if(arr[i][j]==arr[i+1][j]){
					g.addEdge((i-1)*M+j, (i)*M+j, 0, 1);
				}
				else{
					g.addEdge((i-1)*M+j, (i)*M+j, 1, 1);
				}
			}
			if(i-1>=1){
				if(arr[i][j]==arr[i-1][j]){
					g.addEdge((i-1)*M+j, (i-2)*M+j, 0, 1);
				}
				else{
					g.addEdge((i-1)*M+j, (i-2)*M+j, 1, 1);
				}
			}
			if(j+1<=M){
				if(arr[i][j]==arr[i][j+1]){
					g.addEdge((i-1)*M+j, (i-1)*M+j+1, 0, 1);
				}
				else{
					g.addEdge((i-1)*M+j, (i-1)*M+j+1, 1, 1);
				}
			}
			if(j-1>=1){
				if(arr[i][j]==arr[i][j-1]){
					g.addEdge((i-1)*M+j, (i-1)*M+j-1, 0, 1);
				}
				else{
					g.addEdge((i-1)*M+j, (i-1)*M+j-1, 1, 1);
				}
			}
		}
	}
	
	auto ans=g.minCostMaxFlow();
	cout<<ans.first;
	return 0;
}