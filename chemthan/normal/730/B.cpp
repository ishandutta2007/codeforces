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

string ask(int i, int j) {
	cout << "? " << i + 1 << " " << j + 1 << "\n";
	cout.flush();
	string res; cin >> res;
	return res;
}

void solve() {
	int test; cin >> test;
	while (test--) {
		int n; cin >> n;
		vi mn, mx;
		for (int i = 0; i + 1 < n; i += 2) {
			string res = ask(i, i + 1);
			if (res == "<" || res == "=") {
				mn.pb(i), mx.pb(i + 1);
			}
			else {
				mn.pb(i + 1), mx.pb(i);
			}
		}
		if (n & 1) {
			mn.pb(n - 1), mx.pb(n - 1);
		}
		while (sz(mn) > 1) {
			vi nmn;
			for (int i = 0; i + 1 < sz(mn); i += 2) {
				string res = ask(mn[i], mn[i + 1]);
				if (res == "<" || res == "=") {
					nmn.pb(mn[i]);
				}
				else {
					nmn.pb(mn[i + 1]);
				}
			}
			if (sz(mn) & 1) {
				nmn.pb(mn.back());
			}
			mn = nmn;
		}
		while (sz(mx) > 1) {
			vi nmx;
			for (int i = 0; i + 1 < sz(mx); i += 2) {
				string res = ask(mx[i], mx[i + 1]);
				if (res == ">" || res == "=") {
					nmx.pb(mx[i]);
				}
				else {
					nmx.pb(mx[i + 1]);
				}
			}
			if (sz(mx) & 1) {
				nmx.pb(mx.back());
			}
			mx = nmx;
		}
		cout << "! " << mn[0] + 1 << " " << mx[0] + 1 << "\n";
		cout.flush();
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