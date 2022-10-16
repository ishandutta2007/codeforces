#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'
#define debug(x) cerr << #x << " is " << x << endl
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

pair<int, pi> e[200005];
pi q[200005];
int ans[200005], n, m;

int p[200005], sz[200005];
void init() {
	for(int i=1;i<=n;i++)
		p[i] = i, sz[i] = 1;
}

int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}
void unite(int x, int y) {
	int rx = find(x), ry = find(y);
	if(rx == ry) return;
	if(sz[rx] < sz[ry]) swap(rx, ry);
	p[ry] = rx;
	sz[rx] += sz[ry];
}

int32_t main()
{
	IO_OP;
	
	cin >> n >> m;
	for(int i=0;i<n-1;i++)
		cin >> e[i].S.F >> e[i].S.S >> e[i].F;
	sort(e, e+n-1);
	for(int i=0;i<m;i++) {
		cin >> q[i].F;
		q[i].S = i;
	}
	sort(q, q+m);
	int sm = 0;
	init();
	for(int i=0, j=0;i<m;i++) {
		int k = q[i].S, qq = q[i].F;
		while(j < n-1 && e[j].F <= qq) {
			int u = e[j].S.F, v = e[j].S.S;
			sm += sz[find(u)] * sz[find(v)];
			unite(u, v);
			j++;
		}
		ans[k] = sm;
	}
	for(int i=0;i<m;i++)
		cout << ans[i] << " ";
}