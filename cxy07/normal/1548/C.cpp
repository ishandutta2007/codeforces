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

const int MAXN = 3e6 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, q, iv3;
int dp[MAXN][3], fac[MAXN], ifac[MAXN];

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

int C(int x, int y) {
	if(x < y) return 0;
	return fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(q); fac[0] = ifac[0] = 1; iv3 = inv(3);
	for(int i = 1; i < MAXN; ++i) fac[i] = fac[i - 1] * i % mod;
	ifac[MAXN - 1] = inv(fac[MAXN - 1]);
	for(int i = MAXN - 2; i; --i) ifac[i] = ifac[i + 1] * (i + 1) % mod;
	dp[0][0] = dp[0][1] = dp[0][2] = n;
	for(int x = 1, sum; x <= (n * 3); ++x) {
		sum = C(3 * n, x + 1);
		dp[x][0] = ((sum - dp[x - 1][0] * 2 - dp[x - 1][1]) % mod + mod) * iv3 % mod;
		dp[x][1] = (dp[x][0] + dp[x - 1][0]) % mod;
		dp[x][2] = (dp[x][1] + dp[x - 1][1]) % mod;
		assert((dp[x][0] + dp[x][1] + dp[x][2]) % mod == sum);
	}
	while(q--) {
		int x; read(x);
		printf("%lld\n", (dp[x][0] + C(3 * n, x)) % mod);
	}
	return 0;
}