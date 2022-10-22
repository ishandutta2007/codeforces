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
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, q, iv2 = (mod + 1) >> 1, LIM = 2e14;
int a[MAXN], Ans[MAXN];
int p2[MAXN], ip2[MAXN];
int sum[MAXN], stk[MAXN], siz[MAXN], pre[MAXN], top;
vec<pii> qs[MAXN];

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

struct info {
	int v, m;
	info(int _v = 0, int _m = 0) : v(_v), m(_m) {}
	info mul2(int d) {
		if(!v) return info(0, 0);
		assert(v > 0);
		int v2 = LIM / v, m2 = (p2[d] * m) % mod;
		if(__lg(v2) <= d) v2 = LIM;
		else v2 = v << d;
		return info(v2, m2);
	}
	info operator + (const info &b) const {
		return info(min(LIM, v + b.v), (m + b.m) % mod);
	}
} s[MAXN];

int calc(int l, int r) {
	return (sum[r] - sum[l - 1] + mod) * ip2[l] % mod;
}

signed main () {
#ifdef FILE
	freopen("CF878E.in", "r", stdin);
	freopen("CF878E.out", "w", stdout);
#endif
	read(n), read(q); p2[0] = ip2[0] = 1;
	for(int i = 1; i <= n; ++i) read(a[i]);
	for(int i = 1, l, r; i <= q; ++i) {
		read(l), read(r);
		qs[r].pb(mp(l, i));
	}
	for(int i = 1; i < MAXN; ++i) {
		p2[i] = p2[i - 1] * 2 % mod;
		ip2[i] = ip2[i - 1] * iv2 % mod;
	}
	for(int i = 1; i <= n; ++i)
		sum[i] = (sum[i - 1] + (a[i] + mod) * p2[i]) % mod;
	for(int i = 1, num; i <= n; ++i) {
		info cur(a[i], (a[i] + mod) % mod); num = 1;
		while(top && cur.v >= 0) {
			cur = s[top] + cur.mul2(siz[top]);
			num += siz[top], --top;
		}
		stk[++top] = i; siz[top] = num; s[top] = cur;
		pre[top] = (pre[top - 1] + cur.m) % mod;
		for(auto t : qs[i]) {
			int p = lower_bound(stk + 1, stk + top, t.fst) - stk;
			Ans[t.scd] += calc(t.fst, stk[p]);
			(Ans[t.scd] += (pre[top] - pre[p] + mod) * 2) %= mod;
		}
	}
	for(int i = 1; i <= q; ++i) 
		printf("%lld\n", (Ans[i] + mod) % mod);
	return 0;
}