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

const int INF = 1e9 + 7, N = 2e5 + 7;

V<pi> G[N];
int id[N];
int d[805][805];

signed main()
{
	IO_OP;
	
	int n, m, k;
	cin >> n >> m >> k;
	V<array<int, 3>> e;
	for(int i=0;i<m;i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e.PB({w, u, v});
	}
	sort(ALL(e));
	vi node;
	int cnt = 0;
	memset(d, 0x3f, sizeof d);
	for(int i=0;i<min(k, m);i++) {
		int u = e[i][1], v = e[i][2];
		id[u] = id[u] ? id[u] : ++cnt;
		id[v] = id[v] ? id[v] : ++cnt;
		d[id[u]][id[v]] = d[id[v]][id[u]] = e[i][0];
	}
	for(int k=1;k<=cnt;k++) {
		for(int i=1;i<=cnt;i++) {
			for(int j=1;j<=cnt;j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	vi v;
	for(int i=1;i<=cnt;i++)
		for(int j=i+1;j<=cnt;j++)
			v.PB(d[i][j]);
	sort(ALL(v));
	cout << v[k-1] << endl;
	
}