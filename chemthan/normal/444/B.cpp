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
int n, d, x;
int a[maxn];
int b[maxn];

int next() {
    return x = (x * 37LL + 10007) % 1000000007;
}

void init() {
    FOR(i, 0, n) a[i] = i + 1;
    FOR(i, 0, n) swap(a[i], a[next() % (i + 1)]);
    FOR(i, 0, n) if (i < d) b[i] = 1; else b[i] = 0;
    FOR(i, 0, n) swap(b[i], b[next() % (i + 1)]);
}

void solve() {
	scanf("%d%d%d", &n, &d, &x);
	init();
	vi vb; FOR(i, 0, n) if (b[i]) vb.pb(i);
	vi va(n + 1); FOR(i, 0, n) va[a[i]] = i;
	FOR(i, 0, n) {
		int flag = 0;
		FOR(j, 0, min(n, 50)) {
			if (va[n - j] <= i && b[i - va[n - j]]) {
				printf("%d\n", n - j);
				flag = 1; break;
			}
		}
		if (flag) continue;
		int res = 0;
		FOR(j, 0, sz(vb)) {
			if (i < vb[j]) break;
			res = max(res, a[i - vb[j]]);
		}
		printf("%d\n", res);
	}
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