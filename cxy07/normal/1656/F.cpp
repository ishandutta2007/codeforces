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
const int INF = 1e18;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m, Ans;
int a[MAXN], sum = 0;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

#define f(x) ((s2 + a[1] * (n - i) + s1 + a[n] * (i - 1)) * (x) + a[1] * s2 + a[n] * s1)

void solve() {
	read(n); sum = 0; Ans = -INF;
	for(int i = 1; i <= n; ++i) read(a[i]), sum += a[i];
	sort(a + 1, a + n + 1);
	if(sum + (n - 2) * a[1] > 0 || sum + (n - 2) * a[n] < 0) 
		return puts("INF"), void();
	int s1 = 0, s2 = sum;
	for(int i = 1; i < n; ++i) {
		s2 -= a[i];
		if(i > 1) s1 += a[i];
		//(a[1] + x) * (s2 + (n - i) * x) + (a[n] + x) * (s1 + (i - 1) * x) - (n - 1) * x * x
		//= (s2 + a[1] * (n - i) + s1 + a[n] * (i - 1)) * x + a[1] * s2 + a[n] * s1
		Ans = max(Ans, max(f(-a[i]), f(-a[i + 1])));
	}
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