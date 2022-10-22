//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
#define file(FILENAME) freopen(FILENAME".in", "r", stdin), freopen(FILENAME".out", "w", stdout)
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define LINE() cout << "LINE = " << __LINE__ << endl
#define debug(x) cout << #x << " = " << x << endl
#define abs(x) ((x) < 0 ? (-(x)) : (x))
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

const int MAXN = 5e5 + 10;
const int MAXK = 55;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct option {
	int x, y, c;
	option(int _x = 0, int _y = 0, int _c = 0) : x(_x), y(_y), c(_c) {}
};

int n, m, k, q;
int X[MAXN], Y[MAXN], T[MAXN], E[MAXN], C[MAXN], nxt[MAXN];
int now[MAXN];
vec<option> opt[MAXN << 2];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

struct DSU {
	int f[MAXN << 1], siz[MAXN << 1];
	vec<pair<int*, int>> stk;
	void init() {for(int i = 1; i <= (n << 1); ++i) f[i] = i, siz[i] = 1;}
	int find(int x) {
		if(f[x] == x) return x;
		return find(f[x]);
	}
	void make(int &x, int y) {
		stk.pb(mp(&x, x));
		x = y;
	}
	void unity(int x, int y) {
		x = find(x), y = find(y);
		if(x == y) return;
		if(siz[x] < siz[y]) swap(x, y);
		make(f[y], x), make(siz[x], siz[x] + siz[y]);
	}
	void roll(int top = 0) {
		while(stk.size() > top) {
			*(stk.back().fst) = stk.back().scd;
			stk.pop_back();
		}
	}
	bool chk(int x, int y) {
		int a = find(x), b = find(y), na = find(x + n), nb = find(y + n);
		if(a == b || na == nb) return false;
		return true;
	}
} S[MAXK];

void Add(int x, int l, int r, int L, int R, option v) {
	if(L > R) return;
	if(L <= l && r <= R) return opt[x].pb(v), void();
	int mid = (l + r) >> 1;
	if(L <= mid) Add(x << 1, l, mid, L, R, v);
	if(R > mid) Add(x << 1 | 1, mid + 1, r, L, R, v);
}

void Query(int x, int l, int r) {
	int sav[55];
	for(int i = 1; i <= k; ++i) sav[i] = S[i].stk.size();
	for(auto t : opt[x])
		S[t.c].unity(t.x, t.y + n), S[t.c].unity(t.x + n, t.y);
	if(l == r) {
		int e = E[l], c = C[l];
		if(S[c].chk(X[e], Y[e])) {
			puts("YES"); now[e] = c;
			Add(1, 1, q, l + 1, nxt[l] - 1, option(X[e], Y[e], now[e]));
		} else {
			puts("NO");
			if(now[e]) Add(1, 1, q, l + 1, nxt[l] - 1, option(X[e], Y[e], now[e]));
		}
		for(int i = 1; i <= k; ++i) S[i].roll(sav[i]);
		return;
	}
	int mid = (l + r) >> 1;
	Query(x << 1, l, mid); Query(x << 1 | 1, mid + 1, r);
	for(int i = 1; i <= k; ++i) S[i].roll(sav[i]);
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(m), read(k), read(q);
	for(int i = 1; i <= m; ++i) read(X[i]), read(Y[i]);
	for(int i = 1; i <= k; ++i) S[i].init();
	for(int i = 1, e, c; i <= q; ++i) {
		read(e), read(c); E[i] = e, C[i] = c;
		if(T[e]) nxt[T[e]] = i;
		T[e] = i;
	}
	for(int i = 1; i <= m; ++i)
		if(T[i]) nxt[T[i]] = q + 1;
	Query(1, 1, q);
	return 0;
}