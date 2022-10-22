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

int n, q, g, r, mod, Tcnt, lastans;
int l[MAXN], f[MAXN], sum[MAXN];
int rt, ls[MAXN * 40], rs[MAXN * 40], mn[MAXN * 40];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void update(int &x, int l, int r, int p, int v) {
	if(!x) x = ++Tcnt;
	mn[x] = min(mn[x], v);
	if(l == r) return;
	int mid = (l + r) >> 1;
	if(p <= mid) update(ls[x], l, mid, p, v);
	else update(rs[x], mid + 1, r, p, v);
}

int query(int x, int l, int r, int L, int R) {
	if(L <= l && r <= R) return mn[x];
	int mid = (l + r) >> 1, res = INF;
	if(L <= mid) res = min(res, query(ls[x], l, mid, L, R));
	if(R > mid) res = min(res, query(rs[x], mid + 1, r, L, R));
	return res;
}

int ask(int c) {
	int L = (g + c) % mod, R = (mod - 1 + c) % mod, res = INF;
	if(L <= R) return query(rt, 0, mod - 1, L, R);
	res = min(res, query(rt, 0, mod - 1, 0, R));
	res = min(res, query(rt, 0, mod - 1, L, mod - 1));
	return res;
}

void solve(int round) {
	int t, Ans, pos; read(t);
	pos = ask(mod - t % mod);
	if(pos > n + 1) Ans = sum[n + 1];
	else {
		if(pos == n + 1) Ans = sum[n + 1];
		else {
			int _t = (sum[pos] % mod + t) % mod;
			Ans = sum[pos] + (mod - _t) + f[pos];
		}
	} Ans += t; lastans = Ans;
	printf("%lld\n", Ans);
}

signed main () {
#ifdef FILE
	freopen("GT.in", "r", stdin);
	freopen("GT.out", "w", stdout);
#endif
	read(n), read(g), read(r); mod = g + r;
	memset(mn, 0x3f, sizeof mn);
	for(int i = 1; i <= n + 1; ++i) read(l[i]);
	for(int i = 1; i <= n + 1; ++i) sum[i] = sum[i - 1] + l[i];
	update(rt, 0, mod - 1, sum[n + 1] % mod, n + 1);
	f[n + 1] = 0;
	for(int i = n, c, pos; i >= 0; --i) {
		c = sum[i] % mod; pos = ask(c);
		if(pos > n + 1) f[i] = sum[n + 1] - sum[i];
		else {
			if(pos == n + 1) f[i] = sum[n + 1] - sum[i];
			else {
				int t = (sum[pos] - sum[i] % mod + mod) % mod;
				f[i] = (sum[pos] - sum[i]) + (mod - t) + f[pos];
			}
		}
		if(i) update(rt, 0, mod - 1, sum[i] % mod, i);
	} read(q);
	for(int i = 1; i <= q; ++i) solve(i);
	return 0;
}