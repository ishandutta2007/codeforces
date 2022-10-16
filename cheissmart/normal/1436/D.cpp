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

const int INF = 1e9 + 7, N = 2e5 + 7;

vi G[N];

ll mx[N], leaves[N], a[N];
ll sum[N];

void dfs(int u) {
	if(G[u].size() == 0) {
		mx[u] = a[u];
		sum[u] = a[u];
		leaves[u] = 1;
		return;
	}
	for(int v:G[u]) {
		dfs(v);
		leaves[u] += leaves[v];
		mx[u] = max(mx[u], mx[v]);
		sum[u] += sum[v];
	}
	ll buffer = (ll) leaves[u] * mx[u] - sum[u];
	sum[u] += a[u];
	if(a[u] <= buffer) {
		buffer -= a[u];
	} else {
		ll more = a[u] - buffer;
		mx[u] += (more + leaves[u] - 1) / leaves[u];
		buffer = (more - more % leaves[u]) % leaves[u];
	}
}

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	for(int i = 2; i <= n; i++) {
		int p;
		cin >> p;
		G[p].PB(i);
	}
	for(int i = 1; i <= n; i++) cin >> a[i];
	dfs(1);
	cout << mx[1] << endl;

}