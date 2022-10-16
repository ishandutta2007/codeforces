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

const int INF = 1e9 + 7;

int a[100005], pre[100005][105], vis[100005];
vi G[100005], with[105];

void BFS(int type) {
	memset(vis, 0, sizeof vis);
	vi v;
	for(int u:with[type]) {
		v.PB(u);
		vis[u] = 1;
		pre[u][type] = 0;
	}
	for(int i=0;i<v.size();i++) {
		int u = v[i];
		for(int w:G[u]) {
			if(!vis[w]) {
				vis[w] =  1;
				v.PB(w);
				pre[w][type] = pre[u][type] + 1;
			}
		}
	}

} 

signed main()
{
	IO_OP;
	
	int n, m, k, s;
	cin >> n >> m >> k >> s;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		with[a[i]].PB(i);
	}
	for(int i=0;i<m;i++) {
		int u, v;
		cin >>u  >> v;
		G[u].PB(v);
		G[v].PB(u);
	}	
	for(int i=1;i<=k;i++)
		BFS(i);
	for(int i=1;i<=n;i++) {
		vi v;
		for(int j=1;j<=k;j++)
			v.PB(pre[i][j]);
		sort(ALL(v));
		int ans = 0;
		for(int i=0;i<s;i++)
			ans += v[i];
		cout << ans << " ";
	}
}