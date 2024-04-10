//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
#define file(FILENAME) freopen(FILENAME".in", "r", stdin), freopen(FILENAME".out", "w", stdout)
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define LINE() cout << "LINE = " << __LINE__ << endl
#define debug(x) cout << #x << " = " << x << endl
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

const int MAXN = 4e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m, cnt, rt, head;
int pos[MAXN], nxt[MAXN], fac[MAXN], ifac[MAXN];
int rnk[MAXN], tag[MAXN], siz[MAXN], ls[MAXN], rs[MAXN], val[MAXN];
bool eq[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

int qpow(int x, int b) {
	int res = 1;
	for(; b; b >>= 1, (x *= x) %= mod) if(b & 1) (res *= x) %= mod;
	return res;
}

int New(int x) {
	rnk[++cnt] = rand();
	val[cnt] = x; ls[cnt] = rs[cnt] = tag[cnt] = 0;
	return cnt;
}

void push(int x, int v) {
	if(x) tag[x] += v, val[x] += v;
}

void pushdown(int x) {
	push(ls[x], tag[x]), push(rs[x], tag[x]); tag[x] = 0;
}

void split(int x, int &a, int &b, int v) {
	if(!x) return (a = b = 0), void();
	pushdown(x);
	if(val[x] <= v) {
		a = x;
		split(rs[x], rs[a], b, v);
	} else {
		b = x;
		split(ls[x], a, ls[b], v);
	}
}

int merge(int &x, int a, int b) {
	if(!a || !b) return x = a | b;
	pushdown(a), pushdown(b);
	if(rnk[a] < rnk[b]) {
		x = a;
		merge(rs[x], rs[a], b);
	} else {
		x = b;
		merge(ls[x], a, ls[b]);
	}
	return x;
}

bool find(int rt, int a) {
	while(rt) {
		pushdown(rt);
		if(val[rt] == a) return true;
		if(val[rt] < a) rt = rs[rt];
		else rt = ls[rt];
	}
	return false;
}

int C(int a, int b) {
	if(a < b || b < 0) return 0;
	return fac[a] * ifac[b] % mod * ifac[a - b] % mod;
}

void solve() {
	read(n), read(m); cnt = rt = 0;
	for(int i = 1, x, a, b; i <= m; ++i) {
		read(x), read(pos[x]);
		bool o = find(rt, pos[x]);
		split(rt, a, b, pos[x] - 1);
		if(b) push(b, 1);
		if(!o) merge(rt, merge(a, a, New(pos[x] + 1)), b);
		else merge(rt, a, b);
	}
	cnt = n - cnt;
	printf("%lld\n", C(n + cnt - 1, cnt - 1));
}

signed main () {
#ifdef FILE
	freopen("f.in", "r", stdin);
	freopen("f.out", "w", stdout);
#endif
	srand(time(0));
	read(T); fac[0] = ifac[0] = 1;
	for(int i = 1; i < MAXN; ++i) fac[i] = fac[i - 1] * i % mod;
	ifac[MAXN - 1] = inv(fac[MAXN - 1]);
	for(int i = MAXN - 2; i; --i) ifac[i] = ifac[i + 1] * (i + 1) % mod;
	while(T--) solve();
	return 0;
}