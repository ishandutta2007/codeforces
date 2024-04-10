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
template<class T> inline int chkmin(T& a, const T& val) {return a > val ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int maxn = 200010;
int n, k;
int t[maxn];
ld s[maxn];
ld x[maxn];
ld y[maxn];
ld f[2][maxn];
int que[maxn];
int cnt;

ld ff(int j, int k) {
	return (s[k] + f[cnt][k + 1] - s[j] - f[cnt][j + 1]) / (y[k] - y[j]);
}

int worse1(int i, int j, int k) {
	return x[i - 1] < ff(j, k);
}

int worse2(int i, int j, int k) {
	return ff(j, i) < ff(k, j);
}

void solve() {
	scanf("%d%d", &n, &k);
	FOR(i, 1, n + 1) {
		double z; scanf("%lf", &z);
		t[i] = z;
		x[i] = x[i - 1] + t[i];
		y[i] = y[i - 1] + 1.0 / t[i];
		s[i] = s[i - 1] + x[i] / t[i];
	}
	fill_n(f[cnt], n + 2, -1); f[cnt][n + 1] = 0;
	while (k--) {
		fill_n(f[cnt ^ 1], n + 2, -1);
		int qh = 0, qe = 0;
		FORd(i, n + 1, 1) {
			if (f[cnt][i + 1] != -1) {
				while (qh <= qe - 2 && worse2(que[qe - 2], que[qe - 1], i)) qe--;
				que[qe++] = i;
			}
			while (qh <= qe - 2 && worse1(i, que[qh + 1], que[qh])) qh++;
			if (qh < qe) {
				int idx = que[qh];
				if (f[cnt][idx + 1] != -1) {
					f[cnt ^ 1][i] = x[i - 1] * y[i - 1] - s[i - 1] + s[idx] + f[cnt][idx + 1] - x[i - 1] * y[idx];
				}
			}
		}
		cnt ^= 1;
	}
	printf("%0.9lf\n", (double) f[cnt][1]);
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