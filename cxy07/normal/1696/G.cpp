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

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, q, a[MAXN];
double X, Y, v[3], Ans;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

struct info { // a[0] : 0, a[1] : 1 / (X + Y), a[2] : 1 / X
	double a[3][3];
	void clear() { memset(a, -0x3f, sizeof a); }
	info operator * (const info &b) const {
		info res; res.clear();
		res.a[0][0] = max({ a[0][0] + b.a[0][0], a[0][1] + b.a[1][0], a[0][2] + b.a[2][0] });
		res.a[0][1] = max({ a[0][0] + b.a[0][1], a[0][1] + b.a[1][1], a[0][2] + b.a[2][1] });
		res.a[0][2] = max({ a[0][0] + b.a[0][2], a[0][1] + b.a[1][2], a[0][2] + b.a[2][2] });
		res.a[1][0] = max({ a[1][0] + b.a[0][0], a[1][1] + b.a[1][0], a[1][2] + b.a[2][0] });
		res.a[1][1] = max({ a[1][0] + b.a[0][1], a[1][1] + b.a[1][1], a[1][2] + b.a[2][1] });
		res.a[1][2] = max({ a[1][0] + b.a[0][2], a[1][1] + b.a[1][2], a[1][2] + b.a[2][2] });
		res.a[2][0] = max({ a[2][0] + b.a[0][0], a[2][1] + b.a[1][0], a[2][2] + b.a[2][0] });
		res.a[2][1] = max({ a[2][0] + b.a[0][1], a[2][1] + b.a[1][1], a[2][2] + b.a[2][1] });
		res.a[2][2] = max({ a[2][0] + b.a[0][2], a[2][1] + b.a[1][2], a[2][2] + b.a[2][2] });
		return res;
	}
} s[MAXN << 2], M;

void setup(int x, int c) {
	s[x].clear();
	s[x].a[0][0] = s[x].a[0][1] = s[x].a[0][2] = 0;
	s[x].a[1][1] = s[x].a[1][0] = c * v[1];
	s[x].a[2][0] = c * v[2];
}

void build(int x, int l, int r) {
	if(l == r) return setup(x, a[l]), void();
	int mid = (l + r) >> 1;
	build(x << 1, l, mid), build(x << 1 | 1, mid + 1, r);
	s[x] = s[x << 1] * s[x << 1 | 1];
}

void update(int x, int l, int r, int p, int v) {
	if(l == r) return a[l] = v, setup(x, v), void();
	int mid = (l + r) >> 1;
	if(p <= mid) update(x << 1, l, mid, p, v);
	else update(x << 1 | 1, mid + 1, r, p, v);
	s[x] = s[x << 1] * s[x << 1 | 1];
}

void query(int x, int l, int r, int L, int R) {
	if(L <= l && r <= R) return M = M * s[x], void();
	int mid = (l + r) >> 1;
	if(L <= mid) query(x << 1, l, mid, L, R);
	if(R > mid) query(x << 1 | 1, mid + 1, r, L, R);
}

void solve() {
	int o, a, b; read(o), read(a), read(b);
	if(o == 1) { update(1, 1, n, a, b); return; }
	M.clear(); M.a[0][0] = M.a[1][1] = M.a[2][2] = 0;
	query(1, 1, n, a, b); Ans = -INF;
	for(int i = 0; i < 3; ++i) 
		for(int j = 0; j < 3; ++j) Ans = max(Ans, M.a[i][j]);
	printf("%.10lf\n", Ans);
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(q); scanf("%lf%lf", &X, &Y); 
	if(X < Y) swap(X, Y);
	v[0] = 0, v[1] = 1. / (X + Y), v[2] = 1. / X;
	for(int i = 1; i <= n; ++i) read(a[i]);
	build(1, 1, n);
	while(q--) solve();
	return 0;
}