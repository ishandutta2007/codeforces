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

const int maxn = 5010;
const int mod = 1000000007;
int n, a, b, k;
int f[maxn][maxn];
int g[2][maxn];

void solve() {
	ms(f, 0); ms(g, 0);
	scanf("%d%d%d%d", &n, &a, &b, &k);
	if (a > b) {a = n + 1 - a; b = n + 1 - b;}
	f[0][a] = 1; FOR(i, 1, b) g[0][i] = (g[0][i - 1] + f[0][i]) % mod;
	int cnt = 0;
	FOR(i, 1, k + 1) {
		FOR(j, 1, b) {
			int up = (j + b - 1) / 2;
			f[i][j] = g[cnt][up];
			if (j <= up) f[i][j] = (f[i][j] - f[i - 1][j] + mod) % mod;
			g[cnt ^ 1][j] = (g[cnt ^ 1][j - 1] + f[i][j]) % mod;
		}
		cnt ^= 1;
	}
	int ans = 0;
	FOR(i, 1, b) ans = (ans + f[k][i]) % mod;
	printf("%d", ans);
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