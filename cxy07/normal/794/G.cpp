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

const int MAXN = 6e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, lens, lent, tot, Ans;
int fac[MAXN], ifac[MAXN], p2[MAXN];
int cA, cB, cntS, cntT;
char s[MAXN], t[MAXN];

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

void Init() {
	static int f[MAXN];
	fac[0] = ifac[0] = p2[0] = 1;
	for(int i = 1; i < MAXN; ++i) fac[i] = fac[i - 1] * i % mod;
	ifac[MAXN - 1] = inv(fac[MAXN - 1]);
	for(int i = MAXN - 2; i; --i) ifac[i] = ifac[i + 1] * (i + 1) % mod;
	for(int i = 1; i < MAXN; ++i) p2[i] = (p2[i - 1] << 1) % mod;
	for(int i = n; i >= 1; --i) {
		f[i] = (n / i) * (n / i) % mod;
		for(int j = i * 2; j <= n; j += i) (f[i] += mod - f[j]) %= mod;
	}
	for(int i = 1; i <= n; ++i) (tot += f[i] * p2[i]) %= mod;
}

int C(int x, int y) {
	if(x < y || y < 0) return 0;
	return fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}

signed main () {
#ifdef FILE
	freopen("CF794G.in", "r", stdin);
	freopen("CF794G.out", "w", stdout);
#endif
	scanf("%s%s", s + 1, t + 1); read(n); Init();
	lens = strlen(s + 1), lent = strlen(t + 1);
	for(int i = 1; i <= lens; ++i) {
		if(s[i] == 'A') ++cA;
		if(s[i] == 'B') ++cB;
		if(s[i] == '?') ++cntS;
	}
	for(int i = 1; i <= lent; ++i) {
		if(t[i] == 'A') --cA;
		if(t[i] == 'B') --cB;
		if(t[i] == '?') ++cntT;
	}
	for(int dt = -cntT, coef, A, B, d; dt <= cntS; ++dt) {
		coef = C(cntS + cntT, dt + cntT);
		A = cA + dt, B = cB + cntS - cntT - dt;
		if(!A && !B) (Ans += coef * tot) %= mod;
		if(A * B < 0) {
			A = abs(A), B = abs(B);
			d = n / (max(A, B) / __gcd(A, B));
			(Ans += coef * (p2[d + 1] - 2)) %= mod;
		}
	}
	if(lens == lent) {
		bool same = true; int c = 0;
		for(int i = 1; i <= lens; ++i) {
			if(s[i] != '?' && t[i] != '?' && s[i] != t[i]) same = false;
			else if(s[i] == '?' && t[i] == '?') ++c;
		}
		if(same) (Ans += p2[c] * ((p2[n + 1] - 2) * (p2[n + 1] - 2) % mod - tot)) %= mod;
	}
	Ans = (Ans + mod) % mod;
	printf("%lld\n", Ans);
	return 0;
}