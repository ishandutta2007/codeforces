#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

ll x;

void solve() {
	scanf("%I64d", &x); x *= 6;
	ll l = 0, r = (ll) 2e6;
	while (l < r) {
		ll m = (l + r + 1) >> 1;
		if (m * m * m <= x) l = m; else r = m - 1;
	}
	vector<pair<ll, ll> > ans, t;
	FOR(i, 1, l + 1) {
		if (x % (1LL * i * (i + 1)) == 0) {
			ll d = x / i / (i + 1);
			if ((d + i - 1) % 3 == 0 && (d + i - 1) / 3 >= i) {
				t.pb(mp(i, (d + i - 1) / 3));
			}
		}
	}
	ans = t; FOR(i, 0, sz(t)) ans.pb(mp(t[i].se, t[i].fi));
	sort(all(ans)); ans.erase(unique(all(ans)), ans.end());
	printf("%d\n", sz(ans));
	FOR(i, 0, sz(ans)) printf("%I64d %I64d\n", ans[i].fi, ans[i].se);
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