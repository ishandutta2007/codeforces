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
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a + val)) < 0) a += p;}

const int maxn = 1000010;
int n, x, y;
int a[maxn];
ll ans;

int checkprime(int k) {
	if (k < 2) return 0;
	for (ll i = 2; i * i <= k; i++) {
		if (k % i == 0) return 0;
	}
	return 1;
}

void go() {
	vi div;
	for (ll i = 2; i * i <= a[0]; i++) {
		if (a[0] % i == 0) {
			if (checkprime(i)) div.pb(i);
			int d = a[0] / i;
			if (d != i && checkprime(d)) div.pb(d);
		}
	}
	if (checkprime(a[0])) div.pb(a[0]);
	FOR(k, 0, sz(div)) {
		int p = div[k];
		ll tot = 0;
		vector<ll> vl;
		FOR(i, 0, n) {
			if (a[i] % p == 1) tot += y;
			else if (a[i] % p == p - 1) tot += y;
			else if (a[i] % p) break;
			vl.pb(tot);
			ans = min(ans, tot + (ll) (n - i - 1) * x);
		}
		tot = 0;
		vector<ll> vl2;
		FORd(i, n, 0) {
			if (a[i] % p == 1) tot += y;
			else if (a[i] % p == p - 1) tot += y;
			else if (a[i] % p) break;
			vl2.pb(tot);
		}
		reverse(all(vl2));
		int cur = 0;
		ll dmin = LINF;
		FOR(i, 0, sz(vl2)) {
			int idx = n - sz(vl2) + i;
			while (cur < idx && cur < sz(vl)) {
				dmin = min(dmin, vl[cur] - (ll) cur * x);
				cur++;
			}
			if (idx) ans = min(ans, dmin + vl2[i] + (ll) (idx - 1) * x);
			ans = min(ans, vl2[i] + (ll) idx * x);
		}
	}
}

ll res = LINF;

void abc() {
	ans = LINF; go();
	res = min(res, ans);
	a[0]--;
	ans = LINF; go();
	res = min(res, ans + y);
	a[0] += 2;
	ans = LINF; go();
	res = min(res, ans + y);
	a[0]--;
}

void solve() {
	scanf("%d%d%d", &n, &x, &y);
	FOR(i, 0, n) scanf("%d", a + i);
	abc();
	reverse(a, a + n);
	abc();
	printf("%I64d", res);
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