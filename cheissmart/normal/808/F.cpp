#include <bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define V vector
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "LINE(" << __LINE__ << ") -> " << #x << " is " << x << endl
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;
 
const int INF = 1e9 + 7, N = 2e5 + 7;
 
int np[N];
 
struct flow {
	static const int N = 105;
	static const int INF = 2147483647;
	struct Edge {
		int from, to, flow;
		Edge(int _from, int _to, int _flow) {
			from = _from, to = _to, flow = _flow;
		}
	};
	V<Edge> edges;
	vi G[N];
	int d[N], cur[N];
	int n, s, t;
	void init(int _n, int _s, int _t) {
		n = _n, s = _s, t = _t;
		for(int i = 1; i <= n; i++)
			G[i].clear();
		edges.clear();
	}
	void add_edge(int u, int v, int f) {
		edges.EB(u, v, f);
		edges.EB(v, u, 0);
		G[u].PB(edges.size() - 2);
		G[v].PB(edges.size() - 1);
	}
	bool BFS() {
		for(int i = 1; i <= n; i++) d[i] = 0;
		d[s] = 1;
		queue<int> q({s});
		while(q.size()) {
			int u = q.front(); q.pop();
			for(int e:G[u]) {
				if(edges[e].flow) {
					int v = edges[e].to;
					if(d[v] == 0) {
						d[v] = d[u] + 1;
						q.push(v);
					}
				}
			}
		}
		return d[t];
	}
	int DFS(int u, int t, int cur_flow) {
		if(u == t || cur_flow == 0) return cur_flow;
		int res = 0;
		for(int &i = cur[u]; i < G[u].size(); i++) {
			int e = G[u][i];
			int v = edges[e].to, f = edges[e].flow;
			if(d[v] == d[u] + 1) {
				int go = DFS(v, t, min(cur_flow, f));
				edges[e].flow -= go;
				edges[e ^ 1].flow += go;
				res += go;
				cur_flow -= go;
				if(cur_flow == 0) break;
			}
 		}
 		return res;
	}
	int maxflow() {
		int res = 0;
		while(BFS()) {
			for(int i = 1; i <= n; i++)
				cur[i] = 0;
			res += DFS(s, t, INF);
		}
		return res;
	}
} f;
 
signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);
 
	for(ll i = 2; i < N; i++) {
		if(np[i]) continue;
		for(ll j = i * i; j < N; j += i)
			np[j] = 1;
	}
 
	int n, k;
	cin >> n >> k;
	vi p(n), c(n), l(n);
	for(int i = 0; i < n; i++) {
		cin >> p[i] >> c[i] >> l[i];
	}
	auto cal_max = [&] (int max_level) {
		V<pi> even, odd, one;
		for(int i = 0; i < n; i++) {
			if(l[i] <= max_level) {
				if(c[i] == 1) {
					one.EB(p[i], c[i]);
				} else if(c[i] & 1) {
					odd.EB(p[i], c[i]);
				} else {
					even.EB(p[i], c[i]);
				}
			}
		}
		sort(ALL(one));
		if(one.size()) odd.PB(one.back());
		int tot = 0;
		for(pi p:odd) tot += p.F;
		for(pi p:even) tot += p.F;
		// odd: 1, 2, ..., odd.size()
		// even: odd.size() + 1, odd.size() + 2, ..., odd.size() + even.size()
		// s: odd.size() + even.size() + 1, t = s + 1
		int s = odd.size() + even.size() + 1, t = s + 1;
		f.init(odd.size() + even.size() + 2, s, t);
		for(int i = 0; i < odd.size(); i++) {
			int u = i + 1;
			f.add_edge(s, u, odd[i].F);
		}
		for(int i = 0; i < even.size(); i++) {
			int u = odd.size() + i + 1;
			f.add_edge(u, t, even[i].F);
		}
		for(int i = 0; i < odd.size(); i++) {
			for(int j = 0; j < even.size(); j++) {
				if(np[odd[i].S + even[j].S] == 0) {
					int u = i + 1, v = odd.size() + j + 1;
					f.add_edge(u, v, INF);
				}
			}
		}
		return tot - f.maxflow();
	};
	int lb = 1, rb = n;
	while(lb <= rb) {
		int mb = (lb + rb) / 2;
		if(cal_max(mb) >= k) rb = mb - 1;
		else lb = mb + 1;
	}
	if(lb == n + 1) lb = -1;
	cout << lb << '\n';
 
}