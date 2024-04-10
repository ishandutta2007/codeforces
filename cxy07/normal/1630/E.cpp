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

const int MAXN = 1e6 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m, g, up, dn, Ans;
int fac[MAXN], ifac[MAXN], a[MAXN], buk[MAXN];
int pr[MAXN], phi[MAXN], pcnt;
int s[MAXN];
bool np[MAXN];

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

void sieve(int siz) {
	phi[1] = 1;
	for(int i = 2; i <= siz; ++i) {
		if(!np[i]) pr[++pcnt] = i, phi[i] = i - 1;
		for(int j = 1; j <= pcnt && i * pr[j] <= siz; ++j) {
			np[i * pr[j]] = true;
			if(i % pr[j] == 0) { phi[i * pr[j]] = phi[i] * pr[j]; break; }
			phi[i * pr[j]] = phi[i] * phi[pr[j]];
		}
	}
}

int F(int d) {
	d = n / d; int res = 0, p = 1; 
	if(n / d <= 1) return 0;
	for(int i = 1; i <= m; ++i) p = p * ifac[s[i] / d] % mod;
	for(int i = 1; i <= m; ++i) {
		if((s[i] / d) <= 1) continue;
		(res += p % mod * fac[s[i] / d] % mod * ifac[s[i] / d - 2]) %= mod;
	}
	return res * n % mod * fac[n / d - 2] % mod;
}

int G(int d) { // d : number
	d = n / d; int res = fac[n / d];
	for(int i = 1; i <= m; ++i) res = res * ifac[s[i] / d] % mod;
	return res;
}

void solve() {
	read(n); g = m = up = dn = 0;
	for(int i = 1; i <= n; ++i) read(a[i]), buk[a[i]]++;
	for(int i = 1; i <= n; ++i) {
		if(!buk[i]) continue;
		s[++m] = buk[i], g = __gcd(g, buk[i]); buk[i] = 0;
	}
	if(m == 1) return puts("1"), void();
	for(int d = 1; d <= n; ++d) {
		if(n % d || g % (n / d)) continue;
		(up += F(d) * phi[n / d]) %= mod;
		(dn += G(d) * phi[n / d]) %= mod;
	}
	Ans = (n - up * inv(dn) % mod + mod) % mod;
	printf("%lld\n", Ans);
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(T); fac[0] = ifac[0] = 1; sieve(1e6);
	for(int i = 1; i < MAXN; ++i) fac[i] = fac[i - 1] * i % mod;
	ifac[MAXN - 1] = inv(fac[MAXN - 1]);
	for(int i = MAXN - 2; i; --i) ifac[i] = ifac[i + 1] * (i + 1) % mod;
	while(T--) solve();
	return 0;
}