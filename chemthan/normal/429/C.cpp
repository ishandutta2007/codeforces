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

const int maxn = 30;
int n, nleaf;
int d[maxn];
int f[maxn][1 << 11][maxn];
vi submsk[1 << 11];
int sum[1 << 11];

int compare(int a, int b) {
	return a > b;
}

int calc(int pos, int msk, int a) {
	if (pos == n - nleaf) {
		return !msk && !a;
	}
	if (bit(msk, pos)) {
		return 0;
	}
	int& res = f[pos][msk][a];
	if (~res) return res;
	res = 0;
	FOR(i, 0, sz(submsk[msk])) {
		int nxt = submsk[msk][i];
		if (d[pos] - 1 >= sum[nxt] && d[pos] - 1 <= sum[nxt] + a && bitcount(nxt) + d[pos] - 1 - sum[nxt] > 1) {
			res |= calc(pos + 1, msk ^ nxt, sum[nxt] + a - d[pos] + 1);
		}
	}
	return res;
}

void solve() {
	FOR(i, 0, 1 << 11) FOR(j, 0, 1 << 11) {
		if ((i & j) == j) {
			submsk[i].pb(j);
		}
	}
	cin>>n;
	FOR(i, 0, n) cin>>d[i], nleaf += d[i] == 1;
	sort(d, d + n, compare);
	FOR(i, 0, 1 << 11) {
		FOR(j, 0, 11) if (bit(i, j)) {
			sum[i] += d[j];
		}
	}
	if (n == 1) {
		if (d[0] == 1) {
			cout<<"YES\n";
		}
		else {
			cout<<"NO\n";
		}
		return;
	}
	if (nleaf < (n + 1) / 2 || nleaf == n) {
		cout<<"NO\n";
		return;
	}
	ms(f, -1);
	calc(0, (1 << (n - nleaf)) - 2, nleaf) ? cout<<"YES\n" : cout<<"NO\n";
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