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

const int MAXN = 210;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, k;
int dp[MAXN][MAXN], fac[MAXN], ifac[MAXN];
int Inv[MAXN], Ans[MAXN];

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

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(k);
	fac[0] = ifac[0] = Inv[0] = Inv[1] = 1;
	for(int i = 1; i < MAXN; ++i) fac[i] = fac[i - 1] * i % mod;
	for(int i = 2; i < MAXN; ++i)
		Inv[i] = ((mod - (mod / i) * Inv[mod % i]) % mod + mod) % mod;
	ifac[MAXN - 1] = inv(fac[MAXN - 1]);
	for(int i = MAXN - 2; i; --i) ifac[i] = ifac[i + 1] * (i + 1) % mod;
	dp[0][0] = 1;
	for(int i = 0; i <= k; ++i) {
		for(int j = 0; j <= i; ++j) {
			(Ans[i] += dp[i][j] * ifac[j]) %= mod;
			int binom = n - (i + j);
			for(int l = 2; (l - 1) + i <= k; ++l) {
				binom = binom * (n - (i + j) - l + 1) % mod * Inv[l] % mod;
				(dp[i + l - 1][j + 1] += dp[i][j] * binom % mod * fac[l - 1] % mod) %= mod;
			}
		}
	}
	for(int i = 1; i <= k; ++i) {
		if(i >= 2) Ans[i] = (Ans[i] + Ans[i - 2]) % mod;
		printf("%lld ", Ans[i]);
	}
	return 0;
}