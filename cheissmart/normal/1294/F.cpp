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

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 200005;

int ans;
vi G[N];
int h[N];

void dfs(int u, int p = -1) {
	h[u] = 1;
	for(int i = 0;i < (int)G[u].size() - 1; i++)
		if(G[u][i] == p) {
			swap(G[u][i], G[u].back());
			break;
		}
	for(int i=0;i<(int)G[u].size()-1;i++) {
		int v = G[u][i];
		dfs(v, u);
		h[u] = max(h[u], h[v]+1);
	}
}

int root;

void dfs1(int u, int up = 0) {
	vi w;
	if(up) w.PB(up);
	w.PB(0);
	for(int i=0;i<(int)G[u].size()-1;i++) {
		int v = G[u][i];
		w.PB(h[v]);
	}
	sort(ALL(w));
	if(w.size() >= 3) {
		int cans = w[w.size()-1]+w[w.size()-2]+w[w.size()-3];
		if(cans > ans) {
			ans = cans;
			root = u;
		}
	}
	vi p;
	for(int i=0;i<(int)G[u].size()-1;i++) {
		int v = G[u][i];
		p.PB(h[v]);
	}
	for(int i=1;i<(int)p.size();i++) p[i] = max(p[i], p[i-1]);
	int mx = up;
	for(int i=(int)G[u].size()-2;i>=0;i--) {
		int v = G[u][i];
		dfs1(v, max(mx, (i ? p[i-1] : 0))+1);
		mx = max(mx, h[v]);
	}	
}

pi dfs2(int u, int p) {
	int h = 1, r = u;
	for(int v:G[u]) if(v!=p) {
		pi t = dfs2(v, u);
		if(t.F+1 > h) {
			h = t.F + 1;
			r = t.S;
		}
	}
	return MP(h, r);
}

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n-1;i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	G[1].PB(-1);
	dfs(1);
	dfs1(1);
	cout << ans << endl;
	V<pi> cm;
	G[1].pop_back();
	cm.EB(0, root);
	for(int v:G[root]) {
		cm.PB(dfs2(v, root));
	}
	sort(ALL(cm));
	reverse(ALL(cm));
	assert(cm.size() >= 3);
	for(int i=0;i<3;i++) {
		cout << cm[i].S << " ";
	}
}