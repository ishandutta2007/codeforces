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

struct CostFlow {
	static const int N = 205;
	static const ll oo = 1e18;
	struct Edge {
		int from, to;
		ll flow, cost;
		Edge(int _from, int _to, ll _flow, ll _cost) {
			from = _from, to = _to, flow = _flow, cost = _cost;
		}
	};
	int n, s, t;
	V<Edge> edges;
	vi G[N];
	ll dist[N];
	int inq[N], prev_edge[N];
	void init(int _n, int _s, int _t) {
		n = _n, s = _s, t = _t;
		for(int i = 1; i <= n; i++) G[i].clear();
		edges.clear();
	}
	void add_edge(int u, int v, ll f, ll c) {
		edges.EB(u, v, f, c);
		edges.EB(v, u, 0, -c);
		G[u].PB(edges.size() - 2);
		G[v].PB(edges.size() - 1);
	}
	pair<ll, ll> flow(ll mxflow = oo) {
		ll flow = 0, cost = 0;
		while(mxflow > 0) {
			// spfa
			for(int i = 1; i <= n; i++) dist[i] = oo, inq[i] = 0;
			dist[s] = 0, inq[s] = 1;
			queue<int> q({s});
			while(q.size()) {
				int u = q.front(); q.pop();
				inq[u] = 0;
				for(int i:G[u]) {
					Edge e = edges[i];
					int v = e.to;
					ll w = e.cost;
					if(e.flow > 0 && dist[u] + w < dist[v]) {
						prev_edge[v] = i;
						dist[v] = dist[u] + w;
						if(!inq[v]) {
							inq[v] = 1;
							q.push(v);
						}
					}
				}
			}
			if(dist[t] == oo) break;
			ll cur_flow = mxflow;
			{   // calculate cur_flow
				int ptr = t;
				while(ptr != s) {
					cur_flow = min(cur_flow, edges[prev_edge[ptr]].flow);
					ptr = edges[prev_edge[ptr]].from;
				}
			}
			{   // update flow
				int ptr = t;
				while(ptr != s) {
					int i = prev_edge[ptr];
					edges[i].flow -= cur_flow;
					edges[i ^ 1].flow += cur_flow;
					ptr = edges[prev_edge[ptr]].from;
				}
			}
			assert(cur_flow > 0);
			cost += cur_flow * dist[t];
			flow += cur_flow, mxflow -= cur_flow;
		}
		return {flow, cost};
	}
 } f;

const int INF = 1e9 + 7, N = 82, M = 1e9;

int a[N], c[N];

signed main()
{
	IO_OP;

	int n, k;
	cin >> n >> k;
	int s = 1, t = 2 * n + 2;
	f.init(n * 2 + 2, s, t);
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> c[i];
	for(int i = 1; i <= n; i++) {
		f.add_edge(i * 2, i * 2 + 1, 1, -M);
		f.add_edge(s, i * 2, 1, c[a[i]]);
		f.add_edge(i * 2 + 1, t, 1, 0);
	}
	f.add_edge(s, t, INF, 0);
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			int cost = (a[i] == a[j] ? 0 : c[a[j]]);
			f.add_edge(i * 2 + 1, j * 2, 1, cost);
		}
	}
	cout << f.flow(k).S + (ll) M * n << '\n';


}