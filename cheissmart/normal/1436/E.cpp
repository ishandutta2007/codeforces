#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1e5 + 7;

vi pos[N];
V<pi> qq[N];
int a[N], ok[N];

/*
    NOTE: remember to call build function
*/
int n;

struct T {
	int val;
	T(int _val = 0) {
		val = _val;
	}
};

T t[N * 4];

inline T add(T x, T y) {
	return T(max(x.val, y.val));
}

inline void pull(int v) {
	t[v] = add(t[v * 2], t[v * 2 + 1]);
}

void build(int v = 1, int tl = 1, int tr = n + 1) {
	if(tr - tl == 1) {
		t[v] = T(INF); // set one
		return;
	}
	int tm = (tl + tr) / 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm, tr);
	pull(v);
}

T qry(int l, int r, int v = 1, int tl = 1, int tr = n + 1) {
	if(tl >= l && tr <= r) return t[v];
	int tm = (tl + tr) / 2;
	if(r <= tm) return qry(l, r, v * 2, tl, tm);
	else if(l >= tm) return qry(l, r, v * 2 + 1, tm, tr);
	else return add(qry(l, r, v * 2, tl, tm), qry(l, r, v * 2 + 1, tm, tr));
}

void upd(int pos, T val, int v = 1, int tl = 1, int tr = n + 1) {
	if(tr - tl == 1) {
		t[v] = val; // change one
		return;
	}
	int tm = (tl + tr) / 2;
	if(pos < tm) upd(pos, val, v * 2, tl, tm);
	else upd(pos, val, v * 2 + 1, tm, tr);
	pull(v);
}

signed main()
{
	IO_OP;

	cin >> n;
	build();
	for(int i = 1; i <= n + 1; i++) pos[i].PB(-1);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		pos[a[i]].PB(i);
		if(a[i] != 1) ok[1] = 1;
	}
	for(int i = 1; i <= n + 1; i++) pos[i].PB(n);
	for(int i = 2; i <= n + 1; i++) {
		for(int j = 0; j < pos[i].size() - 1; j++) {
			qq[pos[i][j] + 1].EB(i - 1, pos[i][j + 1] - 1);
		}
	}
	for(int i = n - 1; i >= 0; i--) {
		upd(a[i], i);
		for(pi p:qq[i]) {
			int x = p.F, r = p.S;
			if(qry(1, x + 1).val <= r) ok[x + 1] = 1;
		}
	}
	for(int i = 1; i <= n + 2; i++) {
		if(!ok[i]) {
			cout << i << endl;
			return 0;
		}
	}
	throw;

}