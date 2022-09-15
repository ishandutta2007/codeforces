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
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}

const int maxn = 110;
int n;
int p[maxn];
ld a[maxn];
ld f[1000000];

void solve() {
	cin>>n;
	FOR(i, 0, n) cin>>p[i];
	priority_queue<pair<pair<ld, ld>, int> > pq;
	FOR(i, 0, n) {
		a[i] = 1 - p[i] / ld(100);
		pq.push(mp(mp(a[i], p[i]), i));
	}
	FOR(i, 0, 300000) {
		f[n + i] = 1;
		FOR(j, 0, n) {
			f[n + i] *= 1 - a[j];
		}
		ld dmax = 0; int idx = 0;
		FOR(j, 0, n) {
			ld t = (1 - a[j] * (1 - p[j] / ld(100))) / (1 - a[j]);
			if (dmax < t) {
				dmax = t;
				idx = j;
			}
		}
		a[idx] *= 1 - p[idx] / ld(100);
	}
	ld ans = 0;
	FOR(i, n, n + 300000) {
		ans += (f[i] - f[i - 1]) * i;
	}
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