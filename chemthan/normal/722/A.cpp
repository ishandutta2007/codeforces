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

int valid12(string a, string b) {
	stringstream ss1(a), ss2(b);
	int x, y; ss1 >> x, ss2 >> y;
	if (x < 1 || x > 12) return 0;
	if (y < 0 || y > 59) return 0;
	return 1;
}
int valid24(string a, string b) {
	stringstream ss1(a), ss2(b);
	int x, y; ss1 >> x, ss2 >> y;
	if (x < 0 || x > 23) return 0;
	if (y < 0 || y > 59) return 0;
	return 1;
}

void solve() {
	int op; cin >> op;
	string s; cin >> s;
	FOR(i, 0, sz(s)) {
		if (s[i] == ':') {
			s[i] = ' ';
		}
	}
	stringstream ss(s);
	string a, b; ss >> a >> b;
	pair<int, string> ans = mp(INF, "");
	FOR(it1, '0', '9' + 1)
	FOR(it2, '0', '9' + 1)
	FOR(it3, '0', '9' + 1)
	FOR(it4, '0', '9' + 1) {
		string aa = a, bb = b;
		int tot = 0;
		tot += aa[0] != it1;
		tot += aa[1] != it2;
		tot += bb[0] != it3;
		tot += bb[1] != it4;
		aa[0] = it1, aa[1] = it2;
		bb[0] = it3, bb[1] = it4;
		if (op == 12) {
			if (valid12(aa, bb)) {
				chkmin(ans, mp(tot, aa + ":" + bb));
			}
		}
		else {
			if (valid24(aa, bb)) {
				chkmin(ans, mp(tot, aa + ":" + bb));
			}
		}
	}
	cout << ans.se << "\n";
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