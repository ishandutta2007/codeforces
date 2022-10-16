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

const int INF = 1e9 + 7, N = 1e5 + 7;

vi G[N];
vi stk;
int vis[N], dfn[N];
array<int, 2> low[N];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

array<int, 2> add(array<int, 2> a, array<int, 2> b) {
	array<int, 4> c = {a[0], a[1], b[0], b[1]};
	sort(ALL(c));
	return {c[0], c[1]};
}
array<int, 2> add(array<int, 2> a, int b) {
	array<int, 3> c = {a[0], a[1], b};
	sort(ALL(c));
	return {c[0], c[1]};
}

bool ok(int u) {
	bool ret = true;
	vis[u] = 1;
	dfn[u] = stk.size();
	stk.PB(u);
	low[u] = {dfn[u], dfn[u]};
	for(int v:G[u]) {
		if(vis[v] == 0) {
			ret &= ok(v);
			low[u] = add(low[u], low[v]);
		} else if(vis[v] == 1) { // back-edge
			low[u] = add(low[u], dfn[v]);
		} else if(vis[v] == 2) {
			ret = false;
		}
	}
	vis[u] = 2;
	return ret;
}


void solve() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
	}
	vi ans;
	for(int tt = 0; tt < 100; tt++) {
		int r = rng() % n + 1;
		for(int i = 1; i <= n; i++) vis[i] = 0;
		stk.clear();
		if(ok(r)) {
			vi yes(n + 1);
			for(int x:stk) {
				if(x == r) {
					yes[x] = 1;
					continue;
				}
				if(low[x][0] < dfn[x] && low[x][1] < dfn[x]) continue;
				yes[x] = yes[stk[low[x][0]]];
			}
			for(int i = 1; i <= n; i++)
				if(yes[i])
					ans.PB(i);
			break;
		}
	}
	if(5 * ans.size() < n) cout << -1 << endl;
	else {
		for(int i:ans) cout << i << " ";
		cout << endl;
	}
	for(int i = 1; i <= n; i++) {
		G[i].clear();
	}
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) solve();
	
}