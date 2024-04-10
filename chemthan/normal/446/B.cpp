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

const int maxn = 1010;
int n, m, k, p;
int a[maxn][maxn];
ll row[maxn];
ll col[maxn];
ll u[maxn * maxn];
ll v[maxn * maxn];

void solve() {
	scanf("%d%d%d%d", &n, &m, &k, &p);
	FOR(i, 0, n) FOR(j, 0, m) {
		scanf("%d", &a[i][j]);
		row[i] += a[i][j];
		col[j] += a[i][j];
	}
	priority_queue<ll> pq;
	FOR(i, 0, n) pq.push(row[i]);
	FOR(i, 1, k + 1) {
		ll d = pq.top();
		pq.pop();
		u[i] = u[i - 1] + d;
		pq.push(d - p * m);
	}
	while (sz(pq)) pq.pop();
	FOR(i, 0, m) pq.push(col[i]);
	FOR(i, 1, k + 1) {
		ll d = pq.top();
		pq.pop();
		v[i] = v[i - 1] + d;
		pq.push(d - p * n);
	}
	ll ans = -LINF;
	FOR(i, 0, k + 1) ans = max(ans, u[i] + v[k - i] - (ll) i * (k - i) * p);
	printf("%I64d", ans);
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