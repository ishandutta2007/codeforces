// Problem : D. Dima and Trap Graph
// Contest : Codeforces Round #214 (Div. 2)
// URL : https://codeforces.com/problemset/problem/366/D
// Memory Limit : 256.000000 MB
// Time Limit : 3000.000000 milisec
// Powered by CP Editor (https://github.com/coder3101/cp-editor)
 
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int MN = 1e3+3;
struct Edge {
	int a,b,l,r;
	void read(){scanf ("%d%d%d%d",&a,&b,&l,&r);}
};
vector<pii> adj[MN]; int n; int dist[MN];
int solve () {
	priority_queue<pii> pq; //so stupid
	memset(dist,-1,sizeof dist);
	dist[1] = INT_MAX;
	pq.push({INT_MAX,1});
	while (!pq.empty()) {
		int cur = pq.top().second, d = pq.top().first; pq.pop();
		if (d < dist[cur]) continue;
		for (pii p : adj[cur]) if (min(d,p.second) > dist[p.first]) {
			dist[p.first] = min(d,p.second);
			pq.push({dist[p.first],p.first});
		}
	}
	return dist[n];
}
int main () {
	int m;
	scanf ("%d %d",&n,&m);
	vector<Edge> edges(m);
	for (auto &au : edges) au.read();
	sort(all(edges),[](Edge a, Edge b){return a.l < b.l;});
	int ans = 0;
	for (auto &e : edges) {
		adj[e.a].emplace_back(e.b,e.r);
		adj[e.b].emplace_back(e.a,e.r);
		ans = max(ans,solve()-e.l+1);
	}
	printf(ans?"%d\n":"Nice work, Dima!\n",ans);
	return 0;
}