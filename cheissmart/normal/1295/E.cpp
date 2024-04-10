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

const int INF = 1e18 + 7, N = 200005;

int t[4*N], lazy[4*N], a[N], n;

void bld(int v=1, int tl=0, int tr=n) { // [1, n]
	if(tl == tr) {
		t[v] = a[tl];
	} else {
		int tm = (tl + tr) / 2;
		bld(v*2, tl, tm);
		bld(v*2+1, tm+1, tr);
		t[v] = min(t[v*2], t[v*2+1]);
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

void upd(int l, int r, int add, int v = 1, int tl = 0, int tr = n) {
	if(l > r) return;
	if(l == tl && r == tr) {
		t[v] += add;
		lazy[v] += add;
		return;
	}
	push(v);
	int tm = (tl + tr) / 2;
	upd(l, min(r, tm), add, v*2, tl, tm);
	upd(max(l, tm+1), r, add, v*2+1, tm+1, tr);
	t[v] = min(t[v*2], t[v*2+1]);
}

int qry(int l, int r, int v = 1, int tl = 0, int tr = n) {
	if(l > r) return -INF;
	if(l == tl && r == tr) return t[v];
	push(v);
	int tm = (tl + tr) / 2;
	return min(qry(l, min(r, tm), v*2, tl, tm),
		qry(max(l, tm+1), r, v*2+1, tm+1, tr));
}


int p[N], cc[N], c[N];

void myupd(int x) {
	upd(0, x - 1, c[x]);
	upd(x, n, -c[x]);
}

signed main()
{
	IO_OP;
	
	cin >> n;
	for(int i=1;i<=n;i++) cin >> p[i];
	for(int i=1;i<=n;i++) cin >> cc[i];
	for(int i=1;i<=n;i++) c[p[i]] = cc[i];
	
	int cur = 0;
	for(int i=0;i<=n;i++){
		cur += c[i];
		a[i] = cur;
	}
	bld();

	int ans = INF;
	for(int i=1;i<n;i++) {
		myupd(p[i]);
		ans = min(ans, qry(0, n));
	}

	cout << ans << endl;

}