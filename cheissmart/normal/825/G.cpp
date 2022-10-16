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

int mn[N];
vi G[N];

void dfs(int u, int p = 0) {
	mn[u] = u;
	if(p) mn[u] = min(mn[u], mn[p]);
	for(int v:G[u]) if(v != p)
		dfs(v, u);
}

signed main()
{
	IO_OP;

	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	int s;
	cin >> s >> s;
	s = (s % n) + 1;
	dfs(s);
	q--;
	int tt = INF, last = 0;
	while(q--) {
		int op, x;
		cin >> op >> x;
		x = (x + last) % n + 1;
		if(op == 1) {
			tt = min(tt, mn[x]);
		} else {
			cout << (last = min(tt, mn[x])) << '\n';
		}
	}

}