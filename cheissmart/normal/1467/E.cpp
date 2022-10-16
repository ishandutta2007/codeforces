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

int a[N], bad[N], has_up[N], bad_link[N];

vi G[N];

map<int, int> cnt;

map<int, int> dfs1(int u, int p = 0) {
	map<int, int> res;
	for(int v:G[u]) if(v != p) {
		auto tt = dfs1(v, u);
		bad_link[v] = bad[v];
		if(tt.count(a[u])) bad_link[v] = 1;
		if(tt.size() > res.size()) swap(res, tt);
		for(pi p:tt) res[p.F] += p.S;
		if(bad_link[v]) bad[u] = 1;
	}
	res[a[u]]++;
	if(res[a[u]] != cnt[a[u]])
		has_up[u] = 1;
	return res;
}

void dfs2(int u, bool up_bad_link = false, int p = 0) {
	if(has_up[u]) up_bad_link = true;
	if(up_bad_link) bad[u] = 1;
	int bad_link_cnt = up_bad_link;
	for(int v:G[u]) if(v != p)
		bad_link_cnt += bad_link[v];
	for(int v:G[u]) if(v != p) {
		dfs2(v, bad_link_cnt - bad_link[v] > 0 ? true : false, u);
	}
}

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}

	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	dfs1(1);
	dfs2(1);
	int ans = 0;
	for(int i = 1; i <= n; i++)
		if(bad[i] == 0)
			ans++;
	cout << ans << endl;
}