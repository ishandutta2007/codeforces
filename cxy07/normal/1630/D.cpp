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

const int MAXN = 1e6 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m, B, Ans;
int a[MAXN], b[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void solve() {
	read(n), read(m); B = 0, Ans = -INF;
	for(int i = 0; i < n; ++i) read(a[i]);
	for(int i = 1; i <= m; ++i) read(b[i]), B = __gcd(B, b[i]);
	int sum = 0;
	for(int i = 0; i < n; ++i) sum += abs(a[i]);
	for(int p = 0; p < B; ++p) {
		int o = 0, mn = INF;
		for(int i = p; i < n; i += B) {
			if(a[i] < 0) o ^= 1;
			mn = min(mn, abs(a[i]));
		}
		if(o == 1) sum -= mn * 2;
	}
	Ans = max(Ans, sum);
	sum = 0; for(int i = 0; i < n; ++i) sum += abs(a[i]);
	for(int p = 0; p < B; ++p) {
		int o = 0, mn = INF;
		for(int i = p; i < n; i += B) {
			if(a[i] < 0) o ^= 1;
			mn = min(mn, abs(a[i]));
		}
		if(o == 0) sum -= mn * 2;
	}
	Ans = max(Ans, sum);
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