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

pair<long long, long long> euclid(long long a, long long b) {
	if (b == 0) return make_pair(1, 0);
	pair<long long, long long> r = euclid(b, a % b);
	return make_pair(r.second, r.first - a / b * r.second);
}

long long inverse(long long a, long long m) {
	pair<long long, long long> r = euclid(a, m);
	return (r.fi % m + m) % m;
}

long long a[2], b[2];
long long l, r;

void solve() {
	FOR(i, 0, 2) cin >> a[i] >> b[i];
	cin >> l >> r;
	long long left = (max(l, max(b[0], b[1])) - b[1]) / a[1] - 10;
	while (a[1] * left + b[1] < max(l, max(b[0], b[1]))) left++;
	long long right = (r - b[1]) / a[1] + 10;
	while (a[1] * right + b[1] > r) right--;
	if (left > right) {
		cout << 0 << "\n";
		return;
	}
	long long g = __gcd(a[0], a[1]);
	if ((b[0] - b[1]) % g) {
		cout << 0 << "\n";
		return;
	}
	a[0] /= g, a[1] /= g;
	long long R = ((b[0] - b[1]) / g % a[0] + a[0]) % a[0];
	long long x = inverse(a[1], a[0]) * R % a[0];
	long long ll = (left - x) / a[0] - 10;
	while (ll * a[0] + x < left) ll++;
	long long rr = (right - x) / a[0] + 10;
	while (rr * a[0] + x > right) rr--;
	if (ll > rr) {
		cout << 0 << "\n";
		return;
	}
	cout << rr - ll + 1 << "\n";
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