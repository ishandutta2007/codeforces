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
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int maxn = 200010;
int n;
int x[maxn];
ll sum[maxn];

ll calc(int l, int r) {
	if (l > r) return 0;
	if (!l) return sum[r];
	return sum[r] - sum[l - 1];
}

ld calc2(int i, int k) {
	return (ld) (calc(i - k, i - 1) + calc(n - k, n - 1) + x[i]) / (2 * k + 1);
}

ld calc3(int i, int k) {
	return (ld) (calc(i - k, i - 1) + calc(n - k, n - 1) + x[i] + x[i + 1]) / (2 * k + 2);
}

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%d", x + i);
	sort(x, x + n);
	FOR(i, 0, n) {
		if (!i) sum[i] = x[i];
		else sum[i] = sum[i - 1] + x[i];
	}
	vi ans;
	ld dmax = 0;
	FOR(i, 0, n) {
		int l = 0, r = min(i, n - i - 1);
		while (l < r) {
			int mid = (l + r) >> 1;
			if (calc2(i, mid) > calc2(i, mid + 1)) r = mid; else l = mid + 1;
		}
		if (dmax < calc2(i, l) - x[i]) {
			dmax = calc2(i, l) - x[i];
			ans.clear();
			ans.pb(i);
			ans.pb(l);
		}
	}
	FOR(i, 0, n - 1) {
		int l = 0, r = min(i, n - i - 2);
		while (l < r) {
			int mid = (l + r) >> 1;
			if (calc3(i, mid) > calc3(i, mid + 1)) r = mid; else l = mid + 1;
		}
		if (dmax < calc3(i, l) - (x[i] + x[i + 1]) / 2.0) {
			dmax = calc3(i, l) - (x[i] + x[i + 1]) / 2.0;
			ans.clear();
			ans.pb(i);
			ans.pb(l);
			ans.pb(0);
		}
	}
	vi res;
	if (sz(ans) == 2) {
		int idx = ans[0];
		int k = ans[1];
		FOR(i, idx - k, idx) res.pb(x[i]);
		FOR(i, n - k, n) res.pb(x[i]);
		res.pb(x[idx]);
	}
	else if (sz(ans)) {
		int idx = ans[0];
		int k = ans[1];
		FOR(i, idx - k, idx) res.pb(x[i]);
		FOR(i, n - k, n) res.pb(x[i]);
		res.pb(x[idx]);
		res.pb(x[idx + 1]);
	}
	else {
		res.pb(x[0]);
	}
	printf("%d\n", sz(res));
	FOR(i, 0, sz(res)) printf("%d ", res[i]);
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