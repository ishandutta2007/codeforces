#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

struct edge{
	ll u, v, w;
	operator<(const edge e){
		return w < e.w;
	}
};

vector<edge> ve;
ll a[200005], pa[200005], h[200005];

void init(int n) {
	for(int i=0;i<n;i++)
		pa[i] = i;
}

int find(int u) {
	if(pa[u] == u) return u;
	return pa[u] = find(pa[u]);
}
void unite(int u, int v) {
	int pu = find(u), pv = find(v);
	if(pu == pv) return;
	if(h[u] > h[v]) {
		pa[pv] = pu;
	} else if(h[u] < h[v]) {
		pa[pu] = pv;
	} else {
		pa[pv] = pu;
		h[pu]++;
	}
}

bool ok(int u, int v) {
	return find(u) == find(v);
}

int main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<m;i++) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		u--, v--;
		ve.PB({u, v, w});
	}
	int mni;
	ll mn = (1LL<<62);
	for(int i=0;i<n;i++)
		if(a[i] < mn)
			mn = a[i], mni = i;
	for(int i=0;i<n;i++)
		if(i != mni)
			ve.PB({mni, i, a[mni]+a[i]});
	sort(ve.begin(), ve.end());
	init(n);
	ll ans = 0;
	for(auto e:ve) {
		int u = e.u, v = e.v;
		if(ok(u, v)) continue;
		ans += e.w;
		unite(u, v);
	}
	cout << ans << endl;
}