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

const int MAXN = 110;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, iv2 = (mod + 1) >> 1;
int d[MAXN], v[MAXN], dp[MAXN][MAXN], g[MAXN][MAXN];
int ip2[MAXN], fac[MAXN], ifac[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

int qpow(int x, int b) {
	int res = 1;
	for(; b; b >>= 1, (x *= x) %= mod) if(b & 1) (res *= x) %= mod;
	return res;
}

void init() {
	fac[0] = ifac[0] = ip2[0] = 1;
	for(int i = 1; i < MAXN; ++i) {
		fac[i] = fac[i - 1] * i % mod;
		ip2[i] = ip2[i - 1] * iv2 % mod;
	}
	ifac[MAXN - 1] = inv(fac[MAXN - 1]);
	for(int i = MAXN - 2; i; --i) ifac[i] = ifac[i + 1] * (i + 1) % mod;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n); init();
	for(int i = 1; i <= n; ++i) read(d[i]);
	for(int s = 0; s <= n; ++s)
		for(int p = 0, q; (p << 1) <= s; ++p) {
			q = s - (p << 1);
			(v[s] += ifac[p] * ifac[q] % mod * (((p + q) & 1) ? mod - 1 : 1)) %= mod;
		}
	dp[1][d[1]] = 1;
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j <= (i << 1); ++j) {
			if(!g[i][j]) continue;
			for(int d = 0; (d << 1) <= j; ++d)
				(dp[i][j - (d << 1)] += g[i][j] * ip2[d] % mod * ifac[d]) %= mod;
		}
		for(int j = 1, x, y; j <= n - i; ++j) {
			if(!dp[i][j]) continue;
			x = 0, y = 0;
			for(int k = i + 1; k <= i + j; ++k) d[k] == 2 ? x++ : y++;
			for(int s = 0, coe; s <= y; ++s) {
				coe = fac[y] * fac[x + (y << 1) - (s << 1)] % mod * v[s] % mod * ifac[y - s] % mod * ip2[y] % mod;
				(g[i + j][x + (y << 1) - (s << 1)] += dp[i][j] * coe) %= mod;
			}
		}
	}
	printf("%lld\n", dp[n][0]);
	return 0;
}