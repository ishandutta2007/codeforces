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

struct Edge{
	int u, v, w;
	Edge(int _u=0, int _v=0, int _w=0) {
		u = _u, v = _v, w = _w;
	}
	bool operator<(const Edge t) const {
		return w < t.w;
	}
};

int p[2084], sz[2048];
pi mn[2048];
int x[2084], y[2048], c[2048], k[2048];
bool vis[2084];

void init(int n) {
	for(int i=1;i<=n;i++) {
		p[i] = i, sz[i] = 1;
		mn[i] = {c[i], i};
	}
}

int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}
int cnt;
bool unite(int x, int y) {
	int rx = find(x), ry = find(y);
	if(rx == ry) return false;
	if(sz[rx] < sz[ry]) swap(rx, ry);
	p[ry] = rx;
	sz[rx] += sz[ry];
	cnt -= max(mn[rx].F, mn[ry].F);
	mn[rx] = min(mn[rx], mn[ry]);
	return true;
}


signed main()
{
	IO_OP;
	
	int n, ans;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> x[i] >> y[i];
	for(int i=1;i<=n;i++) cin >> c[i], cnt += c[i];
	for(int i=1;i<=n;i++) cin >> k[i];
	init(n);
	V<Edge> es;
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			es.EB(i, j, (k[i]+k[j]) * (abs(x[i]-x[j]) + abs(y[i]-y[j])));
	sort(ALL(es));
	ans = cnt;
	int tot = 0, j = -1;
	for(int i=0;i<es.size();i++) {
		Edge e = es[i];
		int u = e.u, v = e.v, w = e.w;
		if(find(u) == find(v)) continue;
		if(max(mn[find(u)].F, mn[find(v)].F) >= w){
			unite(u, v);
			tot += w;
			if(tot + cnt < ans) {
				ans = tot + cnt;
				j = i;
			}
		}
	}
	cout << ans << endl;
	init(n);
	V<pi> eee;
	for(int i=0;i<=j;i++) {
		Edge e = es[i];
		int u = e.u, v = e.v, w = e.w;
		if(find(u) == find(v)) continue;
		if(max(mn[find(u)].F, mn[find(v)].F) >= w){
			unite(u, v);
			eee.EB(u, v);
		}
	}
	vi vvv;
	for(int i=1;i<=n;i++) {
		int r = find(i);
		if(!vis[r]) {
			vis[r] = true;
			vvv.PB(mn[r].S);
		}
	}
	cout << vvv.size() << endl;
	for(int e:vvv) cout << e << " ";
	cout << endl;
	cout << eee.size() << endl;
	for(pi p:eee) cout << p.F << " " << p.S << endl;

}