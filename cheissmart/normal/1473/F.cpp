#include <bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define V vector
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "LINE(" << __LINE__ << ") -> " << #x << " is " << (x) << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

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
	static const int N = 3005, INF = 2147483647;
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


const int INF = 1e9 + 7, N = 3005;

int a[N], b[N];

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;

	int s = n + 1, t = n + 2;
	f.init(n + 2, s, t);
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		cin >> b[i];
		if(b[i] >= 0) {
			ans += b[i];
			f.add_edge(s, i, b[i]);
		}
		else
			f.add_edge(i, t, -b[i]);
	}
	for(int i = 1; i <= n; i++) {
		unordered_set<int> seen;
		for(int j = i - 1; j >= 1; j--) {
			if(a[i] % a[j] == 0 && !seen.count(a[j])) {
				seen.insert(a[j]);
				f.add_edge(i, j, INF);
			}
		}
	}
	cout << ans - f.maxflow() << '\n';

}