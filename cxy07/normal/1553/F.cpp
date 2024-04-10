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

const int MAXN = 3e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, V = 3e5;
int a[MAXN], p[MAXN];
int FT1[MAXN], FT2[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void add1(int x, int v) { for(; x; x -= lowbit(x)) FT1[x] += v; }

int ask1(int x) {
	int res = 0; for(; x <= V; x += lowbit(x)) res += FT1[x];
	return res;
}

void add2(int x, int v) { for(; x <= V; x += lowbit(x)) FT2[x] += v; }

int ask2(int x) {
	int res = 0; for(; x; x -= lowbit(x)) res += FT2[x];
	return res;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n);
	for(int i = 1; i <= n; ++i) read(a[i]);
	for(int i = 1, s = 0; i <= n; ++i) {
		p[i] = p[i - 1] + s + (i - 1) * a[i];
		s += a[i];
		for(int j = a[i]; j <= V; j += a[i]) p[i] -= ask1(j) * a[i];
		add1(a[i], 1);
		p[i] -= ask2(a[i]);
		for(int j = a[i]; j <= V; j += a[i]) add2(j, a[i]);
		printf("%lld ", p[i]);
	}
	return 0;
}