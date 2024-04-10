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
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2e5 + 87;

int ct[N], l[N], r[N], p[N], sz[N], mx[N], vis[N];

void init() {
	for(int i=0;i<N;i++) {
		p[i] = i;
		mx[i] = sz[i] = ct[i];
	}
}

int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}

void unite(int x, int y) {
	int rx = find(x), ry = find(y);
	if(rx == ry) return;
	if(sz[rx] > sz[ry]) swap(rx, ry);
	p[rx] = ry;
	sz[ry] += sz[rx];
	mx[ry] = max(mx[ry], mx[rx]);
}

int32_t main()
{
	IO_OP;
	
	int n, q;
	cin >> n >> q;
	memset(l, 0x3f, sizeof l);
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		ct[t]++, l[t] = min(l[t], i), r[t] = max(r[t], i);
	}
	init();
	V<pair<pi, int>> v;
	for(int i=1;i<N;i++) {
		if(ct[i]) {
			v.PB({{l[i], r[i]}, i});
		}
	}
	sort(ALL(v));
	int cr = v[0].F.S;
	for(int i=1;i<v.size();i++) {
		if(v[i].F.F < cr) {
			unite(v[i].S, v[i-1].S);
		}
		cr = max(cr, v[i].F.S);
	}
	int ans = 0;
	for(int i=0;i<N;i++) {
		int r = find(i);
		if(!vis[r]) {
			vis[r] = 1;
			ans += sz[r] - mx[r];
		}
	}
	cout << ans << endl;
}