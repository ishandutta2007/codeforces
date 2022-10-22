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

const int MAXN = 1e5 + 10;
const int INF = 2e16;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, k, Ans;
int d[MAXN], a[MAXN], pre[MAXN], suf[MAXN];
int link[MAXN], stk[MAXN], top;
int min_a[MAXN << 2], min_b[MAXN << 2], tag[MAXN << 2], val[MAXN << 2];
vec<int> G[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void push(int x, int v) { min_b[x] += v, val[x] -= v, tag[x] += v; }

void pushdown(int x) { if(tag[x]) push(x << 1, tag[x]), push(x << 1 | 1, tag[x]), tag[x] = 0; }

int calc(int x, int l, int r, int v) {
	if(l == r) return min_a[x] - v;
	int mid = (l + r) >> 1; pushdown(x);
	if(min_b[x << 1] < v) return min(calc(x << 1, l, mid, v), val[x]);
	else return min(calc(x << 1 | 1, mid + 1, r, v), min_a[x << 1] - v);
}

void pushup(int x, int l, int r) {
	min_a[x] = min(min_a[x << 1], min_a[x << 1 | 1]);
	min_b[x] = min(min_b[x << 1], min_b[x << 1 | 1]);
	int mid = (l + r) >> 1;
	val[x] = calc(x << 1 | 1, mid + 1, r, min_b[x << 1]);
}

void build(int x, int l, int r) {
	if(l == r) return min_a[x] = min_b[x] = suf[l], void();
	int mid = (l + r) >> 1;
	build(x << 1, l, mid), build(x << 1 | 1, mid + 1, r);
	pushup(x, l, r);
}

void update(int x, int l, int r, int L, int R, int v) {
	if(L > R) return;
	if(L <= l && r <= R) return push(x, v), void();
	int mid = (l + r) >> 1; pushdown(x);
	if(L <= mid) update(x << 1, l, mid, L, R, v);
	if(R > mid) update(x << 1 | 1, mid + 1, r, L, R, v);
	pushup(x, l, r);
}

int query2(int x, int l, int r, int v) {
	if(l == r) return assert(min_a[x] - v <= k), l;
	int mid = (l + r) >> 1; pushdown(x);
	if(min_a[x << 1 | 1] - v <= k) return query2(x << 1 | 1, mid + 1, r, v);
	else return assert(min_a[x << 1] - v <= k), query2(x << 1, l, mid, v);
}

int query(int x, int l, int r, int &res) {
	if(l == r) {
		int _r = min_a[x] - res <= k ? l : 0;
		res = min(res, min_b[x]); return _r;
	} int mid = (l + r) >> 1; pushdown(x);
	if(min_b[x << 1] < res) {
		if(val[x] <= k) return query(x << 1 | 1, mid + 1, r, res = min_b[x << 1]);
		else {
			int _r = query(x << 1, l, mid, res);
			res = min(res, min_b[x]); return _r;
		}
	} else {
		int _r = min_a[x << 1] - res <= k ? query2(x << 1, l, mid, res) : 0;
		return max(_r, query(x << 1 | 1, mid + 1, r, res));
	}
}

void DFS(int x) {
	stk[++top] = x;
	if(link[x] != n + 1) update(1, 1, n, link[x] - 1, n, -(pre[link[x]] - pre[x]));
	if(x != n + 1) {
		int L = 1, R = top - 1, mid;
		while(L < R) {
			mid = (L + R + 1) >> 1;
			if(pre[stk[mid]] - pre[x] > k) L = mid;
			else R = mid - 1;
		} int limr = stk[L] - 1, p, res = INF;
		update(1, 1, n, 1, x - 1, INF), update(1, 1, n, limr, n, -INF);
		p = query(1, 1, n, res);
		update(1, 1, n, limr, n, INF), update(1, 1, n, 1, x - 1, -INF);
		Ans = max(Ans, p - x + 1);
	} for(auto to : G[x]) DFS(to);
	if(link[x] != n + 1) update(1, 1, n, link[x] - 1, n, pre[link[x]] - pre[x]);
	top--;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(k);
	for(int i = 1; i < n; ++i) read(d[i]);
	for(int i = 1; i <= n; ++i) read(a[i]);
	for(int i = 2; i <= n; ++i) {
		pre[i] = pre[i - 1] + d[i - 1] - a[i - 1];
		suf[i] = suf[i - 1] + d[i - 1] - a[i];
	} pre[n + 1] = INF, link[n + 1] = n + 1;
	for(int i = n + 1; i >= 1; --i) {
		while(top && pre[stk[top]] <= pre[i]) top--;
		if(top) G[stk[top]].pb(i), link[i] = stk[top];
		stk[++top] = i;
	} top = 0; build(1, 1, n); DFS(n + 1);
	printf("%lld\n", Ans);
	return 0;
}