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

const int INF = 1e9 + 7, N = 1e5 + 7;

int u[N], v[N], vis[N], low[N], tin, cnt;
V<pi> G[N];
vi s, bcc[N];

void dfs(int u, int p = 0) {
	vis[u] = low[u] = ++tin;
	for(pi edge:G[u]) if(edge.F != p) {
		int v = edge.F;
		if(vis[v] && vis[v] > vis[u]) continue;
		s.PB(edge.S);
		if(vis[v]) low[u] = min(low[u], vis[v]);
		else {
			dfs(v, u);
			if(low[v] >= vis[u]) {
				cnt++;
				int k;
				do {
					k = s.back(); s.pop_back();
					bcc[cnt].PB(k);
				} while(k != edge.S);
			}
			low[u] = min(low[u], low[v]);
		}
	}
}

int deg[N];

signed main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=0;i<m;i++) {
		cin >> u[i] >> v[i];
		G[u[i]].EB(v[i], i);
		G[v[i]].EB(u[i], i);
	}
	for(int i=1;i<=n;i++) {
		if(!vis[i]) dfs(i);
	}
	vi ans;
	for(int i=1;i<=cnt;i++) {
		for(int j:bcc[i]) deg[u[j]] = deg[v[j]] = 0;
		for(int j:bcc[i]) deg[u[j]]++, deg[v[j]]++;
		bool ok = true;
		for(int j:bcc[i]) if(deg[u[j]] != 2 || deg[v[j]] != 2) ok = false;
		if(ok) {
			for(int j:bcc[i]) ans.PB(j);
		}
	}
	sort(ALL(ans)); 
	cout << ans.size() << endl;
	for(int e:ans) cout << e + 1 << " ";


}