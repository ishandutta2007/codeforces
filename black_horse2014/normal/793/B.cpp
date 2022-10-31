#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef double DB;

#define pb push_back
#define mset(a, b) memset(a, b, sizeof a)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define clzi(x) (__builtin_clz(x))
#define clzl(x) (__builtin_clzll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))

#define X first
#define Y second

#define Error(x) cout << #x << " = " << x << endl

template <typename T, typename U>
inline void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template <typename T, typename U>
inline void chkmin(T& x, U y) {
	if (y < x) x = y;
}

const int MAXN = 1111;

int tot;
int a[MAXN][MAXN], b[MAXN][MAXN];
char s[MAXN][MAXN];

VI con[MAXN*MAXN];

int chk[MAXN*MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '*') continue;
			int k = j; tot++;
			while (k < m && s[i][k] != '*') a[i][k] = tot, k++;
			j = k - 1;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (s[j][i] == '*') continue;
			int k = j; tot++;
			while (k < n && s[k][i] != '*') b[k][i] = tot, k++;
			j = k - 1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] != '*') {
				con[a[i][j]].push_back(b[i][j]);
				con[b[i][j]].push_back(a[i][j]);
			}
		}
	}
	int sx, sy, ex, ey;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == 'S') sx = i, sy = j;
			if (s[i][j] == 'T') ex = i, ey = j;
		}
	}
	int u = a[sx][sy], v = b[sx][sy];
	for (int i = 0; i < sz(con[u]); i++) chk[con[u][i]] = 1;
	for (int i = 0; i < sz(con[v]); i++) chk[con[v][i]] = 1;
	u = a[ex][ey], v = b[ex][ey];
	if (chk[u] || chk[v]) {
		puts("YES");
		return 0;
	}
	for (int i = 0; i < sz(con[u]); i++) if (chk[con[u][i]]) {
		puts("YES");
		return 0;
	}
	for (int i = 0; i < sz(con[v]); i++) if (chk[con[v][i]]) {
		puts("YES");
		return 0;
	}
	puts("NO");
	return 0;
}