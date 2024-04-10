#include <bits/stdc++.h> 
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
//#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

void DBG() { cerr << "]" << endl; }
template<class H, class... T>
void DBG(H h, T... t) {
	cerr << to_string(h);
	if(sizeof...(t)) cerr << ", ";
	DBG(t...);
}

#define debug(...) cerr <<"Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)

const int INF = 1e9 + 7, N = 2e5 + 7;

struct node {
	ll sum;
	int mn, lz, islz;
	node(int val = 0) {
		sum = val;
		mn = val;
		islz = lz = 0;
	}
} t[N * 4];

int a[N], n, q;

void pull(int v) {
	t[v].sum = t[v * 2].sum + t[v * 2 + 1].sum;
	t[v].mn = min(t[v * 2].mn, t[v * 2 + 1].mn);
}

void apply(int v, int val, int tl, int tr) {
	t[v].islz = 1;
	t[v].lz = t[v].mn = val;
	t[v].sum = (ll) val * (tr - tl); 
}

void push(int v, int tl, int tr) {
	if(t[v].islz) {
		int tm = (tl + tr) / 2;
		apply(v * 2, t[v].lz, tl, tm);
		apply(v * 2 + 1, t[v].lz, tm, tr);
		t[v].islz = 0;
	}
}


void build(int v = 1, int tl = 0, int tr = n + 1) {
	if(tr - tl == 1) {
		t[v] = node(a[tl]);
	} else {
		int tm = (tl + tr) / 2;
		build(v * 2, tl, tm);
		build(v * 2 + 1, tm, tr);
		pull(v);
	}
}

int find_first_less(int val, int v = 1, int tl = 0, int tr = n + 1) {
	if(tr - tl == 1) {
		assert(t[v].mn < val);
		return tl;
	}
	push(v, tl, tr);
	int tm = (tl + tr) / 2;
	if(t[v * 2].mn < val) return find_first_less(val, v * 2, tl, tm);
	else return find_first_less(val, v * 2 + 1, tm, tr);
}

void upd(int l, int r, int val, int v = 1, int tl = 0, int tr = n + 1) {
	if(l <= tl && tr <= r) {
		apply(v, val, tl, tr);
	} else {
		push(v, tl, tr);
		int tm = (tl + tr) / 2;
		if(l < tm) upd(l, r, val, v * 2, tl, tm);
		if(r > tm) upd(l, r, val, v * 2 + 1, tm, tr);
		pull(v);
	}
}

void go_right(int l, int r, int& sum, int& cnt, int v = 1, int tl = 0, int tr = n + 1) {
	if(t[v].mn > sum) return;
	if(l <= tl && tr <= r && t[v].sum <= sum) {
		sum -= t[v].sum;
		cnt += tr - tl;
//		debug(tl, tr);
		return;
	}
	push(v, tl, tr);
	int tm = (tl + tr) / 2;
	if(l < tm) go_right(l, r, sum, cnt, v * 2, tl, tm);
	if(r > tm) go_right(l, r, sum, cnt, v * 2 + 1, tm, tr);
}

signed main()
{
	IO_OP;
	
	cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> a[i];
	build();
	while(q--) {
		int t, x, y;
		cin >> t >> x >> y;
		x--;
		if(t == 1) {
			int first = find_first_less(y);
			if(first <= x) upd(first, x + 1, y);
		} else {
			int cnt = 0;
			go_right(x, n, y, cnt);
			cout << cnt << '\n';
		}
	}

}