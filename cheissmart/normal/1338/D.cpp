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

const int INF = 1e9 + 7, N = 1e5 + 7;

vi G[N];

int take[N], not_take[N], ans, n;

void dfs(int u, int p = -1) {
	int ccnt = G[u].size();
	if(p != -1) ccnt--;
	take[u] = 0, not_take[u] = 0;
	for(int v:G[u]) if(v != p) {
		dfs(v, u);
		ans = max(ans, take[u] + not_take[v]);
		ans = max(ans, not_take[u] + max(take[v], not_take[v]) - 1 + (p == -1 ? 0 : 1));
		take[u] = max(take[u], not_take[v] + 1);
		not_take[u] = max(not_take[u], max(take[v], not_take[v]) + ccnt - 1);
	}
	take[u] = max(take[u], 1);
	ans = max(ans, not_take[u] + (p == -1 ? 0 : 1));
	// cerr << u << ": " << take[u] << ", " << not_take[u] << endl;
}

signed main()
{
	IO_OP;

	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	dfs(1);
	cout << ans << endl;

}