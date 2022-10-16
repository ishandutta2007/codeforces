#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

void DBG() { cerr << "]" << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7, N = 3e5 + 7;

int a[N], n;

pi t[N * 4];

pi add(pi a, pi b) {
	if(a.F == b.F) {
		a.S += b.S;
		return a;
	}
	if(a.S < b.S) swap(a, b);
	a.S -= b.S;
	return a;
}

void build(int v = 1, int tl = 0, int tr = n) {
	if(tr - tl == 1) {
		t[v] = {a[tl], 1};
		return;
	}
	int tm = (tl + tr) / 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm, tr);
	t[v] = add(t[v * 2], t[v * 2 + 1]);
}

pi qry(int l, int r, int v = 1, int tl = 0, int tr = n) {
	if(l <= tl && tr <= r) return t[v];
	int tm = (tl + tr) / 2;
	if(r <= tm) return qry(l, r, v * 2, tl, tm);
	else if(l >= tm) return qry(l, r, v * 2 + 1, tm, tr);
	else return add(qry(l, r, v * 2, tl, tm), qry(l, r, v * 2 + 1, tm, tr));
}

vi pos[N];

int cnt(int x, int l, int r) {
	return lower_bound(ALL(pos[x]), r) - lower_bound(ALL(pos[x]), l);
}

signed main()
{
	IO_OP;

	int q; cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> a[i], pos[a[i]].PB(i);

	build();

	while(q--) {
		int l, r; cin >> l >> r;
		l--;
		int x = qry(l, r).F;
		int occ = cnt(x, l, r);
		int tot = r - l;
		if(occ <= (tot + 1) / 2) {
			cout << 1 << '\n';
		} else {
			cout << occ - (tot - occ) << '\n';
		}
	}

}