#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
#define db(x) cout << #x << " = " << (x) << "\n";

const int maxn = 7000 + 5;
int n, p[2];
int a[2][maxn];
int f[maxn];
int g[maxn];
int ff[maxn];
int gg[maxn];
int cnt[maxn];

void upd(int x) {
	FOR(i, 0, p[1]) {
		int nxt = (x + a[1][i]) % n;
		cnt[nxt]++;
	}
}

void work() {
	ms(f, 0), ms(g, 0), ms(cnt, 0);
	FOR(i, 0, p[0]) {
		f[a[0][i]] = 1;
		upd(a[0][i]);
	}
	while (1) {
		int found = 0;
		FOR(j, 1, n) if (!g[j] && cnt[j] == p[1]) {
			found = 1;
			g[j] = 1;
			FOR(k, 0, p[0]) {
				int nxt = (j + a[0][k]) % n;
				if (nxt && !f[nxt]) {
					f[nxt] = 1;
					upd(nxt);
				}
			}
		}
		if (!found) break;
	}
}

void solve() {
	cin >> n;
	cin >> p[0]; FOR(i, 0, p[0]) cin >> a[0][i];
	cin >> p[1]; FOR(i, 0, p[1]) cin >> a[1][i];
	work();
	FOR(i, 0, n) ff[i] = f[i], gg[i] = g[i];
	swap(p[0], p[1]);
	FOR(i, 0, n) swap(a[0][i], a[1][i]);
	work();
	for (int i = 1; i + i < n; i++) {
		swap(ff[i], ff[n - i]);
		swap(gg[i], gg[n - i]);
		swap(f[i], f[n - i]);
		swap(g[i], g[n - i]);
	}
	FOR(i, 1, n) {
		if (ff[i]) {
			cout << "Win";
		}
		else if (g[i]) {
			cout << "Lose";
		}
		else {
			cout << "Loop";
		}
		cout << " \n"[i == n - 1];
	}
	FOR(i, 1, n) {
		if (f[i]) {
			cout << "Win";
		}
		else if (gg[i]) {
			cout << "Lose";
		}
		else {
			cout << "Loop";
		}
		cout << " \n"[i == n - 1];
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}