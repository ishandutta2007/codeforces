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
#define bit(n, i) ((n) & (1LL << (i)))
#define bitcount(n) __builtin_popcount(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = (int) 1e9 + 7) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

const int maxn = 21;
int n;
ll s;
ll a[maxn];
int rev[maxn];

int binomial(int a, ll b) {
	if (a > b) return 0;
	if (a == 0 || a == b) return 1;
	int res = 1;
	FOR(i, 1, a + 1) {
		res = (ll) res * ((b - i + 1) % MOD) % MOD;
		res = (ll) res * rev[i] % MOD;
	}
	return res;
}

void solve() {
	FOR(i, 1, maxn) rev[i] = fpow(i, MOD - 2);
	scanf("%d%I64d", &n, &s);
	FOR(i, 0, n) scanf("%I64d", a + i);
	int ans = 0;
	FOR(i, 0, 1 << n) {
		int sig = 1;
		ll tot = s;
		FOR(j, 0, n) if (bit(i, j)) {
			sig *= -1;
			tot -= a[j] + 1;
		}
		ans = ((ll) ans + sig * binomial(n - 1, tot + n - 1) + MOD) % MOD;
	}
	printf("%d", ans);
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}