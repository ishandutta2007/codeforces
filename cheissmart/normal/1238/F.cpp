#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 3e5 + 87;

vi G[N];
int dp1[N], dp2[N], ans = 0;

void dfs(int u, int p = -1) {
	int mx1 = 0, mx2 = 0, mx3 = 0, ch = 0;
	for(int v:G[u]) if(v != p) {
		dfs(v, u);
		ch++;
		if(dp2[v] > mx1) mx2 = mx1, mx1 = dp2[v];
		else if(dp2[v] > mx2) mx2 = dp2[v];
		mx3 = max(mx3, dp1[v]);
	}
	dp1[u] = dp2[u] = 1;
	if(ch >= 2) dp1[u] = max(dp1[u], mx1 + mx2 + ch - 1);
	if(ch) dp1[u] = max(dp1[u], mx1 + ch);
	if(ch) dp2[u] = max(dp2[u], mx1 + ch);
	ans = max(ans, dp1[u]);
	if(ch) ans = max(ans, mx3+1);
}

void solve() {
	int n;
	cin >> n;
	for(int i=0;i<n-1;i++) {
		int x, y;
		cin >> x >> y;
		G[x].PB(y);
		G[y].PB(x);
	}
	ans = 0;
	dfs(1);
	cout << ans << endl;
	for(int i=1;i<=n;i++)
		G[i].clear();
}

int32_t main()
{
	IO_OP;
	
	int q;
	for(cin >> q;q--;) solve();
	
}