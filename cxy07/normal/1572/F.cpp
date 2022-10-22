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

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, q;
int mx[MAXN << 2], smx[MAXN << 2], cnt[MAXN << 2], tag[MAXN << 2];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

struct FT {
	int a[MAXN], b[MAXN];
	void _add(int x, int v) {
		for(int i = x; i <= n; i += lowbit(i)) a[i] += v, b[i] += x * v;
	}
	int _ask(int x) {
		int A = 0, B = 0;
		for(int i = x; i; i -= lowbit(i)) A += a[i], B += b[i];
		return A * (x + 1) - B;
	}
	void add(int l, int r, int v) { _add(l, v), _add(r + 1, -v); }
	int ask(int l, int r) { return _ask(r) - _ask(l - 1); }
} F;

void pushup(int x) {
	cnt[x] = 0, mx[x] = max(mx[x << 1], mx[x << 1 | 1]), smx[x] = -1;
	if(mx[x << 1] == mx[x]) cnt[x] += cnt[x << 1], smx[x] = max(smx[x], smx[x << 1]);
	else smx[x] = max(smx[x], mx[x << 1]);
	if(mx[x << 1 | 1] == mx[x]) cnt[x] += cnt[x << 1 | 1], smx[x] = max(smx[x], smx[x << 1 | 1]);
	else smx[x] = max(smx[x], mx[x << 1 | 1]);
}

void build(int x, int l, int r) {
	tag[x] = -1;
	if(l == r) return mx[x] = l, smx[x] = -1, cnt[x] = 1, void();
	int mid = (l + r) >> 1;
	build(x << 1, l, mid), build(x << 1 | 1, mid + 1, r);
	pushup(x);
}

void push(int x, int v) { if(mx[x] > v) tag[x] = mx[x] = v; }

void pushdown(int x) {
	if(tag[x] == -1) return;
	push(x << 1, tag[x]), push(x << 1 | 1, tag[x]); tag[x] = -1;
}

void chkmin(int x, int l, int r, int L, int R, int v) {
	if(L > R || mx[x] <= v) return;
	if(L <= l && r <= R && v > smx[x])
		return F.add(v + 1, mx[x], -cnt[x]), push(x, v), void();
	int mid = (l + r) >> 1; pushdown(x);
	if(L <= mid) chkmin(x << 1, l, mid, L, R, v);
	if(R > mid) chkmin(x << 1 | 1, mid + 1, r, L, R, v);
	pushup(x);
}

void make(int x, int l, int r, int p, int v) {
	if(l == r) return F.add(l, mx[x], -1), mx[x] = v, F.add(l, mx[x], 1);
	int mid = (l + r) >> 1; pushdown(x);
	if(p <= mid) make(x << 1, l, mid, p, v);
	else make(x << 1 | 1, mid + 1, r, p, v);
	pushup(x);
}

void solve() {
	int opt, a, b; read(opt), read(a), read(b);
	if(opt == 1) chkmin(1, 1, n, 1, a - 1, a - 1), make(1, 1, n, a, b);
	else printf("%lld\n", F.ask(a, b));
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(q); build(1, 1, n); F.add(1, n, 1);
	while(q--) solve();
	return 0;
}