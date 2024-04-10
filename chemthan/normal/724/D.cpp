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
template<class T> inline T isqrt(T k) {T r = sqrt(k) + 1; while (r * r > k) r--; return r;}
template<class T> inline T icbrt(T k) {T r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int maxn = 100000 + 10;
const int maxc = 26;
int n, m;
string s;
int lst[maxc];
int nxt[maxn][maxc];
int f[maxn];

pi st[maxn << 1];
void upd(int p, pi val) {
	for (st[p += n] = val; p > 1; ) p >>= 1, st[p] = min(st[p << 1], st[p << 1 | 1]);
}
pi query(int l, int r) {
	pi res = mp(INF, INF);
	for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
		if (l & 1) chkmin(res, st[l++]);
		if (r & 1) chkmin(res, st[--r]);
	}
	return res;
}

void solve() {
	cin >> m >> s;
	n = sz(s);
	FOR(i, 0, maxc) lst[i] = INF;
	FORd(i, n, 0) {
		lst[s[i] - 'a'] = i;
		FOR(j, 0, maxc) {
			nxt[i][j] = lst[j];
		}
		upd(i, mp(s[i] - 'a', -i));
	}
	int mx = -INF;
	vector<char> ans;
	FOR(i, 0, n - m + 1) {
		pi best = mp(INF, INF);
		FOR(j, 0, maxc) if (nxt[i][j] < i + m && j < mx) {
			chkmin(best, mp(nxt[i][j], j));
		}
		if (best.fi < INF) {
			ans.pb('a' + best.se);
			chkmax(mx, best.se);
			f[i = best.fi] = 1;
		}
		else {
			best = query(i, i + m - 1);
			ans.pb('a' + best.fi);
			chkmax(mx, best.fi);
			f[i = -best.se] = 1;
		}
	}
	FOR(i, 0, n) if (!f[i] && s[i] < 'a' + mx) {
		ans.pb(s[i]);
	}
	sort(all(ans));
	FOR(i, 0, sz(ans)) cout << ans[i];
	cout << "\n";
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