//Code By CXY07 - It's My Fiesta.
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

const int MAXN = 5e4 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m, d;
int a[MAXN], b[MAXN];
vec<pii> va, vb;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	a *= f; return 1;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void solve() {
	read(n), read(d); va.clear(), vb.clear();
	for(int i = 1; i <= n; ++i) read(a[i]);
	read(m);
	for(int i = 1; i <= m; ++i) read(b[i]);
	pii pre(0, 0);
	for(int i = 1, x, c; i <= n; ++i) {
		x = a[i], c = 1;
		while(x % d == 0) x /= d, c *= d;
		if(pre.fst == x) pre.scd += c;
		else {
			if(i > 1) va.pb(pre); 
			pre = mp(x, c);
		}
	}
	va.pb(pre);
	pre = mp(0, 0);
	for(int i = 1, x, c; i <= m; ++i) {
		x = b[i], c = 1;
		while(x % d == 0) x /= d, c *= d;
		if(pre.fst == x) pre.scd += c;
		else { 
			if(i > 1) vb.pb(pre); 
			pre = mp(x, c); 
		}
	}
	vb.pb(pre);
	if(va.size() != vb.size()) return puts("No"), void();
	for(int i = 0; i < (int)va.size(); ++i) {
		//cerr << vb[i].fst << ' ' << vb[i].scd << endl;
		if(va[i] != vb[i]) return puts("No"), void();
	}
	return puts("Yes"), void();
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