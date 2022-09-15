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

const int maxn = 2010;
int n, m;
ll a[maxn];
ll b[maxn];
ll suma, sumb;

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n) {
		scanf("%I64d", a + i);
		suma += a[i];
	}
	scanf("%d", &m);
	FOR(i, 0, m) {
		scanf("%I64d", b + i);
		sumb += b[i];
	}
	vector<pair<ll, pi> > v;
	FOR(i, 0, n) FOR(j, i + 1, n) {
		v.pb(mp(2 * (a[i] + a[j]), mp(i, j)));
	}
	sort(all(v));
	ll ans = abs(sumb - suma), dif = sumb - suma;
	vii res;
	FOR(i, 0, m) FOR(j, i + 1, m) {
		ll d = 2 * (b[i] + b[j]);
		int k = lower_bound(all(v), mp(d - dif, mp(-INF, -INF))) - v.begin();
		if (k < sz(v)) {
			if (ans > v[k].fi - d + dif) {
				ans = v[k].fi - d + dif;
				res.clear();
				res.pb(mp(v[k].se.fi, i));
				res.pb(mp(v[k].se.se, j));
			}
		}
		if (k) {
			k--;
			if (ans > d - dif - v[k].fi) {
				ans = d - dif - v[k].fi;
				res.clear();
				res.pb(mp(v[k].se.fi, i));
				res.pb(mp(v[k].se.se, j));
			}
		}
	}
	FOR(i, 0, n) FOR(j, 0, m) {
		if (ans > abs(dif - 2 * (b[j] - a[i]))) {
			ans = abs(dif - 2 * (b[j] - a[i]));
			res.clear();
			res.pb(mp(i, j));
		}
	}
	printf("%I64d\n", ans);
	printf("%d\n", sz(res));
	FOR(i, 0, sz(res)) printf("%d %d\n", res[i].fi + 1, res[i].se + 1);
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