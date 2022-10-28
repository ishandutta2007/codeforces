#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double

const int mxN=805;
const int inf=2e9;
 
struct Edgee{
	int to;
	double cost;
	int cap, flow, backEdge;
};
 
struct MCMF{
	int s, t, n;
	vector<Edgee>g[mxN];
	MCMF(int _s, int _t, int _n){
		s=_s, t=_t, n=_n;
	}
	void addEdge(int u, int v, double cost, int cap){
		Edgee e1={v, cost, cap, 0, g[v].size()};
		Edgee e2={u, -cost, 0, 0, g[u].size()};
		g[u].push_back(e1);
		g[v].push_back(e2);
	}
	pair<double, int>minCostMaxFlow(){
		int flow=0;
		double cost=0;
		vector<int>state(n), from(n), from_edge(n);
		vector<double>d(n);
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
	int n;
	cin>>n;
	MCMF g(0, 2*n+1, 2*n+2);
	vector<pair<int, int>>v;
	int maxi=-10000;
	for(int i=0; i<n; i++){
		int x, y;
		cin>>x>>y;
		maxi=max(maxi, y);
		v.push_back({x, y});
	}
	for(int i=0; i<n; i++){
		if(v[i].second!=maxi){
			g.addEdge(n+i+1 ,2*n+1, 0, 1);
		}
	}
	for(int i=1; i<=n; i++){
		g.addEdge(0, i, 0, 2);
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(v[j].second<v[i].second){
				double c=sqrt((v[j].second-v[i].second)*(v[j].second-v[i].second)+(v[j].first-v[i].first)*(v[j].first-v[i].first));
				g.addEdge(i+1, j+n+1, c, 1);
			}
		}
	}
	auto x=g.minCostMaxFlow();
	if(x.second!=n-1){
		cout<<-1;
		return 0;
	}
	cout<<setprecision(20)<<x.first;
	return 0;
}