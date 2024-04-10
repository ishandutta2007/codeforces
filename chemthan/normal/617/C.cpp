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
int n;
ll f1x, f1y, f2x, f2y;
ll x[maxn];
ll y[maxn];
ll d[maxn];

ll dst(ll x, ll y, ll z, ll t) {
	return (x - z) * (x - z) + (y - t) * (y - t);
}

void solve() {
	cin>>n>>f1x>>f1y>>f2x>>f2y;
	vector<pair<ll, ll> > vl;
	FOR(i, 0, n) {
		cin>>x[i]>>y[i];
		ll u = dst(f1x, f1y, x[i], y[i]);
		ll v = dst(f2x, f2y, x[i], y[i]);
		vl.pb(mp(u, v));
	}
	sort(all(vl));
	ll t = 0;
	FORd(i, sz(vl), 0) {
		t = max(t, vl[i].se);
		d[i] = t;
	}
	ll ans = d[0];
	FOR(i, 0, sz(vl)) {
		ans = min(ans, vl[i].fi + d[i + 1]);
	}
	cout<<ans;
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