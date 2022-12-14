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

const int INF = 1e9 + 7, N = 505;

int a[N][N], ans[N], cnt;

V<pi> edges;

int go(vi v) {
	if(v.size() == 1) {
		ans[v[0]] = a[v[0]][v[0]];
		return v[0];
	}
	int mxw = 0;
	for(int i = 0; i < int(v.size()); i++)
		for(int j = i + 1; j < int(v.size()); j++)
			mxw = max(mxw, a[v[i]][v[j]]);
	int root = ++cnt;
	ans[root] = mxw;
	vi vis(v.size());
	for(int i = 0; i < int(v.size()); i++) if(vis[i] == 0) {
		vi subtree;
		for(int j = i; j < int(v.size()); j++) {
			if(a[v[i]][v[j]] < mxw) {
				subtree.PB(v[j]);
				vis[j] = 1;
			}
		}
		int u = go(subtree);
		edges.EB(u, root);
	}
	return root;
}

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	cnt = n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];
	vi v(n);
	iota(ALL(v), 1);
	int r = go(v);
	cout << cnt << '\n';
	for(int i = 1; i <= cnt; i++)
		cout << ans[i] << " ";
	cout <<'\n';
	cout << r << '\n';
	for(pi p:edges) cout << p.F << ' ' << p.S << '\n';

}