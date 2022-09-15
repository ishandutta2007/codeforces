#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 4010;
const int mod = 1000000007;
int n;
ll f[maxn][maxn];
ll g[maxn];
ll c[maxn][maxn];

void build() {
	ms(f, 0); ms(g, 0); f[0][0] = 1;
	FOR(i, 1, maxn) FOR(j, 1, maxn) f[i][j] = (f[i - 1][j - 1] + i * f[i][j - 1]) % mod;
	FOR(i, 0, maxn) FOR(j, 0, i + 1) g[i] = (g[i] + f[j][i]) % mod;
	FOR(i, 0, maxn) c[0][i] = 1;
	FOR(i, 1, maxn) FOR(j, 1, maxn) c[i][j] = (c[i][j - 1] + c[i - 1][j - 1]) % mod;
}

void solve() {
	build();
	scanf("%d", &n);
	ll ans = 0;
	FOR(i, 1, n + 1) ans = (ans + c[i][n] * g[n - i]) % mod;
	printf("%I64d", ans);
}

int main() {
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}