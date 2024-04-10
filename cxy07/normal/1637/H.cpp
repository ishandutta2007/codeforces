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

const int MAXN = 5e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct FenwickTree {
	int a[MAXN], N;
	void clear(int n) { N = n; memset(a, 0, sizeof(int) * (n + 5)); }
	void add(int x, int v) { for(; x <= N; x += lowbit(x)) a[x] += v; }
	int ask(int x) { int r = 0; for(; x; x -= lowbit(x)) r += a[x]; return r; }
} FT;

int T, n, m, sum;
int a[MAXN], t[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void solve() {
	read(n); FT.clear(n), sum = 0;
	for(int i = 1; i <= n; ++i) read(a[i]), t[i] = 0;
	for(int i = 1, o; i <= n; ++i) {
		o = FT.ask(a[i]); t[i] = o - ((i - 1) - o);
		FT.add(a[i], 1);
	}
	for(int i = 1; i <= n; ++i) FT.add(a[i], -1);
	for(int i = n, o; i >= 1; --i) {
		o = FT.ask(a[i]);
		t[i] += 2 * o; sum += o; FT.add(a[i], 1);
	}
	for(int i = 1; i <= n; ++i) FT.add(a[i], -1);
	printf("%lld ", sum);
	sort(t + 1, t + n + 1);
	for(int i = 1, c = t[1]; i <= n; c += t[++i])
		printf("%lld ", sum + c - ((i - 1) * i >> 1));
	putchar('\n');
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