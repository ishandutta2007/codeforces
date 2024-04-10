#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

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
	static const int N = 1e5, INF = 2147483647;
	int n, s, t, d[N], cur[N];
	vi G[N];
	struct Edge {
		int from, to, flow;
		Edge (int _from, int _to, int _flow) {
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
	void add_edge(int u, int v, int flow) {
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
	int DFS(int u, int t, int cur_flow) {
		if(u == t || cur_flow == 0) return cur_flow;
		int flow = 0;
		for(int &i = cur[u]; i < G[u].size(); i++) {
			Edge& e = edges[G[u][i]];
			if(d[e.to] == d[e.from] + 1) {
				int f = DFS(e.to, t, min(cur_flow, e.flow));
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
	int maxflow() {
		int ret = 0;
		while(BFS()) {
			for(int i=1;i<=n;i++) cur[i] = 0;
			ret += DFS(s, t, INF);
		}
		return ret;
	}
} f;

int sum = 0, s, t, ss, tt;

void add_edge(int u, int v, int l, int r) {
	sum += l;
	f.add_edge(u, v, r - l);
	f.add_edge(u, tt, l);
	f.add_edge(ss, v, l);
}

signed main()
{
	IO_OP;

	int n, b, q;
	cin >> n >> b >> q;
	s = b + 1, t = b + 2, ss = b + 3, tt = b + 4;
	int cur = tt + 1;
	f.init(tt + q + 2 + 5, ss, tt);
	f.add_edge(t, s, INF);
	V<pi> qq;
	qq.PB({0, 0});
	for(int i = 0; i < q; i++) {
		pi p;
		cin >> p.F >> p.S;
		qq.PB(p);
	}
	qq.PB({b, n});
	sort(ALL(qq));
	for(int i = 0; i + 1 < qq.size(); i++) {
		if(qq[i].F == qq[i + 1].F) {
			if(qq[i] != qq[i + 1]) {
				cout << "unfair" << endl;
				return 0;
			}
			continue;
		}
		if(qq[i].S > qq[i + 1].S) {
			cout << "unfair" << endl;
			return 0;
		}
		add_edge(s, cur, qq[i + 1].S - qq[i].S, qq[i + 1].S - qq[i].S);
		for(int j = qq[i].F + 1; j <= qq[i + 1].F; j++)
			add_edge(cur, j, 0, 1);
		// cerr << qq[i].F + 1 << " ~ " << qq[i + 1].F << ": " << qq[i + 1].S - qq[i].S << " | " << cur << endl;
		cur++;
	}
	for(int i = 1; i <= b; i++) {
		add_edge(i, cur + i % 5, 0, 1);
	}
	for(int i = 0; i < 5; i++)
		add_edge(cur + i, t, n / 5, n / 5);
	f.add_edge(t, s, INF);
	int ff = f.maxflow();
	if(ff != sum) {
		cout << "unfair" << endl;
		return 0;
	}
	cout << "fair" << endl;

}