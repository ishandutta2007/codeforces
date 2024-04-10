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

const int MAXN = 110;
const int MAXX = 2e5 + 10;
const int SIZ = 1e4 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, q, prod = 1, c[MAXN], b[MAXN];
int L, R, sav[MAXX], sumb[MAXN];
int dp[SIZ], sum[SIZ];
bool vis[MAXX];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

int calc(int x) {
	if(vis[x + (int)1e5]) return sav[x + (int)1e5];
	vis[x + (int)1e5] = true;
	memset(sum, 0, sizeof sum); 
	for(int i = 0; i <= n * m; ++i) sum[i] = 1;
	for(int i = 1; i <= n; ++i) {
		memset(dp, 0, sizeof dp);
		for(int j = 0; j <= n * m; ++j) {
			if(j < i * x + sumb[i]) continue;
			dp[j] = sum[j];
			if(j > c[i]) (dp[j] -= sum[j - c[i] - 1]) %= mod;
		}
		for(int j = 0; j <= n * m; ++j)
			sum[j] = (dp[j] + (j > 0 ? sum[j - 1] : 0)) % mod;
	}
	return sav[x + (int)1e5] = (sum[n * m] + mod) % mod;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), m = 100; 
	for(int i = 1; i <= n; ++i) {
		read(c[i]);
		prod = prod * (c[i] + 1) % mod;
	}
	for(int i = 1; i < n; ++i) read(b[i]);
	L = R = INF;
	for(int i = 1, s = 0, si = 0; i <= n; ++i) {
		sumb[i] = (i * s - si + mod) % mod;
		(s += b[i]) %= mod, (si += b[i] * i) %= mod;
		L = min(L, -sumb[i] / i - 1);
		R = min(R, (i * m - sumb[i]) / i + 1);
	}
	read(q);
	while(q--) {
		int x; read(x);
		if(x < L) printf("%lld\n", prod);
		else if(x > R) puts("0");
		else printf("%lld\n", calc(x));
	}
	return 0;
}