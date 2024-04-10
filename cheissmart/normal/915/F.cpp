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

const int INF = 1e9 + 7, N = 1e6 + 7;

pi a[N];
vi G[N];
int n, vis[N], p[N], sz[N];

ll ans = 0;

int find(int u) {
	return p[u] == u ? u : p[u] = find(p[u]);
}

void unite(int x, int y) {
	int rx = find(x), ry = find(y);
	if(rx == ry) return;
	if(sz[rx] > sz[ry]) swap(rx, ry);
	p[rx] = ry;
	sz[ry] += sz[rx];
}

void go() {
	sort(a+1, a+n+1);
	memset(vis, 0, sizeof vis);
	for(int i = 1; i <= n; i++) p[i] = i, sz[i] = 1;
	for(int i = 1; i <= n; i++) {
		int u = a[i].S;
		vis[u] = 1;
		for(int v:G[u]) if(vis[v]) {
			ans += (ll) a[i].F * sz[find(u)] * sz[find(v)];
			unite(u, v);
		}
	}
}

signed main()
{
	IO_OP;
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i].F, a[i].S = i;
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	go();
	for(int i = 1; i <= n; i++) a[i].F *= -1;
	go();
	cout << ans << endl;

}