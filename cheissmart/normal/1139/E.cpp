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

const int INF = 1e9 + 7, N = 5005;

int p[N], c[N], match[N], ans[N], vis[N];
map<int, int> cnt[N];
vi G[N];

bool dfs(int u) {
	if(vis[u]) return false;
	vis[u] = 1;
	for(int v:G[u]) {
		if(match[v] == -1) {
			match[v] = u;
			return true;
		}
		if(dfs(match[v])) {
			match[v] = u;
			return true;
		}
	}
	return false;
}

bool ok(int u) {
	memset(vis, 0, sizeof vis);
	return dfs(u);
}

signed main()
{
	IO_OP;
	memset(match, -1, sizeof match);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> p[i];
	for(int i = 0; i < n; i++) {
		cin >> c[i];
		c[i]--;
		cnt[c[i]][p[i]]++;
	}
	int d;
	cin >> d;
	V<array<int, 3>> v;
	for(int i = 0; i < d; i++) {
		int k;
		cin >> k;
		k--;
		if(--cnt[c[k]][p[k]] == 0) {
			v.PB({i, p[k], c[k]});
		}
	}
	for(int i = 0; i < m; i++)
		for(pi e:cnt[i]) if(e.S)
			G[e.F].PB(i);
	int cur = 0;
	while(ok(cur)) cur++;
	int qi = d - 1;
	while(v.size()) {
		while(qi >= v.back()[0]) ans[qi--] = cur;
		G[v.back()[1]].PB(v.back()[2]);
		v.pop_back();
		while(ok(cur)) cur++;
	}
	while(qi >= 0) ans[qi--] = cur;
	for(int i = 0; i < d; i++) cout << ans[i] << endl;

}