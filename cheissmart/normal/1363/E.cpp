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
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 200005;

int a[N], b[N], c[N];
int to1[N], to0[N];

vi G[N];

void dfs(int u, int p = -1, int mn = INF) {
	if(b[u] == 0 && c[u] == 1) to1[u]++;
	if(b[u] == 1 && c[u] == 0) to0[u]++;
	mn = a[u] = min(a[u], mn);
	for(int v:G[u]) if(v != p) {
		dfs(v, u, mn);
		to1[u] += to1[v];
		to0[u] += to0[v];
	}
}

int dfs1(int u, int p = -1) {
	int cost = 0, to0_cnt = 0, to1_cnt = 0;
	for(int v:G[u]) if(v != p) {
		cost += dfs1(v, u);
		if(to0[v] > to1[v]) {
			to0_cnt += to0[v] - to1[v];
		} else {
			to1_cnt += to1[v] - to0[v];
		}
	}
	if(b[u] == 0 && c[u] == 1) to1_cnt++;
	if(b[u] == 1 && c[u] == 0) to0_cnt++;
	cost += a[u] * min(to0_cnt, to1_cnt) * 2;
	return cost;
}

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	dfs(1);
	if(to0[1] != to1[1]) return cout << -1 << endl, 0;
	cout << dfs1(1) << endl;

}