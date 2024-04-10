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
// #define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1e5 + 7;

int t[4*N], tt[4*N], lazy[4*N], a[N], k[N], buf[N], n;
bool is_lz[4*N];

void push(int v, int tl, int tr) {
	if(is_lz[v]) {
		int tm = (tl + tr) / 2;
		lazy[v*2] = tt[v*2] = lazy[v];
		t[v*2] = lazy[v*2] * (tm - tl + 1);
		lazy[v*2+1] = tt[v*2+1] = lazy[v];
		t[v*2+1] = lazy[v*2+1] * (tr - tm);
		is_lz[v*2] = is_lz[v*2+1] = true;
		is_lz[v] = false;
	}
}

void bld(int v=1, int tl=1, int tr=n) { // [1, n]
	if(tl == tr) {
		t[v] = tt[v] = buf[tl];
	} else {
		int tm = (tl + tr) / 2;
		bld(v*2, tl, tm);
		bld(v*2+1, tm+1, tr);
		t[v] = t[v*2] + t[v*2+1];
		tt[v] = max(tt[v*2], tt[v*2+1]);
	}
}


void upd(int l, int r, int add, int v = 1, int tl = 1, int tr = n) {
	if(l > r) return;
	if(l == tl && r == tr) {
		t[v] = add * (tr - tl + 1);
		tt[v] = add;
		lazy[v] = add;
		is_lz[v] = true;
		return;
	}
	push(v, tl, tr);
	int tm = (tl + tr) / 2;
	upd(l, min(r, tm), add, v*2, tl, tm);
	upd(max(l, tm+1), r, add, v*2+1, tm+1, tr);
	t[v] = t[v*2] + t[v*2+1];
	tt[v] = max(tt[v*2], tt[v*2+1]);
}

int qry(int l, int r, int v = 1, int tl = 1, int tr = n) {
	if(l > r) return 0;
	if(l == tl && r == tr) return t[v];
	push(v, tl, tr);
	int tm = (tl + tr) / 2;
	return qry(l, min(r, tm), v*2, tl, tm)+ qry(max(l, tm+1), r, v*2+1, tm+1, tr);
}

int bs(int val, int v = 1, int tl = 1, int tr = n) { // upper bound
	if(tl == tr) {
		if(tt[v] > val) return tl;
		else return tl + 1;
	}
	push(v, tl, tr);
	int tm = (tl + tr) / 2;
	if(tt[v*2] > val) return bs(val, v*2, tl, tm);
	else return bs(val, v*2+1, tm+1, tr);
}

signed main()
{
	IO_OP;
	
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	k[1] = a[1];
	for(int i=2;i<=n;i++) cin >> k[i];
	for(int i=1;i<=n;i++) buf[i] = a[i] - a[i-1] - k[i];
	for(int i=1;i<=n;i++) buf[i] += buf[i-1];
	bld();
	for(int i=1;i<=n;i++) k[i] += k[i-1];
	for(int i=1;i<=n;i++) k[i] += k[i-1];
	int q;
	cin >> q;
	while(q--) {
		char op;
		cin >> op;
		if(op =='+') {
			int i, x;
			cin >> i >> x;
			int j = bs(qry(i, i) + x) - 1;
			upd(i, j, qry(i, i) + x);
		} else {
			int l, r;
			cin >> l >> r;
			cout << k[r] - k[l-1] + qry(l, r) << endl;
		}
	}
	
}