//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
//#define ull unsigned long long
#define LL long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) qpow((x),mod - 2)
#define lowbit(x) ((x) & (-(x)))
#define vec vector

const int MAXN = 5010;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, k, ans, fac[MAXN], ifac[MAXN];
int S[MAXN][MAXN];

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

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
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n); read(m); read(k);
	S[0][0] = 1;
	for(int i = 1; i <= k; ++i) { 
		S[i][0] = 0;
		for(int j = 1; j <= i; ++j)
			S[i][j] = (S[i - 1][j] * j % mod + S[i - 1][j - 1]) % mod;
	}
	fac[0] = ifac[0] = 1;
	for(int i = 1; i <= k; ++i) fac[i] = fac[i - 1] * i % mod;
	ifac[k] = inv(fac[k]);
	for(int i = k - 1; i >= 1; --i) ifac[i] = ifac[i + 1] * (i + 1) % mod;
	if(n <= k) {
		for(int i = 0; i <= n; ++i)
			(ans += qpow(i, k) * C(n, i) % mod * qpow(m - 1, n - i) % mod) %= mod;
	} else {
		int c = 1;
		for(int i = 0; i <= k; ++i) {
			(ans += S[k][i] * fac[i] % mod * c % mod * qpow(m, n - i) % mod) %= mod;
			(c *= (n - i) * inv(i + 1) % mod) %= mod;
		}
	}
	(ans *= inv(qpow(m, n))) %= mod;
	printf("%lld\n", ans);
	return 0;
}