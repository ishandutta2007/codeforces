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

const int maxn = 200000 + 10;
int n, m;
int a[maxn];

int compare(int i, int j) {
	if (a[i] != a[j]) return a[i] > a[j];
	return i < j;
}

void solve() {
	cin >> n >> m;
	FOR(i, 0, n) cin >> a[i];
	vi v; FOR(i, 0, n) v.pb(i);
	sort(all(v), compare);
	map<int, int> hs;
	int cnt[2] = {};
	vi change;
	FOR(j, 0, n) {
		int i = v[j];
		int pt = a[i] & 1;
		if (cnt[pt] == n / 2) {
			change.pb(i);
		}
		else {
			if (!hs.count(a[i])) {
				hs[a[i]] = 1;
				cnt[pt]++;
			}
			else {
				change.pb(i);
			}
		}
	}
	int ptr1 = 1, ptr2 = 2;
	FOR(j, 0, sz(change)) {
		int i = change[j];
		if (cnt[0] < n / 2) {
			while (hs.count(ptr2)) ptr2 += 2;
			if (ptr2 > m) {
				cout << -1 << "\n";
				return;
			}
			a[i] = ptr2;
			hs[ptr2] = 1;
			cnt[0]++;
		}
		else if (cnt[1] < n / 2) {
			while (hs.count(ptr1)) ptr1 += 2;
			if (ptr1 > m) {
				cout << -1 << "\n";
				return;
			}
			a[i] = ptr1;
			hs[ptr1] = 1;
			cnt[1]++;
		}
	}
	cout << sz(change) << "\n";
	FOR(i, 0, n) cout << a[i] << " \n"[i == n - 1];
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