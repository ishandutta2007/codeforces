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

const int maxn = 100;
int a[maxn];
int b[maxn];
ll f[maxn][2][2][2][2];

ll calc(int pos, int cnt, bool positive, bool flaga, bool flagb) {
	if (pos == 63) {
		return cnt == 1;
	}
	ll& res = f[pos][cnt][positive][flaga][flagb];
	if (~res) return res;
	res = 0;
	int lo = 0, hi = 1;
	if (!flaga) lo = max(lo, a[pos]);
	if (!flagb) hi = min(hi, b[pos]);
	FOR(i, lo, hi + 1) {
		int t = cnt;
		if (positive && !i) t++;
		if (t <= 1) {
			res += calc(pos + 1, t, positive | i > 0, flaga | i > a[pos], flagb | i < b[pos]);
		}
	}
	return res;
}

void solve() {
	ms(f, -1);
	ll A, B; scanf("%I64d%I64d", &A, &B);
	FOR(i, 0, 63) {
		if (bit(A, 62 - i)) a[i] = 1;
		if (bit(B, 62 - i)) b[i] = 1;
	}
	printf("%I64d", calc(0, 0, 0, 0, 0));
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