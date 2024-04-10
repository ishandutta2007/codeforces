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
#define EPS 1e-18
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

const int maxn = 1000010;
int n, c, d;
ld angle[maxn];

ld getangle(ld x, ld y) {
	if (x == 0) {
		if (y > 0) return PI / 2;
		return 3 * PI / 2;
	}
	if (y == 0) {
		if (x > 0) return 0;
		return PI;
	}
	ld res = atan(y / x);
	if (x < 0) return res + PI;
	if (y < 0) return res + 2 * PI;
	return res;
}

void solve() {
	scanf("%d%d%d", &n, &c, &d);
	FOR(i, 0, n) {
		ll x, y; scanf("%I64d%I64d", &x, &y);
		angle[i] = getangle(x - c, y - d);
	}
	sort(angle, angle + n);
	FOR(i, 0, n) angle[i + n] = angle[i] + 2 * PI;
	ll tot = 0;
	FOR(i, 0, n) {
		int l = i, r = i + n;
		while (l < r) {
			int m = (l + r + 1) >> 1;
			if (angle[m] - angle[i] < PI - EPS) l = m; else r = m - 1;
		}
		int p = l;
		l = i; r = i + n;
		while (l < r) {
			int m = (l + r) >> 1;
			if (angle[m] - angle[i] < PI + EPS) l = m + 1; else r = m;
		}
		int q = l;
		ll u = p - i;
		ll v = n - (q - i);
		ll w = q - p - 1;
		tot += u * (u - 1) / 2 + v * (v - 1) / 2 + w * (u + v);
	}
	printf("%I64d", 1LL * n * (n - 1) * (n - 2) / 6 - tot / 2);
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