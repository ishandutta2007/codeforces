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

const int maxn = 10;
int n;
int l[maxn];
int r[maxn];
ld f[10010];

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%d%d", l + i, r + i);
	FOR(k, 1, 10001) {
		FOR(u, 1, 1 << n) if (bitcount(u) > 1) {
			ld tot = 1.0;
			FOR(i, 0, n) {
				if (bit(u, i)) {
					if (l[i] > k || r[i] < k) tot = 0;
					else {
						tot /= r[i] - l[i] + 1;
					}
				}
				else {
					if (l[i] >= k) tot = 0;
					else if (r[i] >= k) {
						tot *= (ld) (k - l[i]) / (r[i] - l[i] + 1);
					}
				}
			}
			f[k] += tot;
		}
		FOR(u, 1, 1 << n) if (bitcount(u) == 1) FOR(v, 1, 1 << n) {
			if (!(u & v)) {
				int lmax = 0, rmin = INF;
				ld tot = 1.0;
				FOR(i, 0, n) {
					if (bit(u, i)) {
						lmax = max(lmax, l[i]);
						rmin = min(rmin, r[i]);
					}
					else if (bit(v, i)) {
						if (l[i] > k || r[i] < k) tot = 0;
						else {
							tot /= r[i] - l[i] + 1;
						}
					}
					else {
						if (l[i] >= k) tot = 0;
						else if (r[i] >= k) {
							tot *= (ld) (k - l[i]) / (r[i] - l[i] + 1);
						}
					}
				}
				if (rmin < lmax || rmin <= k) tot = 0;
				else {
					int d = max(k + 1, lmax);
					FOR(i, 0, n) if (bit(u, i)) {
						tot /= r[i] - l[i] + 1;
					}
					tot *= rmin - d + 1;
				}
				f[k] += tot;
			}
		}
	}
	ld ans = 0;
	FOR(k, 1, 10001) ans += f[k] * k;
	cout<<prec(9)<<ans;
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