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

const int maxn = 1000010;
int n, k;
int v[maxn];
int c[maxn];
int f[maxn];

void solve() {
	scanf("%d%d", &n, &k);
	FOR(i, 0, n) scanf("%d", v + i);
	FOR(i, 0, n) scanf("%d", c + i);
	multiset<int> st1, st2;
	int cur = 0;
	FOR(i, 0, n) {
		if (i) {
			st1.erase(st1.find(100 * v[i - 1]));
			st2.erase(st2.find(c[i - 1]));
		}
		while (cur <= i) {
			st1.insert(100 * v[cur]);
			st2.insert(c[cur]);
			cur++;
		}
		while (cur < n && max(*st1.rbegin(), 100 * v[cur]) <= min(*st2.begin(), c[cur])) {
			st1.insert(100 * v[cur]);
			st2.insert(c[cur]);
			cur++;
		}
		f[i] = min(*st1.rbegin(), *st2.begin());
		if (cur < n) {
			setmax(f[i], min(max(*st1.rbegin(), 100 * v[cur]), min(*st2.begin(), c[cur])));
		}
	}
	sort(f, f + n);
	ld ans = 0, t = (ld) k / n;
	FOR(i, 0, n - k + 1) {
		ans += t * f[i];
		t /= (ld) (n - i - 1) / (n - i - k);
	}
	cout<<prec(9)<<ans;
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