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

const int INF = 1e9 + 7;

const int N = 2e5 + 7;

struct T {
	ll val;
	int lazy, first_occ;
	bool islz;
	T(ll _val = 0) {
		val = _val;
		lazy = 0;
		first_occ = INF;
		islz = false;
	}
};

T t[N * 4];

inline T add(T x, T y) {
	T z;
	z.val = x.val + y.val;
	z.first_occ = min(x.first_occ, y.first_occ);
	return z;
}

inline void pull(int v) {
	t[v] = add(t[v * 2], t[v * 2 + 1]);
}

inline void apply(int v, int val, int tl, int tr) {
	t[v].first_occ = tl;
	if(t[v].islz) {
		t[v].val += (ll) val * (tr - tl);
		t[v].lazy += val;
	} else {
		t[v].val += (ll) val * (tr - tl);
		t[v].lazy = val;
	}
	t[v].islz = true;
}

inline void push(int v, int tl, int tr) {
	int tm = (tl + tr) / 2;
	if(t[v].islz) {
		apply(v * 2, t[v].lazy, tl, tm);
		apply(v * 2 + 1, t[v].lazy, tm, tr);
		t[v].islz = false;
		t[v].lazy = 0;
	}
}

void upd(int l, int r, int val, int v = 1, int tl = 0, int tr = N - 1) {
	if(l <= tl && tr <= r) {
		if(val == 1) {
			apply(v, val, tl, tr);
		}
		else {
			assert(tr - tl == 1);
			t[v].val--;
			if(t[v].val == 0) t[v].first_occ = INF;
		}
		return;
	}
	push(v, tl, tr);
	int tm = (tl + tr) / 2;
	if(l < tm) upd(l, r, val, v * 2, tl, tm);
	if(r > tm) upd(l, r, val, v * 2 + 1, tm, tr);
	pull(v);
}

int get_kth(int k, int v = 1, int tl = 0, int tr = N - 1) {
	if(tr - tl == 1)
		return tl;
	int tm = (tl + tr) / 2;
	push(v, tl, tr);
	if(t[v * 2].val >= k) return get_kth(k, v * 2, tl, tm);
	else return get_kth(k - t[v * 2].val, v * 2 + 1, tm, tr);
}

signed main()
{
	IO_OP;

	int n, k;
	ll mx = 1;
	cin >> n >> k;
	vi l(n);
	for(int i = 0; i < n; i++) {
		cin >> l[i];
		mx = mx + l[i] - 2;
	}
	sort(ALL(l), greater<int>());
	if(mx < k) {
		cout << -1 << endl;
		return 0;
	}
	int ans = INF;
	ll cnt = 1;
	upd(0, 1, 1);
	for(int len:l) {
		int who = t[1].first_occ;
		upd(who, who + 1, -1);
		int x = (len - 1) / 2, y = len - 1 - x;
		upd(who + 2, who + 2 + x, 1);
		upd(who + 2, who + 2 + y, 1);
		cnt = cnt + len - 2;
		if(cnt >= k) ans = min(ans, get_kth(k));
	}
	cout << ans << endl;
}