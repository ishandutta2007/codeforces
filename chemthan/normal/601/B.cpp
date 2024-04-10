#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
#define EPS 1e-7
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

const int maxn = 100010;
int n, q;
int a[maxn];
int d[maxn];
int l[maxn];
int r[maxn];

void solve() {
	scanf("%d%d", &n, &q);
	FOR(i, 0, n) scanf("%d", a + i);
	FOR(i, 0, n - 1) d[i] = abs(a[i + 1] - a[i]);
	FOR(i, 0, n - 1) l[i] = r[i] = i;
	FOR(i, 1, n - 1) {
		int cur = i;
		while (cur > 0 && d[cur - 1] <= d[i]) cur = l[cur - 1];
		l[i] = cur;
	}
	FORd(i, n - 2, 0) {
		int cur = i;
		while (cur < n - 2 && d[cur + 1] < d[i]) cur = r[cur + 1];
		r[i] = cur;
	}
	while (q--) {
		int x, y; scanf("%d%d", &x, &y); x--; y -= 2;
		ll ans = 0;
		FOR(i, x, y + 1) {
			int u = i - max(x, l[i]);
			int v = min(y, r[i]) - i;
			if (u >= 0 && v >= 0) ans += 1LL * d[i] * (u + 1) * (v + 1);
		}
		printf("%I64d\n", ans);
	}
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