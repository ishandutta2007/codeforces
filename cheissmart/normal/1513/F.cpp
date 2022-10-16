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

template<class A, class B> string to_string(pair<A, B> p) {
	string s;
	s += "(", s += to_string(p.F), s += ", ", s += to_string(p.S), s += ")";
	return s;
}

template<class T> string to_string(V<T> t) {
	string s = "{";
	for(int i = 0; i < int(t.size()); i++) {
		if(i) s += ", ";
		s += to_string(t[i]);
	}
	s += "}";
	return s;
}

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

const int INF = 1e9 + 7;
const ll oo = 1e18;

struct seg {
	struct node {
		ll mn;
		node *l, *r;
		node() {
			mn = oo;
			l = r = nullptr;
		}
	};
	void pull(node* t) {
		t -> mn = min(t -> l ? t -> l -> mn : oo, t -> r ? t -> r -> mn : oo);
	}
	node* root;
	seg() {
		root = nullptr;
	}
	void upd(int pos, ll val) {
		upd(root, pos, val);
	} 
	void upd(node* &t, int pos, ll val, int tl = 0, int tr = INF) {
		if(!t) t = new node();
		if(tr - tl == 1) {
			assert(tl == pos);
			t -> mn = min(t -> mn, val);
			return;
		}
		int tm = (tl + tr) / 2;
		if(pos < tm) upd(t -> l, pos, val, tl, tm);
		else upd(t -> r, pos, val, tm, tr);
		pull(t);
	}
	ll qry(int l, int r) {
		return qry(root, l, r);
	}
	ll qry(node* t, int l, int r, int tl = 0, int tr = INF) {
		if(!t) return oo;
		if(l <= tl && tr <= r) return t -> mn;
		int tm = (tl + tr) / 2;
		ll ans = oo;
		if(l < tm) ans = min(ans, qry(t -> l, l, r, tl, tm));
		if(r > tm) ans = min(ans, qry(t -> r, l, r, tm, tr));
		return ans;
	}
};

signed main()
{
	IO_OP;

	ll ans = 0, mn = 0;
	int n; cin >> n;

	vi a(n), b(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];

	V<pi> sa, na;
	for(int i = 0; i < n; i++) {
		ans += abs(a[i] - b[i]);
		if(a[i] < b[i]) sa.EB(a[i], b[i]);
		if(a[i] > b[i]) na.EB(b[i], a[i]);
	}
	debug(ans);
	debug(sa, na);
	sort(ALL(sa)), sort(ALL(na));
	for(int _ = 0;  _ < 2; _++) {
		seg t1, t2;
		for(int i = int(sa.size()) - 1, j = int(na.size()) - 1; i >= 0; i--) {
			int L = sa[i].F, R = sa[i].S;
			while(j >= 0 && na[j].F >= L) {
				int l = na[j].F, r = na[j].S;
				t1.upd(r, 2 * (l - r));
				t2.upd(r, 2 * l);
				j--;
			}
			debug(i, L, R, t1.qry(0, R + 1), -2 * R + t2.qry(R + 1, INF));
			mn = min(mn, t1.qry(0, R + 1));
			mn = min(mn, -2 * R + t2.qry(R + 1, INF));
		}
		swap(sa, na);
	}
	ans += mn;
	cout << ans << '\n';

}