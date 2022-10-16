#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector","unroll-loops")
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

const int M = 1e9 + 7, N = 4e5 + 7;

inline int qpow(ll a,ll b){
	ll ret = 1;
	for(;b;b>>=1,a = a * a % M)
		b & 1 ? ret = ret * a % M : 0;
	return ret;
}

int pf[303], pre[64], a[N], n, q;
vi ps;

struct nd{
	ll has;
	int s;
	nd(int _s = 1) {
		s = _s, has = 0;
		for(int i=0;i<ps.size();i++) if(s % ps[i] == 0) has |= (1LL << i);
	}
	int phi() {
		int ret = s;
		for(int i=0;i<ps.size();i++)
			if(has >> i & 1)
				ret = (ll) ret * pre[i] % M;
		return ret;
	}
} t[4*N], lz[4*N];
bool islz[4*N];

nd add(nd a, nd b) {
	nd c;
	c.s = (ll)a.s * b.s % M;
	c.has = a.has | b.has;
	return c;
}

void bld(int v = 1, int tl = 0, int tr = n) {
	if(tr - tl == 1) {
		t[v] = nd(a[tl]);
		return;
	}
	int tm = (tl + tr) / 2;
	bld(v*2, tl, tm);
	bld(v*2+1, tm, tr);
	t[v] = add(t[v*2], t[v*2+1]);
}

void push(int v, int tl, int tr) {
	if(islz[v]) {
		int tm = (tl + tr) / 2;
		lz[v*2] = add(lz[v*2], lz[v]);
		lz[v*2+1] = add(lz[v*2+1], lz[v]);
		t[v*2].has |= lz[v].has;
		t[v*2+1].has |= lz[v].has;
		t[v*2].s = (ll)t[v*2].s * qpow(lz[v].s, tm - tl) % M;
		t[v*2+1].s = (ll)t[v*2+1].s * qpow(lz[v].s, tr - tm) % M;
		islz[v*2] = islz[v*2+1] = true;
		lz[v] = nd();
		islz[v] = false;
	}
}

nd qry(int l, int r, int v = 1, int tl = 0, int tr = n) {
	if(l >= r) return nd();
	if(l == tl && r == tr)return t[v];
	push(v, tl, tr);
	int tm = (tl + tr) / 2;
	return add(qry(l, min(tm, r), v*2, tl, tm),
			   qry(max(l, tm), r, v*2+1, tm, tr));
}

void upd(int l, int r, int val, int v = 1, int tl = 0, int tr = n) {
	if(l >= r) return;
	if(l == tl && r == tr) {
		nd p1 = nd(val), p2 = p1;
		p2.s = qpow(p2.s, tr - tl);
		t[v] = add(t[v], p2);
		lz[v] = add(lz[v], p1);
		islz[v] = true;
		return;
	}
	push(v, tl, tr);
	int tm = (tl + tr) / 2;
	upd(l, min(tm, r), val, v*2, tl, tm);
	upd(max(l, tm), r, val, v*2+1, tm, tr);
	t[v] = add(t[v*2], t[v*2+1]);
}

signed main()
{
	IO_OP;
	
	for(int i=2;i<303;i++) {
		if(pf[i]) continue;
		pf[i] = i;
		for(int j=i*i;j<303;j+=i)
			pf[j] = i;
	}
	for(int i=2;i<303;i++)
		if(pf[i] == i) ps.PB(i);
	for(int i=0;i<ps.size();i++)
		pre[i] = (ll)(ps[i] - 1) * qpow(ps[i], M - 2) % M;
	cin >> n >> q;
	for(int i=0;i<n;i++) cin >> a[i];
	bld();
	while(q--) {
		string op;
		cin >> op;
		if(op[0] == 'M')  {
			int l, r, x;
			cin >> l >> r >> x;
			l--;
			upd(l, r, x);
		} else {
			int l, r;
			cin >> l >> r;
			l--;
			cout << qry(l, r).phi() << endl;
		}
	}
	
}