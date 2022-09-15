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

const int maxn = 2010;
int n, m;
char s[maxn];
bool a[maxn][maxn];
bool b[maxn][maxn];
int u[maxn];
int d[maxn];
int l[maxn];
int r[maxn];
int f[2][maxn][2];
int g[2][maxn];
int h[2][maxn];
int x[2][maxn];

ll go() {
	ms(f, 0); ms(g, 0); ms(h, 0); ms(x, 0);
	ll res = 0;
	bool cnt = 0;
	FOR(i, 1, m - 1) {
		f[cnt][i][0] = a[0][i];
		g[cnt][i] = g[cnt][i - 1] + f[cnt][i][0];
		h[cnt][i] = h[cnt][i - 1] + f[cnt][i][0] * f[cnt][i - 1][0];
		x[cnt][i] = x[cnt][i - 1] + f[cnt][i][0] * f[cnt][i][0];
	}
	FOR(i, 1, n - 1) {
		int cur = -1;
		FOR(j, 1, m - 1) {
			if (a[i][j]) {
				f[cnt ^ 1][j][0] = f[cnt][j][0];
				f[cnt ^ 1][j][1] = f[cnt][j][1];
				if (cur == -1) cur = j;
				if (j == m - 2 && cur != -1) {
					FOR(k, cur, j + 1) f[cnt ^ 1][k][1] += g[cnt][j] - g[cnt][cur - 1] - f[cnt][k][0];
					ll sum = g[cnt][j] - g[cnt][cur - 1];
					ll prd = h[cnt][j] - h[cnt][cur];
					ll sqr = x[cnt][j] - x[cnt][cur - 1];
					res += (sum * sum - sqr) / 2 - prd;
				}
			}
			else {
				f[cnt ^ 1][j][0] = f[cnt ^ 1][j][1] = 0;
				if (cur != -1) {
					FOR(k, cur, j) f[cnt ^ 1][k][1] += g[cnt][j - 1] - g[cnt][cur - 1] - f[cnt][k][0];
					ll sum = g[cnt][j - 1] - g[cnt][cur - 1];
					ll prd = h[cnt][j - 1] - h[cnt][cur];
					ll sqr = x[cnt][j - 1] - x[cnt][cur - 1];
					res += (sum * sum - sqr) / 2 - prd;
					cur = -1;
				}
			}
		}
		FOR(j, 1, m - 1) {
			g[cnt ^ 1][j] = g[cnt ^ 1][j - 1] + f[cnt ^ 1][j][0];
			h[cnt ^ 1][j] = h[cnt ^ 1][j - 1] + f[cnt ^ 1][j][0] * f[cnt ^ 1][j - 1][0];
			x[cnt ^ 1][j] = x[cnt ^ 1][j - 1] + f[cnt ^ 1][j][0] * f[cnt ^ 1][j][0];
		}
		cnt ^= 1;
	}
	FOR(i, 1, m - 1) if (a[n - 1][i]) res += f[cnt][i][0] + f[cnt][i][1];

	ms(f, 0); ms(g, 0); ms(h, 0); ms(x, 0);
	cnt = 0;
	FOR(i, 1, m - 1) {
		f[cnt][i][0] = a[n - 1][i];
		g[cnt][i] = g[cnt][i - 1] + f[cnt][i][0];
		h[cnt][i] = h[cnt][i - 1] + f[cnt][i][0] * f[cnt][i - 1][0];
		x[cnt][i] = x[cnt][i - 1] + f[cnt][i][0] * f[cnt][i][0];
	}
	FORd(i, n - 1, 1) {
		int cur = -1;
		FOR(j, 1, m - 1) {
			if (a[i][j]) {
				f[cnt ^ 1][j][0] = f[cnt][j][0];
				f[cnt ^ 1][j][1] = f[cnt][j][1];
				if (cur == -1) cur = j;
				if (j == m - 2 && cur != -1) {
					FOR(k, cur, j + 1) f[cnt ^ 1][k][1] += g[cnt][j] - g[cnt][cur - 1] - f[cnt][k][0];
					ll sum = g[cnt][j] - g[cnt][cur - 1];
					ll prd = h[cnt][j] - h[cnt][cur];
					ll sqr = x[cnt][j] - x[cnt][cur - 1];
					res += (sum * sum - sqr) / 2 - prd;
				}
			}
			else {
				f[cnt ^ 1][j][0] = f[cnt ^ 1][j][1] = 0;
				if (cur != -1) {
					FOR(k, cur, j) f[cnt ^ 1][k][1] += g[cnt][j - 1] - g[cnt][cur - 1] - f[cnt][k][0];
					ll sum = g[cnt][j - 1] - g[cnt][cur - 1];
					ll prd = h[cnt][j - 1] - h[cnt][cur];
					ll sqr = x[cnt][j - 1] - x[cnt][cur - 1];
					res += (sum * sum - sqr) / 2 - prd;
					cur = -1;
				}
			}
		}
		FOR(j, 1, m - 1) {
			g[cnt ^ 1][j] = g[cnt ^ 1][j - 1] + f[cnt ^ 1][j][0];
			h[cnt ^ 1][j] = h[cnt ^ 1][j - 1] + f[cnt ^ 1][j][0] * f[cnt ^ 1][j - 1][0];
			x[cnt ^ 1][j] = x[cnt ^ 1][j - 1] + f[cnt ^ 1][j][0] * f[cnt ^ 1][j][0];
		}
		cnt ^= 1;
	}

	return res;
}

void solve() {
	scanf("%d%d", &n, &m);
	FOR(i, 0, n) {
		scanf("%s", s);
		FOR(j, 0, m) a[i][j] = b[i][j] = s[j] == '.';
	}
	ll ans = 0;
	FOR(i, 1, m - 1) {
		u[i] = n - 1;
		d[i] = 0;
		FOR(j, 0, n) if (!a[j][i]) {u[i] = j - 1; break;}
		FORd(j, n, 0) if (!a[j][i]) {d[i] = j + 1; break;}
	}
	FOR(i, 1, n - 1) {
		l[i] = m - 1;
		r[i] = 0;
		FOR(j, 0, m) if (!a[i][j]) {l[i] = j - 1; break;}
		FORd(j, m, 0) if (!a[i][j]) {r[i] = j + 1; break;}
	}
	FOR(i, 1, m - 1) FOR(j, 1, n - 1) {
		if (u[i] >= j && r[j] <= i) ans++;
		if (u[i] >= j && l[j] >= i) ans++;
		if (d[i] <= j && r[j] <= i) ans++;
		if (d[i] <= j && l[j] >= i) ans++;
	}
	ans += go();
	ms(a, 0);
	FOR(i, 0, n) FOR(j, 0, m) a[j][i] = b[i][j];
	swap(n, m);
	ans += go();
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