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

ll l, r;
int k;
int a[63];
int b[63];
int f[63][2][2][2][2][2][2][2][2][2];

void go(int pos, int g1, int l1, int g2, int l2, int g3, int l3, int d1, int d2, int d3, ll n1, ll n2, ll n3) {
	if (pos == 63) {
		if (d1 && d2 && d3) {
			printf("0\n3\n%I64d %I64d %I64d", n1, n2, n3);
			exit(0);
		}
		return;
	}
	if (f[pos][g1][l1][g2][l2][g3][l3][d1][d2][d3]) return;
	f[pos][g1][l1][g2][l2][g3][l3][d1][d2][d3] = 1;
	int lo1 = 0, hi1 = 1, lo2 = 0, hi2 = 1, lo3 = 0, hi3 = 1;
	if (!g1) lo1 = a[pos];
	if (!l1) hi1 = b[pos];
	if (!g2) lo2 = a[pos];
	if (!l2) hi2 = b[pos];
	if (!g3) lo3 = a[pos];
	if (!l3) hi3 = b[pos];
	FOR(i, lo1, hi1 + 1) FOR(j, lo2, hi2 + 1) FOR(k, lo3, hi3 + 1) {
		int _g1 = g1 | i > a[pos];
		int _l1 = l1 | i < b[pos];
		int _g2 = g2 | j > a[pos];
		int _l2 = l2 | j < b[pos];
		int _g3 = g3 | k > a[pos];
		int _l3 = l3 | k < b[pos];
		int _d1 = d1 | i != j;
		int _d2 = d2 | j != k;
		int _d3 = d3 | k != i;
		if ((i ^ j ^ k) == 0) go(pos + 1, _g1, _l1, _g2, _l2, _g3, _l3, _d1, _d2, _d3, (n1 << 1) ^ i, (n2 << 1) ^ j, (n3 << 1) ^ k);
	}
}

void solve() {
	scanf("%I64d%I64d%d", &l, &r, &k);
	FOR(i, 0, 63) {
		a[i] = bit(l, 62 - i) > 0;
		b[i] = bit(r, 62 - i) > 0;
	}
	if (l == r || k == 1) {
		printf("%I64d\n1\n%I64d", l, l);
	}
	else if (k == 2) {
		if (r - l == 1) {
			if ((l ^ r) < l) {
				printf("%I64d\n2\n%I64d %I64d", l ^ r, l, r);
			}
			else {
				printf("%I64d\n1\n%I64d", l, l);
			}
		}
		else {
			if (l & 1) l++;
			printf("1\n2\n%I64d %I64d", l, l + 1);
		}
	}
	else if (k == 3) {
		go(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
		if (r - l == 1) {
			printf("%I64d\n2\n%I64d %I64d", l ^ r, l, r);
		}
		else {
			if (l & 1) l++;
			printf("1\n2\n%I64d %I64d", l, l + 1);
		}
	}
	else {
		if (r - l <= 3) {
			int d = r - l + 1;
			ll dmin = LINF; vector<ll> ans;
			FOR(i, 0, 1 << d) {
				int tot = 0; ll xorsum = 0;
				FOR(j, 0, d) if (bit(i, j)) {
					tot++; xorsum ^= l + j;
				}
				if (tot && tot <= k && dmin > xorsum) {
					dmin = xorsum;
					ans.clear();
					FOR(j, 0, d) if (bit(i, j)) {
						ans.pb(l + j);
					}
				}
			}
			printf("%I64d\n%d\n", dmin, sz(ans));
			FOR(i, 0, sz(ans)) printf("%I64d ", ans[i]);
		}
		else {
			if (l & 1) l++;
			printf("0\n4\n");
			FOR(i, 0, 4) printf("%I64d ", l + i);
		}
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