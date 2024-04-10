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

const int maxn = 510;
const int mod = 1000000007;
int n, m;
char s[maxn];
int a[maxn][maxn];
int f[2][maxn][maxn];

void solve() {
	scanf("%d%d", &n, &m);
	FOR(i, 0, n) {scanf("%s", s); FOR(j, 0, m) a[i][j] = s[j] - 'a';}
	int cnt = 0;
	FORd(i, (n + m) / 2, 1) {
		ms(f[cnt ^ 1], 0);
		FOR(j, 0, i + 1) FOR(k, 0, n + m - i - 1) {
			int x = j;
			int y = i - j;
			int z = k;
			int t = n + m - i - k - 2;
			if (x >= n || y >= m || z >= n || t >= m) continue;
			if (a[x][y] != a[z][t]) continue;
			if (abs(x - z) + abs(y - t) <= 1 && x <= z && y <= t) f[cnt][x][z] = 1;
			if (x && t < m - 1 && a[x - 1][y] == a[z][t + 1]) f[cnt ^ 1][x - 1][z] = (f[cnt ^ 1][x - 1][z] + f[cnt][x][z]) % mod;
			if (x && z < n - 1 && a[x - 1][y] == a[z + 1][t]) f[cnt ^ 1][x - 1][z + 1] = (f[cnt ^ 1][x - 1][z + 1] + f[cnt][x][z]) % mod;
			if (y && t < m - 1 && a[x][y - 1] == a[z][t + 1]) f[cnt ^ 1][x][z] = (f[cnt ^ 1][x][z] + f[cnt][x][z]) % mod;
			if (y && z < n - 1 && a[x][y - 1] == a[z + 1][t]) f[cnt ^ 1][x][z + 1] = (f[cnt ^ 1][x][z + 1] + f[cnt][x][z]) % mod;
		}
		cnt ^= 1;
	}
	printf("%d", f[cnt][0][n - 1]);
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