//Code By CXY07 - It's My Fiesta.
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
#define file(FILENAME) freopen(FILENAME".in", "r", stdin), freopen(FILENAME".out", "w", stdout)
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define LINE() cout << "LINE = " << __LINE__ << endl
#define debug(x) cout << #x << " = " << x << endl
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define popc(x) __builtin_popcount(x)
#define min(a, b) (a < b ? a : b)
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

const int MAXN = (1 << 18) + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct SGT {
	int M = 1, mn[MAXN << 1];
	void update(int p, int v) {
		p += M; mn[p] = v;
		while(p > 1) { p >>= 1; mn[p] = min(mn[p << 1], mn[p << 1 | 1]); }
	}
	int query(int l, int r) {
		int res = INF;
		for(l = l + M - 1, r = r + M + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
			if(r & 1) res = min(res, mn[r ^ 1]);
			if((~l) & 1) res = min(res, mn[l ^ 1]);
		}
		return res;
	}
	void build(int n) {
		while(M <= (n + 1)) M <<= 1;
		for(int i = 0; i <= M + n + 1; ++i) mn[i] = INF;
	}
} T1, T2;

int T, n, m;
int a[MAXN];
int stk[MAXN], top, f[MAXN];
int stk2[MAXN], top2;
int lmx[MAXN], rmx[MAXN], lmn[MAXN], rmn[MAXN];
vec<int> vmx[MAXN], vmn[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	a *= f; return 1;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void solve() {
	read(n); T1.build(n), T2.build(n);
	for(int i = 1; i <= n; ++i) {
		read(a[i]), f[i] = INF;
		vmx[i].clear(), vmn[i].clear();
	}
	stk[0] = stk2[0] = 0; top = top2 = 0;
	for(int i = 1; i <= n; ++i) {
		while(top && a[stk[top]] < a[i]) --top;
		lmx[i] = stk[top]; stk[++top] = i;
		while(top2 && a[stk2[top2]] > a[i]) --top2;
		lmn[i] = stk2[top2]; stk2[++top2] = i;
	}
	stk[0] = stk2[0] = n + 1; top = top2 = 0;
	for(int i = n; i >= 1; --i) {
		while(top && a[stk[top]] < a[i]) --top;
		rmx[i] = stk[top]; stk[++top] = i;
		while(top2 && a[stk2[top2]] > a[i]) --top2;
		rmn[i] = stk2[top2]; stk2[++top2] = i;
	}
	f[1] = 0;
	T1.update(1, 0), T2.update(1, 0);
	vmx[rmx[1]].pb(1), vmn[rmn[1]].pb(1);
	for(int i = 2; i <= n; ++i) {
		for(auto p : vmx[i]) T1.update(p, INF);
		for(auto p : vmn[i]) T2.update(p, INF);
		vmx[i].clear(), vmn[i].clear();
		f[i] = min(T1.query(lmn[i] + 1, i), T2.query(lmx[i] + 1, i)) + 1;
		T1.update(i, f[i]), T2.update(i, f[i]);
		vmx[rmx[i]].pb(i), vmn[rmn[i]].pb(i);
	}
	printf("%d\n", f[n]);
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(T);
	while(T--) solve();
	return 0;
}