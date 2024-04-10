//Code By CXY07 - It's My Fiesta.
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define popc(x) __builtin_popcount(x)
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

const int MAXN = 1010;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, Ans, E0, E1, f, p = 1;
int a[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void modadd(int &x, int y) {
	x += y;
	if(x >= mod) x -= mod;
}

int inv(int i) {
	if(i <= 1) return i;
	return inv(mod % i) * (mod - mod / i) % mod;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(m);
	for(int i = 1; i <= m; ++i) read(a[i]), n += a[i];
	sort(a + 1, a + m + 1);
	E0 = 0, E1 = 2 * n % mod, f = n;
	while(p <= m && a[p] == 1) modadd(Ans, 2), ++p;
	for(int i = 1, t; i < n; ++i) {
		t = ((3 * n - 2 * i) * E1 - (2 * n - i) * E0 % mod * (n - i + 1)) % mod;
		E0 = E1; E1 = t; f = f * (n - i) % mod;
		while(p <= m && a[p] == i + 1) modadd(Ans, E1 * inv(f) % mod), ++p;
	}
	Ans = E1 * inv(f) % mod - Ans;
	Ans = (Ans % mod + mod) % mod;
	printf("%lld\n", Ans);
	return 0;
}