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

const int INF = 1e9 + 7, N = 100005;

int ans[N], c[N];
vi G[N];

pair<map<int, int>, pi> dfs(int u, int p = 0) {
	pair<map<int, int>, pi> ret;
	ret.F[c[u]]++, ret.S.F = 1, ret.S.S = c[u];
	for(int v:G[u]) if(v != p) {
		auto r = dfs(v, u);
		if(r.F.size() > ret.F.size()) swap(ret, r);
		for(pi e:r.F) {
			int x = e.F, y = e.S;
			ret.F[x]+=y;
			if(ret.F[x] > ret.S.F) {
				ret.S.F = ret.F[x];
				ret.S.S = x;
			} else if(ret.F[x] == ret.S.F) {
				ret.S.S += x;
			}
		}
	}
	ans[u] = ret.S.S;
	return ret;
}

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> c[i];
	for(int i=0;i<n-1;i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	dfs(1);
	for(int i=1;i<=n;i++) cout << ans[i] << " ";
	
}