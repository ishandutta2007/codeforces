//Code By CXY07 - It's My Fiesta.
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
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

const int MAXN = 1e6 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct info {
	int x, l, r, o;
	info(int _x = 0, int _l = 0, int _r = 0, int _o = 0) :
		x(_x), l(_l), r(_r), o(_o) {}
	bool operator < (const info &b) const { return x < b.x; }
};

int n, m;
int stk[MAXN], top = 0;
int mxL[MAXN], mxR[MAXN], mnL[MAXN], mnR[MAXN];
int mx[MAXN << 2], mxc[MAXN << 2], tag[MAXN << 2];
LL a[MAXN], Ans;
vec<info> M[70];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void push(int x, int v) { mx[x] += v, tag[x] += v; }

void pushdown(int x) {
	if(!tag[x]) return;
	push(x << 1, tag[x]), push(x << 1 | 1, tag[x]);
	tag[x] = 0;
}

void pushup(int x) {
	mxc[x] = 0;
	mx[x] = max(mx[x << 1], mx[x << 1 | 1]);
	if(mx[x << 1] == mx[x]) mxc[x] += mxc[x << 1];
	if(mx[x << 1 | 1] == mx[x]) mxc[x] += mxc[x << 1 | 1];
}

void build(int x, int l, int r) {
	if(l == r) return mx[x] = 0, mxc[x] = 1, void();
	int mid = (l + r) >> 1;
	build(x << 1, l, mid), build(x << 1 | 1, mid + 1, r);
	pushup(x);
}

void update(int x, int l, int r, int L, int R, int v) {
	if(L <= l && r <= R) return push(x, v), void();
	int mid = (l + r) >> 1; pushdown(x);
	if(L <= mid) update(x << 1, l, mid, L, R, v);
	if(R > mid) update(x << 1 | 1, mid + 1, r, L, R, v);
	pushup(x);
}

int query(int x, int l, int r, int L, int R) {
	if(L <= l && r <= R) return (mx[x] == 2 ? mxc[x] : 0);
	int mid = (l + r) >> 1, res = 0; pushdown(x);
	if(L <= mid) res += query(x << 1, l, mid, L, R);
	if(R > mid) res += query(x << 1 | 1, mid + 1, r, L, R);
	return res;
}

void calc(int idx) {
	if(!M[idx].size()) return;
	sort(M[idx].begin(), M[idx].end());
	int siz = M[idx].size();
	for(int l = 0, r; l < siz; l = r + 1) {
		r = l;
		while(r + 1 < siz && M[idx][r + 1].x == M[idx][l].x) ++r;
		for(int i = l; i <= r; ++i) update(1, 1, n, M[idx][i].l, M[idx][i].r, M[idx][i].o);
		if(M[idx][l].x <= n) {
			if(mx[1] != 2) continue;
			Ans += 1ll * mxc[1] * (M[idx][r + 1].x - M[idx][l].x);
		}
	}
	assert(mx[1] == 0);
}

signed main () {
#ifdef FILE
	freopen("f.in", "r", stdin);
	freopen("f.out", "w", stdout);
#endif
	read(n); 
	for(int i = 1; i <= n; ++i) read(a[i]);
	build(1, 1, n);
	top = 0;
	for(int i = 1; i <= n; ++i) {
		while(top && a[stk[top]] < a[i]) --top;
		mxL[i] = stk[top] + 1;
		stk[++top] = i;
	}
	top = 0;
	for(int i = 1; i <= n; ++i) {
		while(top && a[stk[top]] > a[i]) --top;
		mnL[i] = stk[top] + 1;
		stk[++top] = i;
	}
	top = 0; stk[0] = n + 1;
	for(int i = n; i >= 1; --i) {
		while(top && a[stk[top]] <= a[i]) --top;
		mxR[i] = stk[top] - 1;
		stk[++top] = i;
	}
	top = 0; stk[0] = n + 1;
	for(int i = n; i >= 1; --i) {
		while(top && a[stk[top]] >= a[i]) --top;
		mnR[i] = stk[top] - 1;
		stk[++top] = i;
	}
	for(int i = 1, p; i <= n; ++i) {
		p = __builtin_popcountll(a[i]);
		M[p].pb(info(i, mxL[i], i, 1));
		M[p].pb(info(mxR[i] + 1, mxL[i], i, -1));
		M[p].pb(info(i, mnL[i], i, 1));
		M[p].pb(info(mnR[i] + 1, mnL[i], i, -1));
	}
	for(int i = 0; i <= 60; ++i) calc(i);
	printf("%lld\n", Ans);
	return 0;
}