#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const ll INF = 1e18 + 7;

/*
	NOTE: vertices are 1-indexed (1, 2, ..., n)

                *
                * O(N^2 * M), in general
	Complexity: * O(min(N ^ 2 / 3, M ^ 1 / 2) * M), if all capacities = 1 
                * O(sqrt(N) * M), for bipartite graph matching
                *
	WARNING: long long vs int
*/
struct Dinic {
	static const int N = 2010;
	int n, s, t, d[N], cur[N];
	vi G[N];
	struct Edge {
		int from, to;
		ll flow;
		Edge (int _from, int _to, ll _flow) {
			from = _from, to = _to, flow = _flow;
		}
	};
	V<Edge> edges;
	void init(int _n, int _s, int _t) {
		n = _n;
		s = _s;
		t = _t;
		for(int i=1;i<=n;i++) G[i].clear();
        edges.clear();
	}
	void add_edge(int u, int v, ll flow) {
		edges.EB(u, v, flow);
		edges.EB(v, u, 0);
		G[u].PB(edges.size()-2);
		G[v].PB(edges.size()-1);
	}
	bool BFS() {
		for(int i=1;i<=n;i++) d[i] = 0;
		d[s] = 1;
		queue<int> q({s});
		while(q.size()) {
			int u = q.front(); q.pop();
			for(int e:G[u]) {
				int v = edges[e].to;
				if(!d[v] && edges[e].flow > 0) {
					d[v] = d[u] + 1;
					q.push(v);
				}
			}
		}
		return d[t];
	}
	ll DFS(int u, int t, ll cur_flow) {
		if(u == t || cur_flow == 0) return cur_flow;
		ll flow = 0;
		for(int &i = cur[u]; i < G[u].size(); i++) {
			Edge& e = edges[G[u][i]];
			if(d[e.to] == d[e.from] + 1) {
				ll f = DFS(e.to, t, min(cur_flow, e.flow));
				e.flow -= f;
				edges[G[u][i] ^ 1].flow += f;
				flow += f;
				cur_flow -= f;
                if(cur_flow == 0) break;
                /* ^^^^^^^^^^^^^^^^^^^^^
                    this is important
                    (break here so that "i++" will not be executed)
                */
			}
		}
		return flow;
	}
	ll maxflow() {
		ll ret = 0;
		while(BFS()) {
			for(int i=1;i<=n;i++) cur[i] = 0;
			ret += DFS(s, t, INF);
		}
		return ret;
	}
} f;

const int N = 1003;

int x[N], y[N], w[N];

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	int s = n * 2 + 1, t = n * 2 + 2;
	f.init(n * 2 + 2, s, t);
	vi a, b, c, d;
	ll tot = 0;
	for(int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i] >> w[i];
		tot += w[i];
		if(x[i] % 2 && y[i] % 2) a.PB(i);
		else if(x[i] % 2 == 0 && y[i] % 2) b.PB(i);
		else if(x[i] % 2 == 0 && y[i] % 2 == 0) c.PB(i);
		else d.PB(i);
	}
	auto adj = [&] (int i, int j) {
		return abs(x[i] - x[j]) + abs(y[i] - y[j]) == 1;
	};
	for(int i:a) {
		f.add_edge(s, i, w[i]);
		for(int j:b)
			if(adj(i, j))
				f.add_edge(i, j, INF);
	}
	for(int i:b) {
		f.add_edge(i, i + n, w[i]);
		for(int j:c)
			if(adj(i, j))
				f.add_edge(i + n, j, INF);
	}
	for(int i:c) {
		f.add_edge(i, i + n, w[i]);
		for(int j:d)
			if(adj(i, j))
				f.add_edge(i + n, j, INF);
	}
	for(int i:d) {
		f.add_edge(i, t, w[i]);
	}
	cout << tot - f.maxflow() << '\n';
}