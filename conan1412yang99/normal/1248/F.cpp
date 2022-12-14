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
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1e6 + 87;

vi G[N], g[N], s;

int scc[N], d[N], low[N], cnt, tin;
void dfs(int u) {
	d[u] = low[u] = ++tin;
	s.PB(u);
	for(int v:G[u]) {
		if(!d[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if(!scc[v]) {
			low[u] = min(low[u], d[v]);
		}
	}
	if(low[u] == d[u]) {
		cnt++;
		int t;
		do {
			t = s.back(); s.pop_back();
			scc[t] = cnt; 
		} while(t != u);
	}
}

map<pi, bool> ok;
void init(int n) {
	for(int i=0;i<=n;i++)
		scc[i] = low[i] = d[i] = 0;
	for(int i=0;i<=n;i++)
		G[i].clear(); 
	ok.clear();
	cnt = 0, tin = 0;
}

int32_t main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		init(n);
		for(int i=0;i<m;i++) {
			int u, v;
			cin >> u >> v;
			G[v].PB(u);
		}
		for(int i=1;i<=n;i++)
			if(!scc[i]) dfs(i);
		if(cnt == 1) {
			cout << "No" << endl;
			continue;
		}
		cout << "Yes" << endl;
		for(int i=1;i<=n;i++)
			for(int u:G[i])
				if(scc[u] != scc[i] && !ok[{scc[i], scc[u]}]) {
					ok[{scc[i], scc[u]}] = true;
					g[scc[i]].PB(scc[u]);
				}
		int id = -1;
		for(int i=1;i<=cnt;i++)
			if(g[i].size() == 0) id = i;
		assert(id != -1);
		vi x, y;
		for(int i=1;i<=n;i++) {
			if(scc[i]!=id) x.PB(i);
			else y.PB(i);
		}
		cout << x.size() << " " << y.size() << endl;
		for(int e:x) cout << e << " ";
		cout << endl;
		for(int e:y) cout << e << " ";
		cout << endl;

		for(int i=1;i<=cnt;i++)
			g[i].clear();
	}	
	
}