#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
const ll INF = 1000000000000000000LL;

#define VEI(w,e) ((E[e].u == w) ? E[e].v : E[e].u)
#define CAP(w,e) ((E[e].u == w) ? E[e].cap[0] - E[e].flow : E[e].cap[1] + E[e].flow)
#define ADD(w,e,f) E[e].flow += ((E[e].u == w) ? (f) : (-(f)))

struct Edge { int u, v; ll cap[2], flow; };

VI d, act;

bool bfs(int s, int t, VVI& adj, vector<Edge>& E) {
	queue<int> Q;
	d = VI(adj.size(), -1);
	d[t] = 0;
	Q.push(t);
	while (not Q.empty()) {
		int u = Q.front(); Q.pop();
		for (int i = 0; i < int(adj[u].size()); ++i) {
			int e = adj[u][i], v = VEI(u, e);
			if (CAP(v, e) > 0 and d[v] == -1) {
				d[v] = d[u] + 1;
				Q.push(v);
			}
		}
	}
	return d[s] >= 0;
}

ll dfs(int u,int t,ll bot,VVI& adj,vector<Edge>& E) {
	if (u == t) return bot;
	for (; act[u] < int(adj[u].size()); ++act[u]) {
		int e = adj[u][act[u]];
		if (CAP(u, e) > 0 and d[u] == d[VEI(u, e)] + 1) {
			ll inc=dfs(VEI(u,e),t,min(bot,CAP(u,e)),adj,E);
			if (inc) {
				ADD(u, e, inc);
				return inc;
			}
		}
	}
	return 0;
}

ll maxflow(int s, int t, VVI& adj, vector<Edge>& E) {
	for (int i=0; i<int(E.size()); ++i) E[i].flow = 0;
	ll flow = 0, bot;
	while (bfs(s, t, adj, E)) {
		act = VI(adj.size(), 0);
		while ((bot = dfs(s,t,INF, adj, E))) flow += bot;
	}
	return flow;
}

void addEdge(int u, int v, ll cap1, ll cap2, VVI& adj, vector<Edge>& E) {
	Edge e;
	e.u = u;
	e.v = v;
	e.cap[0] = cap1;
	e.cap[1] = cap2;
	adj[u].push_back(E.size());
	adj[v].push_back(E.size());
	E.push_back(e);
}

int main() {
	ll INF = 1e13;
	int n, h, m;
	cin >> n >> h >> m;
	VVI adj(n*h + m + 2);
	vector<Edge> E;
	int cont = 0;
	int sink = n*h + m + 1;
	for (int i = 0; i < n; ++i) {
		++cont;
		addEdge(0,cont,h*h,INF,adj,E);
		for (int j = 1; j < h; ++j) {
			++cont;
			addEdge(cont-1,cont,h*h-j*j,INF,adj,E);
		}
	}
	while (m--) {
		int l, r, x, c;
		cin >> l >> r >> x >> c;
		++cont;
		addEdge(cont,sink,c,0,adj,E);
		if (x == h) continue;
		for (int i = l-1; i < r; ++i) {
			int val = i*h + x + 1;
			addEdge(val,cont,INF,0,adj,E);
		}
	}
	cout << h*h*n - maxflow(0,sink,adj,E) << '\n';
}