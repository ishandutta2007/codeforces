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

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7;

/*
    NOTE: remember to call build function
*/
const int N = 1e5 + 7;

int n, q;

struct T {
	ll mx, mn;
	T(ll _val = 0) {
		mx = mn = _val;
	}
};

V<ll> aux;

T t[N * 4];

inline void pull(int v) {
	t[v].mx = max(t[v * 2].mx, t[v * 2 + 1].mx);
	t[v].mn = min(t[v * 2].mn, t[v * 2 + 1].mn);
}

void build(int v = 1, int tl = 1, int tr = n + 1) {
	if(tr - tl == 1) {
		t[v] = T(aux[tl]); // set one
		return;
	}
	int tm = (tl + tr) / 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm, tr);
	pull(v);
}

ll qry_mn(int l, int r, int v = 1, int tl = 1, int tr = n + 1) {
	if(tl >= l && tr <= r) return t[v].mn;
	int tm = (tl + tr) / 2;
	if(r <= tm) return qry_mn(l, r, v * 2, tl, tm);
	else if(l >= tm) return qry_mn(l, r, v * 2 + 1, tm, tr);
	else return min(qry_mn(l, r, v * 2, tl, tm), qry_mn(l, r, v * 2 + 1, tm, tr));
}

ll qry_mx(int l, int r, int v = 1, int tl = 1, int tr = n + 1) {
	if(tl >= l && tr <= r) return t[v].mx;
	int tm = (tl + tr) / 2;
	if(r <= tm) return qry_mx(l, r, v * 2, tl, tm);
	else if(l >= tm) return qry_mx(l, r, v * 2 + 1, tm, tr);
	else return max(qry_mx(l, r, v * 2, tl, tm), qry_mx(l, r, v * 2 + 1, tm, tr));
}

signed main()
{
	IO_OP;

	cin >> n >> q;
	aux = V<ll> (n + 1);
	for(int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		aux[i] -= a;
	}
	for(int i = 1; i <= n; i++) {
		int b;
		cin >> b;
		aux[i] += b;
		aux[i] += aux[i - 1];
	}
	build();
	while(q--) {
		int l, r;
		cin >> l >> r;
		if(aux[r] != aux[l - 1]) {
			cout << -1 << '\n';
			continue;
		}
		ll mn = qry_mn(l, r + 1) - aux[l - 1];
		if(mn < 0) {
			cout << -1 << '\n';
			continue;
		}
		cout << qry_mx(l, r + 1) - aux[l - 1] << '\n';
	}

}