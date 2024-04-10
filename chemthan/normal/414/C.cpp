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

const int maxn = 21;
int n, q;
int a[1 << maxn];
int b[1 << maxn];
ll p2[maxn];
ll f[maxn];
ll g[maxn];
ll h[maxn];
int tmp[1 << maxn];

void merge(int l, int r, int k) {
	if (l == r) return;
	int m = l + r >> 1;
	merge(l, m, k - 1); merge(m + 1, r, k - 1);
	int idx = m;
	FOR(i, l, m + 1) {
		while (idx < r && a[idx + 1] < a[i]) idx++;
		f[k] += idx - m;
	}
	idx = r + 1;
	FORd(i, m + 1, l) {
		while (idx > m + 1 && a[idx - 1] > a[i]) idx--;
		g[k] += r - idx + 1;
	}
	int cnt = 0, cur1 = l, cur2 = m + 1;
	while (cur1 <= m || cur2 <= r) {
		if (cur1 > m) {
			tmp[cnt++] = a[cur2++];
		}
		else if (cur2 > r) {
			tmp[cnt++] = a[cur1++];
		}
		else if (a[cur1] < a[cur2]) {
			tmp[cnt++] = a[cur1++];
		}
		else {
			tmp[cnt++] = a[cur2++];
		}
	}
	FOR(i, l, r + 1) a[i] = tmp[i - l];
}

void solve() {
	p2[0] = 1; FOR(i, 1, maxn) p2[i] = p2[i - 1] << 1;
	scanf("%d", &n);
	FOR(i, 0, 1 << n) scanf("%d", a + i), b[i] = a[i];
	merge(0, (1 << n) - 1, n);
	FOR(i, 1, n + 1) f[i] += f[i - 1], g[i] += g[i - 1];
	FOR(i, 0, n + 1) h[i] = f[i] + g[i];
	scanf("%d", &q);
	while (q--) {
		int k; scanf("%d", &k);
		ll z;
		FOR(i, 0, k + 1) {
			if (i == k) {
				z = h[i] - 2 * f[i];
			}
			f[i] = h[i] - f[i];
		}
		FOR(i, k + 1, n + 1) {
			f[i] += z;
		}
		cout<<f[n]<<"\n";
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