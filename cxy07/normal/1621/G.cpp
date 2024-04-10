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
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m;
int a[MAXN], FT[MAXN], pre[MAXN], suf[MAXN];
int mx[MAXN], mxv[MAXN];
LL Ans;
vec<int> v;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void add1(int x, int v) { for(; x <= n; x += lowbit(x)) (FT[x] += v) %= mod; }
int ask1(int x) { int res = 0; { for(; x; x -= lowbit(x)) (res += FT[x]) %= mod; } return res; }

void add2(int x, pii v) {
	for(; x; x -= lowbit(x)) {
		if(mx[x] < v.fst) mx[x] = v.fst, mxv[x] = 0;
		if(mx[x] == v.fst) (mxv[x] += v.scd) %= mod;
	}
}

pii ask2(int x) {
	int _mx = 0, _mxv = 0;
	for(; x <= n; x += lowbit(x)) {
		if(_mx < mx[x]) _mx = mx[x], _mxv = 0;
		if(_mx == mx[x]) (_mxv += mxv[x]) %= mod;
	}
	return mp(_mx, _mxv);
}

void solve() {
	read(n); v.clear(); Ans = 0;
	for(int i = 1; i <= n; ++i) read(a[i]), v.pb(a[i]);
	for(int i = 1; i <= n; ++i) FT[i] = mx[i] = mxv[i] = 0;
	sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());
	for(int i = 1; i <= n; ++i) a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
	for(int i = 1; i <= n; ++i) add1(a[i], pre[i] = ask1(a[i] - 1) + 1);
	for(int i = 1; i <= n; ++i) FT[i] = 0;
	for(int i = n; i >= 1; --i) {
		add1(n - a[i] + 1, suf[i] = ask1(n - a[i]) + 1);
		pii cur = ask2(a[i] + 1);
		if(!cur.scd) cur = mp(i, 1);
		(suf[i] -= cur.scd) %= mod; add2(a[i], cur);
	}
	for(int i = 1; i <= n; ++i) (Ans += 1ll * pre[i] * suf[i]) %= mod;
	Ans = (Ans + mod) % mod;
	printf("%lld\n", Ans);
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