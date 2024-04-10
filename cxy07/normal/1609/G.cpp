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
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, q, Ans, cur;
int a[MAXN], b[MAXN], a1, b1;
int sum[MAXN << 2], mn[MAXN << 2], tag[MAXN << 2];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void push(int x, int l, int r, int v) { 
	tag[x] += v;
	sum[x] += v * (r - l + 1);
	mn[x] += v; 
}

void pushdown(int x, int l, int r) {
	if(!tag[x]) return;
	int mid = (l + r) >> 1;
	push(x << 1, l, mid, tag[x]);
	push(x << 1 | 1, mid + 1, r, tag[x]);
	tag[x] = 0;
}

void pushup(int x) {
	sum[x] = sum[x << 1] + sum[x << 1 | 1];
	mn[x] = mn[x << 1];
}

void build(int x, int l, int r) {
	if(l == r) return sum[x] = mn[x] = b[l], void();
	int mid = (l + r) >> 1;
	build(x << 1, l, mid), build(x << 1 | 1, mid + 1, r);
	pushup(x);
}

void update(int x, int l, int r, int L, int R, int v) {
	if(L <= l && r <= R) return push(x, l, r, v), void();
	int mid = (l + r) >> 1; pushdown(x, l, r);
	if(L <= mid) update(x << 1, l, mid, L, R, v);
	if(R > mid) update(x << 1 | 1, mid + 1, r, L, R, v);
	pushup(x);
}

int query(int x, int l, int r, int L, int R) {
	if(L <= l && r <= R) return sum[x];
	int mid = (l + r) >> 1, res = 0; pushdown(x, l, r);
	if(L <= mid) res += query(x << 1, l, mid, L, R);
	if(R > mid) res += query(x << 1 | 1, mid + 1, r, L, R);
	return res;
}

int findpos(int x, int l, int r, int v, int s, int tot) {
	if(l == r) return s + sum[x] + v * (m - l + tot);
	int mid = (l + r) >> 1; pushdown(x, l, r);
	if(mn[x << 1 | 1] >= v) return findpos(x << 1, l, mid, v, s, tot);
	else return findpos(x << 1 | 1, mid + 1, r, v, s + sum[x << 1], tot);
}

void solve() {
	int opt, k, d; read(opt), read(k), read(d);
	if(opt == 1) {
		if(k == n + 1) a1 += d, k--;
		for(int i = n - k + 1; i <= n; ++i) a[i] += d;
	} else {
		if(k == m + 1) b1 += d, k--;
		update(1, 0, m, m - k + 1, m, d);
		cur += ((k + 1) * k >> 1) * d;
	}
	Ans = cur;
	for(int i = n; i >= 1; --i)
		Ans += findpos(1, 0, m, a[i], 0, n - i + 1);
	Ans += (a1 + b1) * (n + m + 1);
	printf("%lld\n", Ans);
}

signed main () {
#ifdef FILE
	freopen("g.in", "r", stdin);
	freopen("g.out", "w", stdout);
#endif
	read(n), read(m), read(q);
	for(int i = 1; i <= n; ++i) read(a[i]);
	for(int i = 1; i <= m; ++i) read(b[i]);
	a1 = a[1], b1 = b[1];
	for(int i = 1; i < n; ++i) a[i] = a[i + 1] - a[i];
	for(int i = 1; i < m; ++i) b[i] = b[i + 1] - b[i];
	--n, --m;
	for(int i = 1; i <= m; ++i) cur += (m - i + 1) * b[i];
	build(1, 0, m);
	while(q--) solve();
	return 0;
}