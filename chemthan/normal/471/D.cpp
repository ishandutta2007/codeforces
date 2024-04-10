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

const int maxn = 200010;
int n, m;
int a[maxn];
int b[maxn];
int hash1[maxn];
int hash2[maxn];
int pw[maxn];
int rp[maxn];

int calc(int l, int r) {
	if (!l) return hash1[r];
	int res = (hash1[r] - hash1[l - 1] + MOD) % MOD;
	return (ll) res * rp[l] % MOD;
}

void solve() {
	pw[0] = 1; FOR(i, 1, maxn) pw[i] = (ll) 2311 * pw[i - 1] % MOD;
	rp[0] = 1; rp[1] = fpow(2311, MOD - 2); FOR(i, 2, maxn) rp[i] = (ll) rp[1] * rp[i - 1] % MOD;
	scanf("%d%d", &n, &m);
	int t = 0;
	FOR(i, 0, n) {
		scanf("%d", a + i);
		t = (t + (ll) pw[i] * a[i]) % MOD;
		hash1[i] = t;
	}
	t = 0;
	FOR(i, 0, m) {
		scanf("%d", b + i);
		t = (t + (ll) pw[i] * b[i]) % MOD;
		hash2[i] = t;
	}
	int ans = 0;
	FOR(i, 0, n - m + 1) {
		t = calc(i, i + m - 1);
		int r = (a[i] - b[0] + MOD) % MOD;
		t = (t - (ll) r * (fpow(2311, m) + MOD - 1) % MOD * fpow(2311 - 1, MOD - 2) % MOD + MOD) % MOD;
		if (t == hash2[m - 1]) ans++;
	}
	printf("%d", ans);
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