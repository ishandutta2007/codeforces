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

const int maxn = 1000010;
const int maxq = 60;
const int maxe = 20;
int n, q;
int a[maxn << 1];
ll b[maxn];
ll sum[maxn << 1];
int nxt[maxn << 1];

ll calc(int l, int r) {
	if (!l) return sum[r];
	return sum[r] - sum[l - 1];
}

void solve() {
	scanf("%d%d", &n, &q);
	FOR(i, 0, n) {
		scanf("%d", a + i);
		a[i + n] = a[i];
	}
	FOR(i, 0, q) scanf("%I64d", b + i);
	FOR(i, 0, n << 1) {
		if (!i) sum[i] = a[i];
		else sum[i] = sum[i - 1] + a[i];
	}
	FOR(k, 0, q) {
		int cur = 0;
		FOR(i, 0, n << 1) {
			while (cur < i || cur < (n << 1) - 1 && calc(i, cur + 1) <= b[k]) cur++;
			nxt[i] = cur + 1;
		}
		int idx = 0, dmin = INF;
		FOR(i, 0, n) {
			if (dmin > nxt[i] - i) {
				dmin = nxt[i] - i;
				idx = i;
			}
		}
		int res = INF;
		FOR(i, idx, min(n, nxt[idx] + 1)) {
			int cur = i, tot = 0;
			while (cur < min(n << 1, i + n)) {
				cur = nxt[cur];
				tot++;
			}
			res = min(res, tot);
		}
		printf("%d\n", res);
	}
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