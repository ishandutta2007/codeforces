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

const int INF = 1e9 + 7, N = 5e5 + 7;

int n, q;
string s;

struct node {
	int ans, lans, rans, ltype, rtype, len;
	node() {
		ans = lans = rans = ltype = rtype = len = 0;
	}
	node(int type) {
		ltype = rtype = type;
		ans = lans = rans = len = 1;
	}
} a[N * 4], b[N * 4];

bool lz[N * 4];

node operator + (const node a, const node b) {
	if(a.len == 0) return b;
	if(b.len == 0) return a;
	node ret;
	ret.len = a.len + b.len;
	ret.ltype = a.ltype, ret.rtype = b.rtype;
	ret.ans = max(a.ans, b.ans);
	ret.lans = a.lans, ret.rans = b.rans;
	if(!(a.rtype == 0 && b.ltype == 1)) {
		ret.ans = max(ret.ans, a.rans + b.lans);
		if(a.lans == a.len) ret.lans = a.lans + b.lans;
		if(b.rans == b.len) ret.rans = a.rans + b.rans;
	}
	return ret;
}

void apply(int v) {
	lz[v] ^= 1;
	swap(a[v], b[v]);
}

void push(int v) {
	if(lz[v]) {
		apply(v * 2);
		apply(v * 2 + 1);
		lz[v] = 0;
	}
}

void bld(int v = 1, int tl = 0, int tr = n) {
	if(tr - tl == 1) {
		if(s[tl] == '<') a[v] = node(0), b[v] = node(1);
		else a[v] = node(1), b[v] = node(0);
		return;
	}
	int tm = (tl + tr) / 2;
	bld(v * 2, tl, tm);
	bld(v * 2 + 1, tm, tr);
	a[v] = a[v * 2] + a[v * 2 + 1];
	b[v] = b[v * 2] + b[v * 2 + 1];
}

void upd(int l, int r, int v = 1, int tl = 0, int tr = n) {
	if(l >= r) return;
	if(l == tl && r == tr) {
		apply(v);
		return;
	}
	push(v);
	int tm = (tl + tr) / 2;
	upd(l, min(tm, r), v * 2, tl, tm);
	upd(max(tm, l), r, v * 2 + 1, tm, tr);
	a[v] = a[v * 2] + a[v * 2 + 1];
	b[v] = b[v * 2] + b[v * 2 + 1];
}


node qry(int l, int r, int v = 1, int tl = 0, int tr = n) {
	if(l >= r) return node();
	if(l == tl && r == tr) return a[v];
	push(v);
	int tm = (tl + tr) / 2;
	return qry(l, min(r, tm), v * 2, tl, tm) + qry(max(l, tm), r, v * 2 + 1, tm, tr);
}

signed main()
{
	IO_OP;
	
	cin >> n >> q >> s;
	bld();
	while(q--) {
		int l, r;
		cin >> l >> r;
		l--;
		upd(l, r);
		cout << qry(l, r).ans << endl;
	}	
	
}