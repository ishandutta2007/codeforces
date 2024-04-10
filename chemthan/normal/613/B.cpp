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

const int maxn = 100010;
ll n, A, cf, cm, m;
ll a[maxn];
ll sum[maxn];
vii v;

ll calc(int l, int r) {
	if (l > r) return 0;
	if (!l) return sum[r];
	return sum[r] - sum[l - 1];
}

int check(int k, int d, ll m) {
	int h = lower_bound(all(v), mp(d, -INF)) - v.begin();
	if (!h) return 1;
	h--; h = min(h, k);
	ll u = calc(0, h);
	if ((ll) d * (h + 1) - u > m) return 0;
	return 1;
}

void solve() {
	scanf("%I64d%I64d%I64d%I64d%I64d", &n, &A, &cf, &cm, &m);
	FOR(i, 0, n) {
		scanf("%I64d", a + i);
		v.pb(mp(a[i], i));
	}
	sort(all(v));
	FOR(i, 0, n) {
		if (!i) sum[i] = v[i].fi;
		else sum[i] = sum[i - 1] + v[i].fi;
	}
	if (A * n - calc(0, n - 1) <= m) {
		printf("%I64d\n", n * cf + A * cm);
		FOR(i, 0, n) printf("%d ", A);
		return;
	}
	ll ans = 0; pi res;
	FOR(i, 0, n) {
		ll d = A * i - calc(n - i, n - 1);
		if (d > m) continue;
		ll l = 0, r = INF << 1;
		while (l < r) {
			ll mid = (l + r + 1) >> 1;
			if (check(n - i - 1, mid, m - d)) l = mid; else r = mid - 1;
		}
		if (!check(n - i - 1, l, m - d)) continue;
		ll t = i * cf + l * cm;
		if (ans <= t) {
			ans = t;
			res = mp(i, l);
		}
	}
	printf("%I64d\n", ans);
	FOR(i, n - res.fi, n) v[i].fi = A;
	FOR(i, 0, n - res.fi) if (v[i].fi < res.se) v[i].fi = res.se;
	int anss[maxn];
	FOR(i, 0, n) anss[v[i].se] = v[i].fi;
	FOR(i, 0, n) printf("%d ", anss[i]);
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
    solve();
#ifdef _LOCAL_
    //printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}