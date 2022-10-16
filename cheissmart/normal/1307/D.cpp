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

int a[N], d1[N], d2[N], vis[N];
int n, m, k;
vi G[N];

void BFS(int s, int *d) {
	memset(vis, 0, sizeof vis);
	vis[s] = 1, d[s] = 0;
	vi v({s});
	for(int i=0;i<v.size();i++) {
		for(int u:G[v[i]]) {
			if(!vis[u]) {
				vis[u] = 1;
				d[u] = d[v[i]] + 1;
				v.PB(u);
			}
		}
	}
}

bool cmp(int x, int y) {
	return d1[x] - d2[x] < d1[y] - d2[y];
}

signed main()
{
	IO_OP;
	
	cin >> n >> m >> k;
	for(int i=0;i<k;i++) cin >> a[i];
	for(int i=0;i<m;i++){
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	BFS(1, d1);
	BFS(n, d2);
	int ans = d1[n];
	sort(a, a+k, cmp);
	int mx = -1, mx1 = -INF;
	for(int i=0;i<k;i++) {
		mx = max(mx, d2[a[i]] + mx1 + 1);
		mx1 = max(mx1, d1[a[i]]);
	}
	ans = min(ans, mx);
	cout << ans << endl;
}