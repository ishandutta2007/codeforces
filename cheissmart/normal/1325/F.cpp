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

const int INF = 1e9 + 7, N = 2e5 + 7;

vi G[N];
int pa[N], d[N], vis[N], no[N], tar;

void dfs(int u, int p = 0, int depth = 0) {
	vis[u] = 1, d[u] = depth, pa[u] = p;
	vi bk;
	for(int v:G[u]) if(v != p) {
		if(vis[v] && d[v] > d[u]) continue;
		if(vis[v]) {
			bk.PB(v);
			if(d[u] - d[v] + 1 >= tar) {
				vi s;
				int ptr = u;
				do {
					s.PB(ptr);
					ptr = pa[ptr];
				} while(ptr != v);
				s.PB(ptr);
				cout << 2 << endl;
				cout << s.size() << endl;
				for(int e:s) cout << e << " ";
				exit(0);
			}
		} else {
			dfs(v, u, depth + 1);
		}
	}
	if(!no[u]) {
		for(int e:bk) no[e] = true;
		no[p] = true;
	}
}

signed main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	tar = (int)ceil(sqrt(n));
	for(int i=0;i<m;i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	dfs(1);
	vi s;
	for(int i=1;i<=n;i++) if(!no[i]) s.PB(i);
	assert((int)s.size() >= tar);
	cout << 1 << endl;
	for(int i=0;i<tar;i++) cout << s[i] << " ";

}