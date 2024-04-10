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
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, Ans, cB, cW;
int same, BW, WB;
int fac[MAXN], ifac[MAXN];
char s[MAXN][3];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

int qpow(int x, int b) {
	int res = 1;
	for(; b; b >>= 1, (x *= x) %= mod) if(b & 1) (res *= x) %= mod;
	return res;
}

int C(int x, int y) {
	if(x < y || y < 0) return 0;
	return fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n); fac[0] = ifac[0] = 1;
	for(int i = 1; i < MAXN; ++i) fac[i] = fac[i - 1] * i % mod;
	ifac[MAXN - 1] = inv(fac[MAXN - 1]);
	for(int i = MAXN - 2; i; --i) ifac[i] = ifac[i + 1] * (i + 1) % mod;
	for(int i = 1; i <= n; ++i) {
		scanf("%s", s[i] + 1);
		if(s[i][1] == 'B') cB++;
		if(s[i][1] == 'W') cW++;
		if(s[i][2] == 'B') cB++;
		if(s[i][2] == 'W') cW++;
	}
	if(cB > n || cW > n) return puts("0"), 0;
	Ans = C((n << 1) - cB - cW, n - cW);
	for(int i = 1; i <= n; ++i) {
		if(s[i][1] == s[i][2] && s[i][1] != '?') same++;
		else if(s[i][1] == 'B' || s[i][2] == 'W') ++BW;
		else if(s[i][1] == 'W' || s[i][2] == 'B') ++WB;
	}
	if(!same) {
		for(int i = 0; i <= n - WB - BW; ++i)
			if((WB + i) > 0 && (WB + i) < n)
				(Ans -= C(n - WB - BW, i)) %= mod;
		Ans = (Ans + mod) % mod;
	}
	printf("%lld\n", Ans);
	return 0;
}