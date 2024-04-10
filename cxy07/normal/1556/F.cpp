//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
#define file(FILENAME) freopen(FILENAME".in", "r", stdin), freopen(FILENAME".out", "w", stdout)
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define LINE() cout << "LINE = " << __LINE__ << endl
#define debug(x) cout << #x << " = " << x << endl
#define abs(x) ((x) < 0 ? (-(x)) : (x))
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

const int MAXN = 15;
const int SIZ = (1 << 14) + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, U, Ans;
int a[MAXN], win[MAXN][MAXN], iwin[MAXN][MAXN], popc[SIZ], ia[MAXN];
int f[SIZ], g[SIZ];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
	return 1;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

int qpow(int x, int b) {
	int res = 1;
	for(; b; b >>= 1, (x *= x) %= mod) if(b & 1) (res *= x) %= mod;
	return res;
}

int _win(int x, int y) {
	return a[x] * inv(a[x] + a[y]) % mod;
}

int _iwin(int x, int y) {
	return (a[x] + a[y]) * ia[x] % mod;
}

int _win2(int S, int T) {
	int res = 1;
	for(int i = 1; i <= n; ++i) {
		if(((S >> (i - 1)) & 1) == 0) continue;
		for(int j = 1; j <= n; ++j) {
			if(((T >> (j - 1)) & 1) == 0) continue;
			res = res * win[i][j] % mod;
		}
	}
	return res;
}

int _iwin2(int S, int T) {
	int res = 1;
	for(int i = 1; i <= n; ++i) {
		if(((S >> (i - 1)) & 1) == 0) continue;
		for(int j = 1; j <= n; ++j) {
			if(((T >> (j - 1)) & 1) == 0) continue;
			res = res * iwin[i][j] % mod;
		}
	}
	return res;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n); U = (1 << n) - 1;
	for(int i = 1; i <= n; ++i) read(a[i]), ia[i] = inv(a[i]);
	for(int i = 1; i < (1 << n); ++i) 
		popc[i] = popc[i >> 1] + (i & 1);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if(i ^ j) win[i][j] = _win(i, j), iwin[i][j] = _iwin(i, j);
	for(int S = 1; S < (1 << n); ++S) {
		g[S] = _win2(S, U ^ S) % mod; f[S] = g[S];
		for(int T = (S - 1) & S; T; T = (T - 1) & S)
			(f[S] += mod - g[T] * f[S ^ T] % mod * _iwin2(T, S ^ T) % mod) %= mod;
		(Ans += f[S] * popc[S] % mod) %= mod;
	}
	cout << Ans % mod << endl;
	return 0;
}