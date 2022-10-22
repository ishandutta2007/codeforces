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

const int MAXN = (1 << 19) + 10;
const int INF = 2e16;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct Query {
	int l, r, k;
	Query(int _l = 0, int _r = 0, int _k = 0) : l(_l), r(_r), k(_k) {}
	bool operator < (const Query &b) const { return r < b.r; }
} s[MAXN];

int n, q, M, Ans = -INF;
int a[3][MAXN], f[MAXN], g[MAXN], dp[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

struct zkw {
	int M = 1, mxg[MAXN << 1], mx[MAXN << 1], val[MAXN << 1];
	void pushup(int x) {
		mxg[x] = max(mxg[x << 1], mxg[x << 1 | 1]);
		mx[x] = max(mx[x << 1], mx[x << 1 | 1]);
		val[x] = max(val[x << 1], val[x << 1 | 1]);
		val[x] = max(val[x], mx[x << 1] + mxg[x << 1 | 1]);
	}
	void Init(int o) {
		while(M < n) M <<= 1;
		for(int i = 1; i <= n; ++i) {
			mxg[i + M] = g[i], mx[i + M] = (o ? f[i] : dp[i]);
			val[i + M] = mxg[i + M] + mx[i + M];
		}
		for(int i = M; i >= 1; --i) pushup(i);
	}
	void chkmax(int p, int v) {
		p += M; mx[p] = max(mx[p], v);
		val[p] = mx[p] + mxg[p];
		while(p > 1) pushup(p >>= 1);
	}
	int ask(int l, int r) {
		int res = -INF;
		for(l = l + M - 1, r = r + M + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
			if((~l) & 1) res = max(res, mx[l ^ 1]);
			if(r & 1) res = max(res, mx[r ^ 1]);
		}
		return res;
	}
	int query(int l, int r) {
		static int stk[MAXN], top; top = 0;
		int res = -INF, tmpv = -INF;
		for(l = l + M - 1, r = r + M + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
			if((~l) & 1) {
				res = max(res, val[l ^ 1]); res = max(res, tmpv + mxg[l ^ 1]);
				tmpv = max(tmpv, mx[l ^ 1]);
			}
			if(r & 1) stk[++top] = (r ^ 1);
		}
		while(top) {
			res = max(res, val[stk[top]]); res = max(res, tmpv + mxg[stk[top]]);
			tmpv = max(tmpv, mx[stk[top]]); --top;
		}
		return res;
	}
} T;

signed main () {
#ifdef FILE
	freopen("CF1648D.in", "r", stdin);
	freopen("CF1648D.out", "w", stdout);
#endif
	read(n), read(q);
	for(int i = 0; i < 3; ++i)
		for(int j = 1; j <= n; ++j) 
			read(a[i][j]), a[i][j] += a[i][j - 1];
	for(int i = 1; i <= q; ++i) read(s[i].l), read(s[i].r), read(s[i].k);
	sort(s + 1, s + q + 1); 
	for(int i = 1; i <= n; ++i) {
		f[i] = a[0][i] - a[1][i - 1];
		g[i] = a[1][i] + a[2][n] - a[2][i - 1];
	}
	T.Init(1); memset(dp, -0x3f, sizeof dp);
	for(int i = 1; i <= q; ++i) {
		Ans = max(Ans, T.query(s[i].l, s[i].r) - s[i].k);
		dp[s[i].r] = max(dp[s[i].r], T.ask(s[i].l, s[i].r) - s[i].k);
	}
	T.Init(0);
	for(int i = 1, L, R; i <= q; ++i) {
		L = max(s[i].l - 1, 1ll), R = s[i].r;
		Ans = max(Ans, T.query(L, R) - s[i].k);
		T.chkmax(s[i].r, T.ask(L, R) - s[i].k);
	}
	printf("%lld\n", Ans);
	return 0;
}