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
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
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
const ld PI = 2 * acos((ld) 0);

int p, k;

int exp(int n, int k, int mod) {
	if (!k) return 1;
	if (k & 1) return 1LL * n * exp(n, k - 1, mod) % mod;
	int t = exp(n, k >> 1, mod);
	return 1LL * t * t % mod;
}

void solve() {
	scanf("%d%d", &p, &k);
	if (!k) {
		printf("%d", exp(p, p - 1, MOD));
		return;
	}
	int ord = p - 1;
	FOR(i, 1, p) if ((p - 1) % i == 0) {
		if (exp(k, i, p) == 1) {
			ord = i;
			break;
		}
	}
	int ans = exp(p, (p - 1) / ord, MOD);
	if (k == 1) ans = 1LL * ans * p % MOD;
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