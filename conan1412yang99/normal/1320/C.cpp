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

const int INF = 1e12 + 7, N = 2e5 + 7;

pi a[N], b[N];
int n, m, p;
struct M{
	int x, y, z;
	bool operator < (const M t) const {
		return x < t.x;
	}
} c[N];

int go(pi *a, int n) {
	V<pi> v;
	for(int i=0;i<n;i++) {
		while(v.size() && a[i].S <= v.back().S) v.pop_back();
		v.PB(a[i]);
	}
	n = v.size();
	for(int i=0;i<n;i++) a[i] = v[i];
	return n;
}

int t[4*N], lazy[4*N];

void bld(int v=1, int tl=0, int tr=m) {
	if(tr - tl == 1) {
		t[v] = -b[tl].S;
	} else {
		int tm = (tl + tr) / 2;
		bld(v*2, tl, tm);
		bld(v*2+1, tm, tr);
		t[v] = max(t[v*2], t[v*2+1]);
	}
}
void push(int v) {
	if(lazy[v]) {
		lazy[v*2] += lazy[v];
		lazy[v*2+1] += lazy[v];
		t[v*2] += lazy[v];
		t[v*2+1] += lazy[v];
		lazy[v] = 0;
	}
}

void upd(int l, int r, int add, int v = 1, int tl = 0, int tr = m) {
	if(l >= r) return;
	if(l == tl && r == tr) {
		t[v] += add;
		lazy[v] += add;
		return;
	}
	push(v);
	int tm = (tl + tr) / 2;
	upd(l, min(r, tm), add, v*2, tl, tm);
	upd(max(l, tm), r, add, v*2+1, tm, tr);
	t[v] = max(t[v*2], t[v*2+1]);
}

int qry(int l, int r, int v = 1, int tl = 0, int tr = m) {
	if(l >= r) return -INF;
	if(l == tl && r == tr) return t[v];
	push(v);
	int tm = (tl + tr) / 2;
	return max(qry(l, min(r, tm), v*2, tl, tm),
		qry(max(l, tm), r, v*2+1, tm, tr));
}

signed main()
{
	IO_OP;
	
	cin >> n >> m >> p;
	for(int i=0;i<n;i++) cin >> a[i].F >> a[i].S;
	for(int i=0;i<m;i++) cin >> b[i].F >> b[i].S;
	for(int i=0;i<p;i++) {
		cin >> c[i].x >> c[i].y >> c[i].z;
	}
	sort(a, a+n);
	sort(b, b+m);
	sort(c, c+p);
	n = go(a, n);
	m = go(b, m);
	bld();
	int j = 0, ans = -INF;
	for(int i=0;i<p;i++) {
		while(j < n && a[j].F <= c[i].x) j++;
		// cout << i << " => " << j << endl;
		if(j == n) {
			ans = max(ans, -a[0].S - b[0].S);
		} else {
			int pay = a[j].S;
			int pos = upper_bound(b, b+m, MP(c[i].y, INF)) - b;
			// debug(pos);
			if(pos < m) {
				upd(pos, m, c[i].z);
			}
			ans = max(ans, qry(0, m) - pay);
			// debug(qry(0, m));		
		}
	}
	cout << ans << endl;
}