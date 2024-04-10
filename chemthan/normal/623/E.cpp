#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) ((n) & (1LL << (i)))
#define bitcount(n) __builtin_popcount(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}

int add(int a, int b, int p = (int) 1e9 + 7) {return a + b - (a + b >= p) * p;}
int sub(int a, int b, int p = (int) 1e9 + 7) {return a - b + (a - b < 0) * p;}
int mul(int a, int b, int p = (int) 1e9 + 7) {return ((long long) a * b) % p;}
int inv(int a, int p = (int) 1e9 + 7) {return fpow(a, p - 2, p);}
const int PRIME[3] = {1004535809, 1007681537, 1012924417}; //2 ^ 20 * {958, 961, 966}
const int gen[3] = {3, 3, 5}; //primitive roots
const int MAXN = 1 << 20;
int fa[MAXN];
int fb[MAXN];
int fd[3][MAXN];
int prv[MAXN];
int nxt[MAXN];
int roots[MAXN];
void fft(int a[], int k, int w, int p) {
	for (int i = 0; i < (1 << k); i++) prv[i] = nxt[i] = roots[i] = 0;
	int high = -1;
	for (int i = 1; i < (1 << k); i++) {
		if (!(i & (i - 1))) high++;
		prv[i] = prv[i ^ (1 << high)];
		prv[i] |= (1 << (k - 1 - high));
	}
	for (int i = 0; i < (1 << k); i++) prv[i] = a[prv[i]];
	roots[0] = 1;
	for (int i = 1; i < (1 << k); i++) roots[i] = mul(roots[i - 1], w, p);
	for (int len = 1; len < (1 << k); len <<= 1) {
		int rstep = (1 << k) / (len << 1);
		for (int pdest = 0; pdest < (1 << k); ) {
			int p1 = pdest;
			for (int i = 0; i < len; i++) {
				int val = mul(roots[i * rstep], prv[p1 + len], p);
				nxt[pdest] = add(prv[p1], val, p);
				nxt[pdest + len] = sub(prv[p1], val, p);
				pdest++;
				p1++;
			}
			pdest += len;
		}
		for (int i = 0; i < (1 << k); i++) swap(prv[i], nxt[i]);
	}
	for (int i = 0; i < (1 << k); i++) a[i] = prv[i];
}
void multiply(int a[], int b[], int c[], int na, int nb, int mod = (int) 1e9 + 7) {
	int len = na + nb - 1;
	int k = 0; while ((1 << k) <= 2 * max(na, nb)) k++;
	for (int r = 0; r < 3; r++) {
		for (int i = 0; i < (1 << k); i++) fa[i] = fb[i] = 0;
		for (int i = 0; i < na; i++) fa[i] = a[i];
		for (int i = 0; i < nb; i++) fb[i] = b[i];
		int p = PRIME[r];
		int w = fpow(gen[r], (p - 1) / (1 << k), p);
		fft(fa, k, w, p);
		fft(fb, k, w, p);
		for (int i = 0; i < (1 << k); i++) fd[r][i] = mul(fa[i], fb[i], p);
		fft(fd[r], k, inv(w, p), p);
		int rem = inv(1 << k, p);
		for (int i = 0; i < (1 << k); i++) {
			fd[r][i] = mul(fd[r][i], rem, p);
		}
	}
	for (int i = 0; i < len; i++) {
		long long cur = (long long) mul(sub(fd[1][i], fd[0][i], PRIME[1]), inv(PRIME[0], PRIME[1]), PRIME[1]) * PRIME[0] + fd[0][i];
		long long cur2 = mul(sub(fd[2][i], cur % PRIME[2], PRIME[2]), inv(mul(PRIME[0], PRIME[1], PRIME[2]), PRIME[2]), PRIME[2]);
		cur2 = add(mul(cur2 % mod, mul(PRIME[0], PRIME[1], mod), mod), cur % mod, mod);
		c[i] = cur2;
	}
}

const int maxn = 1 << 16;
ll n;
int k;
int a[maxn];
int b[maxn];
int c[maxn << 1];
int d[maxn];
int fac[maxn];
int rfac[maxn];

int binomial(int a, int b) {
	if (!a || a == b) return 1;
	if (a > b) return 0;
	return (ll) fac[b] * rfac[a] % MOD * rfac[b - a] % MOD;
}

void go(ll n) {
	if (n == 1) {
		FOR(i, 1, k + 1) a[i] = 1;
		return;
	}
	if (!(n & 1)) {
		go(n >> 1);
		int d = 0;
		FOR(i, 1, k + 1) {
			b[i] = (ll) a[i] * rfac[i] % MOD * fpow(2, (ll) i * (n >> 1)) % MOD;
		}
		FOR(i, 1, k + 1) {
			a[i] = (ll) a[i] * rfac[i] % MOD;
		}
		multiply(a, b, c, k + 1, k + 1);
		FOR(i, 1, k + 1) a[i] = (ll) c[i] * fac[i] % MOD;
	}
	else {
		go(n - 1);
		FOR(i, 1, k + 1) {
			b[i] = (ll) rfac[i] * fpow(2, (ll) i * (n - 1)) % MOD;
		}
		FOR(i, 1, k + 1) {
			a[i] = (ll) a[i] * rfac[i] % MOD;
		}
		multiply(a, b, c, k + 1, k + 1);
		FOR(i, 1, k + 1) a[i] = (ll) c[i] * fac[i] % MOD;
	}
}

void solve() {
	fac[0] = rfac[0] = 1;
	FOR(i, 1, maxn) {
		fac[i] = (ll) fac[i - 1] * i % MOD;
		rfac[i] = fpow(fac[i], MOD - 2);
	}
	cin>>n>>k;
	if (n > k) {
		cout<<0;
		return;
	}
	go(n);
	int ans = 0;
	FOR(i, 1, k + 1) {
		addmod(ans, (ll) a[i] * binomial(i, k) % MOD);
	}
	cout<<ans;
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}