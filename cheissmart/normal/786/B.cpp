#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 0x3f3f3f3f3f3f3f3f, N = 1e5 + 5;

int n, q, s;
int d[N*4], num[N], num_cnt;
int seg[N*4][2];
V<pi> G[N*4];

void edge(int a, int b, int w) {
	G[a].EB(b, w);
}

void add_edge(int l, int r, int u, int w, int type, int v = 1, int tl = 1, int tr = n) {
	if(l > r) return;
	if(l == tl && r == tr) {
		if(type == 0)
			edge(num[u], seg[v][1], w);
		else
			edge(seg[v][0], num[u], w);
		return;
	}
	int tm = (tl + tr) / 2;
	add_edge(l, min(r, tm), u, w, type, v*2, tl, tm);
	add_edge(max(l, tm+1), r, u, w, type, v*2+1, tm+1, tr);
}

void build(int v = 1, int tl = 1, int tr = n) {
	if(tl == tr) {
		seg[v][0] = seg[v][1] = num_cnt;
		num[tl] = num_cnt++;
		return;
	}
	int tm = (tl + tr) / 2;
	build(v*2, tl, tm);
	build(v*2+1, tm+1, tr);
	seg[v][0] = num_cnt++;
	seg[v][1] = num_cnt++;
	edge(seg[v*2][0], seg[v][0], 0);
	edge(seg[v*2+1][0], seg[v][0], 0);
	edge(seg[v][1], seg[v*2][1], 0);
	edge(seg[v][1], seg[v*2+1][1], 0);
}

signed main()
{
	IO_OP;
	
	cin >> n >> q >> s;
	build();
	while(q--) {
		int t;
		cin >> t;
		if(t == 1) {
			int u, v, w;
			cin >> u >> v >> w;
			add_edge(v, v, u, w, 0);
		} else if(t == 2) {
			int u, l, r, w;
			cin >> u >> l >> r >> w;
			add_edge(l, r, u, w, 0);
		} else {
			int u, l, r, w;
			cin >> u >> l >> r >> w;
			add_edge(l, r, u, w, 1);
		}
	}
	memset(d, 0x3f, sizeof d);
	priority_queue<pi, V<pi>, greater<pi>> pq;
	d[num[s]] = 0;
	pq.push(MP(d[num[s]], num[s]));
	while(pq.size()) {
		pi p = pq.top(); pq.pop();
		if(p.F > d[p.S]) continue;
		int u = p.S;
		for(pi e:G[u]) {
			if(d[u] + e.S < d[e.F]) {
				d[e.F] = d[u] + e.S;
				pq.push(MP(d[e.F], e.F));
			}
		}
	}
	for(int i=1;i<=n;i++) {
		if(d[num[i]] == INF) cout << -1 << " ";
		else cout << d[num[i]] << " ";
	}
	cout << endl;


}