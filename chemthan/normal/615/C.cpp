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

const int maxn = 2110;
char s[maxn];
char t[maxn];
int n, m;
int hash1[maxn][maxn];
int hash2[maxn][maxn];
int hash3[maxn][maxn];
int pw[maxn];

pi check(int cur, int mid) {
	FOR(i, 0, n) {
		if (hash1[i][mid] == hash3[cur][mid]) return mp(i, i + mid - 1);
		if (hash2[i][mid] == hash3[cur][mid]) return mp(i + mid - 1, i);
	}
	return mp(-1, -1);
}

void solve() {
	pw[0] = 1; FOR(i, 1, maxn) pw[i] = (ll) 2311 * pw[i - 1] % MOD;
	scanf("%s%s", s, t);
	n = strlen(s); m = strlen(t);
	FOR(i, 0, n) FOR(j, 1, n - i + 1) {
		hash1[i][j] = ((ll) 2311 * hash1[i][j - 1] + s[i + j - 1]) % MOD;
		hash2[i][j] = (hash2[i][j - 1] + (ll) pw[j - 1] * s[i + j - 1]) % MOD;
	}
	FOR(i, 0, m) FOR(j, 1, m - i + 1) {
		hash3[i][j] = ((ll) 2311 * hash3[i][j - 1] + t[i + j - 1]) % MOD;
	}
	vii ans;
	int cur = 0;
	while (cur < m) {
		int l = 1, r = m - cur;
		while (l < r) {
			int mid = (l + r + 1) >> 1;
			if (check(cur, mid) != mp(-1, -1)) l = mid; else r = mid - 1;
		}
		pi res = check(cur, l);
		if (res == mp(-1, -1)) {
			printf("-1");
			return;
		}
		else {
			ans.pb(res);
			cur += l;
		}
	}
	printf("%d\n", sz(ans));
	FOR(i, 0, sz(ans)) printf("%d %d\n", ans[i].fi + 1, ans[i].se + 1);
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