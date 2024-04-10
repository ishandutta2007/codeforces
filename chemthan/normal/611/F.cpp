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

const int maxn = 500010;
int n, w, h;
char s[maxn];
int xmin[maxn];
int xmax[maxn];
int ymin[maxn];
int ymax[maxn];
ll alox[maxn];
ll aloy[maxn];
ll tot[maxn];

void solve() {
	scanf("%d%d%d%s", &n, &h, &w, s);
	int dx = 0, dy = 0;
	FOR(i, 0, n) {
		if (s[i] == 'L') dx--;
		else if (s[i] == 'R') dx++;
		else if (s[i] == 'U') dy--;
		else dy++;
		if (!i) {
			xmin[i] = xmax[i] = dx;
			ymin[i] = ymax[i] = dy;
		}
		else {
			xmin[i] = min(xmin[i - 1], dx);
			xmax[i] = max(xmax[i - 1], dx);
			ymin[i] = min(ymin[i - 1], dy);
			ymax[i] = max(ymax[i - 1], dy);
		}
	}
	FOR(i, 0, w) {
		int c = 0;
		if (i + xmin[n - 1] >= 0 && i + xmax[n - 1] < w) {
			int l = 0, r = INF;
			while (l < r) {
				int m = (l + r) >> 1;
				if (dx >= 0) {
					if (i + xmax[n - 1] + 1LL * m * dx < w) l = m + 1; else r = m;
				}
				else {
					if (i + xmin[n - 1] + 1LL * m * dx >= 0) l = m + 1; else r = m;
				}
			}
			c = l;
		}
		if (c == INF) {
			alox[i] = -1;
			continue;
		}
		int l = 0, r = n - 1;
		while (l < r) {
			int m = (l + r) >> 1;
			if (i + xmin[m] + 1LL * c * dx >= 0 && i + xmax[m] + 1LL * c * dx < w) l = m + 1; else r = m;
		}
		alox[i] = 1LL * c * n + l + 1;
	}
	FOR(i, 0, h) {
		int c = 0;
		if (i + ymin[n - 1] >= 0 && i + ymax[n - 1] < h) {
			int l = 0, r = INF;
			while (l < r) {
				int m = (l + r) >> 1;
				if (dy >= 0) {
					if (i + ymax[n - 1] + 1LL * m * dy < h) l = m + 1; else r = m;
				}
				else {
					if (i + ymin[n - 1] + 1LL * m * dy >= 0) l = m + 1; else r = m;
				}
			}
			c = l;
		}
		if (c == INF) {
			aloy[i] = -1;
			continue;
		}
		int l = 0, r = n - 1;
		while (l < r) {
			int m = (l + r) >> 1;
			if (i + ymin[m] + 1LL * c * dy >= 0 && i + ymax[m] + 1LL * c * dy < h) l = m + 1; else r = m;
		}
		aloy[i] = 1LL * c * n + l + 1;
	}
	int flagx = 0, flagy = 0;
	FOR(i, 0, w) {
		if (!~alox[i]) {
			flagx = 1;
			alox[i] = LINF;
		}
	}
	FOR(i, 0, h) {
		if (!~aloy[i]) {
			flagy = 1;
			aloy[i] = LINF;
		}
	}
	if (flagx && flagy) {printf("-1"); return;}
	int ans = 0;
	sort(aloy, aloy + h);
	FOR(i, 0, h) {
		if (!i) tot[i] = aloy[i] % MOD;
		else tot[i] = (tot[i - 1] + aloy[i]) % MOD;
	}
	FOR(i, 0, w) {
		int k = upper_bound(aloy, aloy + h, alox[i]) - aloy - 1;
		if (~k) ans = (ans + tot[k]) % MOD;
		ans = (ans + 1LL * (h - k - 1) * alox[i]) % MOD;
	}
	printf("%d", ans);
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