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
#define bit(n, i) (((n) >> (i)) & 1)
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
ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> void setmin(T& a, T val) {if (a > val) a = val;}
template<class T> void setmax(T& a, T val) {if (a < val) a = val;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

typedef double T;
const int MAXN = 1 << 20;
typedef complex<T> cplex;
cplex fa[MAXN << 1], fb[MAXN << 1];
void fft(cplex a[], int n, int invert) {
	for (int i = 1, j = 0; i < n; i++) {
		for (int s = n; j ^= s >>= 1, ~j & s;);
		if (i < j) swap(a[i], a[j]);
	}
	for (int m = 1; m < n; m <<= 1) {
		T p = PI / m * (invert ? -1 : 1);
		cplex w = cplex(cos(p), sin(p));
		for (int i = 0; i < n; i += m << 1) {
			cplex unit = 1;
			for (int j = 0; j < m; j++) {
				cplex &x = a[i + j + m], &y = a[i + j], t = unit * x;
				x = y - t;
				y = y + t;
				unit *= w;
			}
		}
	}
	if (invert) for (int i = 0; i < n; i++) a[i] /= n;
}
vi multiply(vi a, vi b) {
	int na = sz(a), nb = sz(b);
	int n = 1; while (n < na + nb) n <<= 1;
	for (int i = 0; i < n; i++) fa[i] = fb[i] = cplex(0);
	for (int i = 0; i < na; i++) fa[i] = cplex(a[i]);
	for (int i = 0; i < nb; i++) fb[i] = cplex(b[i]);
	fft(fa, n, 0); fft(fb, n, 0);
	for (int i = 0; i < n; i++) fa[i] *= fb[i];
	fft(fa, n, 1);
	vi res;
	for (int i = 0; i < na + nb - 1; i++) {
		long long t = (long long) (fa[i].real() + 0.5);
		res.pb(t > 0);
	}
	return res;
}

const int maxn = 1010;
int n, k;
vi va(maxn, 0);

vi calc(int d) {
	if (d == 1) {
		return va;
	}
	else if (d & 1) {
		return multiply(va, calc(d - 1));
	}
	else {
		vi r = calc(d >> 1);
		return multiply(r, r);
	}
}

void solve() {
	scanf("%d%d", &n, &k);
	FOR(i, 0, n) {
		int a; scanf("%d", &a);
		va[a] = 1;
	}
	vi res = calc(k);
	FOR(i, 0, sz(res)) {
		if (res[i]) {
			printf("%d ", i);
		}
	}
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