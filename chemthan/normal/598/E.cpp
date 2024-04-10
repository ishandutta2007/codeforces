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
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

int f[60][40][40];

int calc(int k, int n, int m) {
	if (k == 0 || k == n * m) return 0;
	if (f[k][n][m] != -1) return f[k][n][m];
	int& res = f[k][n][m]; res = INF;
	FOR(i, 0, k + 1) {
		FOR(j, 1, n) res = min(res, calc(i, j, m) + calc(k - i, n - j, m) + m * m);
		FOR(j, 1, m) res = min(res, calc(i, n, j) + calc(k - i, n, m - j) + n * n);
	}
	return res;
}

void solve() {
	ms(f, -1);
	FOR(k, 0, 51) FOR(i, 0, 31) FOR(j, 0, 31) f[k][i][j] = calc(k, i, j);
	int t; scanf("%d", &t);
	while (t--) {
		int n, m, k; scanf("%d%d%d", &n, &m, &k);
		printf("%d\n", f[k][n][m]);
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