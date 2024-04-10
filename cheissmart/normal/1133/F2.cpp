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

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2e5 + 7;

int u[N], v[N];
int p[N], sz[N];
int vis[N];

int find(int u) {
	return p[u] == u ? p[u] : p[u] = find(p[u]);
}

bool unite(int x, int y) {
	int rx = find(x), ry = find(y);
	if(rx == ry) return false;
	if(sz[rx] > sz[ry]) swap(rx, ry);
	p[rx] = ry;
	sz[ry] += sz[rx];
	return true;
}

signed main()
{
	IO_OP;

	int n, m, d;
	cin >> n >> m >> d;
	vi adj;
	for(int i=0;i<m;i++) {
		cin >> u[i] >> v[i];
		if(u[i] == 1) adj.PB(v[i]);
		if(v[i] == 1) adj.PB(u[i]);
	}
	for(int i=1;i<=n;i++) p[i] = i, sz[i] = 1;
	int comp = n - 1;
	for(int i=0;i<m;i++) {
		if(u[i] != 1 && v[i] != 1) {
			comp -= unite(u[i], v[i]);
		}
	}
	if(comp > d || d > adj.size()) return cout << "NO" << endl, 0;
	V<pi> ans;
	vi adj2;
	for(int i:adj) {
		int j = find(i);
		if(!vis[j]) {
			vis[j] = 1;
			ans.EB(1, i);
			d--;
		} else {
			adj2.PB(i);
		}
	}
	for(int i:adj2) {
		if(d) {
			d--;
			ans.EB(1, i);
		}
	}
	for(int i=1;i<=n;i++) p[i] = i, sz[i] = 1;
	for(pi p:ans) unite(p.F, p.S);
	for(int i=0;i<m;i++) {
		if(u[i] != 1 && v[i] != 1 && unite(u[i], v[i])) {
			ans.EB(u[i], v[i]);
		}
	}
	cout << "YES" << endl;
	for(pi p:ans)
		cout << p.F << " " << p.S << endl;

}