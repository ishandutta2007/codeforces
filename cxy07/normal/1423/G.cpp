//Code By CXY07 - It's My Fiesta.
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define popc(x) __builtin_popcount(x)
#define inv(x) qpow((x), mod - 2)
#define lowbit(x) ((x) & (-(x)))
#define ull unsigned long long
#define pii pair<int, int>
#define LL long long
#define mp make_pair
#define pb push_back
#define scd second
#define vec vector
#define fst first
#define endl '\n'
#define y1 _y1

const int MAXN = 1e5 + 10;
const int SIZ = (1 << 18) + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct SGT {
	int s[SIZ], g[SIZ], L[SIZ], R[SIZ], M = 1;
	void Init(int n) {
		++n; while(M < n) M <<= 1;
		for(int i = M; i < (M << 1); ++i) L[i] = R[i] = i - M;
		for(int i = M - 1; i >= 1; --i) L[i] = L[i << 1], R[i] = R[i << 1 | 1];
	}
	void add(int l, int r, int a, int b) {
		for(int _l = l + M - 1, _r = r + M + 1; _l ^ _r ^ 1; _l >>= 1, _r >>= 1) {
			if((~_l) & 1) s[_l ^ 1] += a + b * (L[_l ^ 1] - l), g[_l ^ 1] += b;
			if(_r & 1) s[_r ^ 1] += a + b * (L[_r ^ 1] - l), g[_r ^ 1] += b;
		}
	}
	int query(int x) {
		int cur = x + M; int res = 0;
		while(cur) { res += s[cur] + g[cur] * (x - L[cur]); cur >>= 1; }
		return res;
	}
} T;

struct NODE {
	int l, r, c;
	NODE(int _l = 0, int _r = 0, int _c = 0) : l(_l), r(_r), c(_c) {}
	bool operator < (const NODE &b) const { return l < b.l; }
};

int n, m, Ans;
int a[MAXN], b[MAXN], pre[MAXN];
set<NODE> S, sc[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void update_node(int i, int p, int o) {
	int L = i - p, R = n - i + 1;
	if(L <= R) {
		T.add(L, R, (i - p) * o, 0);
		T.add(1, L - 1, o, o);
		T.add(R + 1, n - p, (n - R - p) * o, -o);
	} else {
		T.add(R, L, (n - i + 1) * o, 0);
		T.add(1, R - 1, o, o);
		T.add(L + 1, n - p, (n - L - p) * o, -o);
	}
}

void update_range(int l, int r, int o) {
	if(l > r) return;
	int len = r - l + 1;
	T.add(1, n - r, len * o, 0);
	T.add(n - r + 1, n - l + 1, len * o, -o);
}

void update(NODE v, int o) {
	int c = v.c, p; 
	p = prev(sc[c].lower_bound(NODE(v.l, 0, 0)))->r;
	update_node(v.l, p, o); update_range(v.l + 1, v.r, o);
}

void Insert(NODE v) { 
	int c = v.c;
	auto it = sc[c].upper_bound(NODE(v.l, 0, 0));
	if(it != sc[c].end()) update(*it, -1);
	update(v, 1); sc[c].insert(v);
	it = sc[c].upper_bound(NODE(v.l, 0, 0));
	if(it != sc[c].end()) update(*it, 1);
}

void Erase(NODE v) {
	int c = v.c; 
	auto it = sc[c].upper_bound(NODE(v.l, 0, 0));
	if(it != sc[c].end()) update(*it, -1);
	update(v, -1); sc[c].erase(v);
	it = sc[c].upper_bound(NODE(v.l, 0, 0));
	if(it != sc[c].end()) update(*it, 1);
}

set<NODE>::iterator split(int p) { // [L, p), [p, R]
	if(p > n) return S.end();
	auto it = S.upper_bound(NODE(p, 0, 0));
	it = prev(it); 
	int L = it->l, R = it->r, c = it->c;
	if(L == p) return it;
	S.erase(it); sc[c].erase(NODE(L, R, c));
	sc[c].insert(NODE(L, p - 1, c));
	sc[c].insert(NODE(p, R, c));
	S.insert(NODE(L, p - 1, c));
	return S.insert(NODE(p, R, c)).fst;
}

void solve() {
	int o, l, r, x; read(o);
	if(o == 1) {
		read(l), read(r), read(x);
		auto itR = split(r + 1); auto itL = split(l);
		for(auto it = itL; it != itR; ++it) Erase(*it);
		S.erase(itL, itR);
		Insert(NODE(l, r, x)); S.insert(NODE(l, r, x));
	} else { read(x); printf("%lld\n", T.query(x)); }
}

signed main () {
#ifdef FILE
	freopen("GT.in", "r", stdin);
	freopen("GT.out", "w", stdout);
#endif
	read(n), read(m); T.Init(n);
	for(int i = 1; i <= n; ++i) read(a[i]);
	for(int i = 0; i <= (int)1e5; ++i) sc[i].insert(NODE(0, 0, i));
	for(int L = 1, R; L <= n; L = R + 1) {
		R = L;
		while(R < n && a[R + 1] == a[L]) ++R;
		Insert(NODE(L, R, a[L]));
		S.insert(NODE(L, R, a[L]));
	}
	while(m--) solve();
	return 0;
}