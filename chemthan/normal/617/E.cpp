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
const int K = 317;
int n, m, k;
int a[maxn];
int xsum[maxn];
int rsum[maxn];
ll f[100 * maxn];
ll g[100 * maxn];
vector<pair<pi, int> > query;
ll ans[maxn];

int compare(pair<pi, int> a, pair<pi, int> b) {
	if (a.fi.fi / K != b.fi.fi / K) return a.fi.fi / K < b.fi.fi / K;
	return a.fi.se < b.fi.se;
}

void solve() {
	scanf("%d%d%d", &n, &m, &k);
	FOR(i, 0, n) {
		scanf("%d", a + i);
		if (!i) xsum[i] = a[i];
		else xsum[i] = xsum[i - 1] ^ a[i];
	}
	FORd(i, n, 0) {
		rsum[i] = rsum[i + 1] ^ a[i];
	}
	FOR(i, 0, m) {
		int l, r;
		scanf("%d%d", &l, &r); l--; r--;
		query.pb(mp(mp(l, r), i));
	}
	sort(all(query), compare);
	ll tot = 0;
	FOR(i, 0, sz(query)) {
		int l = query[i].fi.fi;
		int r = query[i].fi.se;
		int idx = query[i].se;
		if (!i) {
			FOR(i, l, r + 1) {
				if (i) f[xsum[i - 1]]++; else f[0]++;
				g[rsum[i + 1]]++;
				tot += f[xsum[i] ^ k];
			}
		}
		else {
			int ll = query[i - 1].fi.fi;
			int rr = query[i - 1].fi.se;
			if (r > rr) {
				FOR(i, rr + 1, r + 1) {
					if (i) f[xsum[i - 1]]++; else f[0]++;
					g[rsum[i + 1]]++;
					tot += f[xsum[i] ^ k];
				}
			}
			else {
				FORd(i, rr + 1, r + 1) {
					tot -= f[xsum[i] ^ k];
					if (i) f[xsum[i - 1]]--; else f[0]--;
					g[rsum[i + 1]]--;
				}
			}
			if (l < ll) {
				FORd(i, ll, l) {
					if (i) f[xsum[i - 1]]++; else f[0]++;
					g[rsum[i + 1]]++;
					tot += g[rsum[i] ^ k];
				}
			}
			else {
				FOR(i, ll, l) {
					tot -= g[rsum[i] ^ k];
					if (i) f[xsum[i - 1]]--; else f[0]--;
					g[rsum[i + 1]]--;
				}
			}
		}
		ans[idx] = tot;
	}
	FOR(i, 0, m) printf("%I64d\n", ans[i]);
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