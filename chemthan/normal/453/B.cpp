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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll exp(ll n, ll k, int p = (int) 1e9 + 7) {if (!k) return 1; if (k & 1) return n * exp(n, k - 1, p) % p; int t = exp(n, k >> 1, p); return t * t % p;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

const int maxn = 110;
int n;
int a[maxn];
bool isprime[maxn];
vi prime;
int f[maxn][1 << 16];
int msk[maxn];
int rb[maxn][1 << 16];

int getmsk(int k) {
	int res = 0;
	FOR(i, 0, sz(prime)) if (k % prime[i] == 0) res |= 1 << i;
	return res;
}

void trace(int i, int d) {
	if (i == n) return;
	int k = rb[i][d];
	printf("%d ", k);
	trace(i + 1, d ^ msk[k]);
}

void solve() {
	ms(isprime, 1); FOR(i, 2, maxn) if (isprime[i]) {prime.pb(i); for (int j = i * i; j < maxn; j += i) isprime[j] = 0;}
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%d", a + i);
	FOR(i, 1, maxn) msk[i] = getmsk(i);
	ms(f, 0x3f); FOR(i, 0, 1 << 16) f[n][i] = 0;
	FORd(i, n, 0) FOR(j, 0, 1 << 16) {
		FOR(k, 1, 60) {
			int r = msk[k];
			if ((j & r) == r) {
				int t = f[i + 1][j ^ r] + abs(a[i] - k);
				if (f[i][j] > t) {
					f[i][j] = t;
					rb[i][j] = k;
				}
			}
		}
	}
	trace(0, (1 << 16) - 1);
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