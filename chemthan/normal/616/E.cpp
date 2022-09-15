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

void solve() {
	ll n, m; scanf("%I64d%I64d", &n, &m);
	ll l = 0, r = INF;
	while (l < r) {
		ll mid = (l + r) >> 1;
		if (mid * mid < n) l = mid + 1; else r = mid;
	}
	ll d = l;
	ll ans = 0;
	FOR(i, 1, d + 1) {
		l = n / (i + 1) + 1;
		r = min(n / i, m);
		if (l > r) continue;
		ll t;
		if ((l + r) % 2 == 0) {
			t = (l + r) / 2 % MOD;
			t = t * ((r - l + 1) % MOD) % MOD;
			ans = (ans + t * i) % MOD;
		}
		else {
			t = (r - l + 1) / 2 % MOD;
			t = t * ((l + r) % MOD) % MOD;
			ans = (ans + t * i) % MOD;
		}
	}
	FOR(i, 1, min(m, d) + 1) {
		if (n / i > d) {
			ans = (ans + n / i % MOD * i) % MOD;
		}
	}
	ans = (n % MOD * (m % MOD) - ans + MOD) % MOD;
	printf("%I64d", ans);
}

int main() {
//  ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
    solve();
#ifdef _LOCAL_
    //printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}