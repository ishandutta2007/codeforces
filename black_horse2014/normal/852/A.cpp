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

const int MAXN = 200000+20;
const int MAXM = 250000+20;

char s[MAXN];
int dp[MAXM], p[MAXM], nxt[MAXM];

int chk[51][MAXN], pr[51][MAXN];

int a[128], b[8][8], pw[8];
int r;
int vis[MAXN];

void print(int x, int dep) {
	if (dep == 0) return;
	if (dp[x] < dep) {
		printf("%d\n", x*9+r);
		print(x, dep-1);
		return;
	}
	int s = p[x];
	int m = 0;
	int d[10];
	for (int y = x * 9 + r; y; d[m++] = y % 10, y /= 10);
	for (int j = m-1; j >= 0; j--) {
		if (s >> j & 1) putchar('+');
		putchar(d[j] + '0');
	}
	puts("");
	print(nxt[x], dep-1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d%s", &n, s);
	if (n == 1 && s[0] == '0') return puts("0\n0\n0"), 0;
	int sum = 0;
	for (int i = 0; i < n; i++) sum += s[i] - '0';
	r = (sum + 8) % 9 + 1;
	dp[0] = 0;
	for (int i = 0; i < 8; i++) pw[i] = (i == 0 ? 1 : pw[i-1] * 10);
	for (int i = 1; i < MAXM; i++) {
		int x = i * 9 + r, m = 0;
		for (int y = x; y; m++, y /= 10);
		for (int j = 0; j < m; j++) {
			for (int k = j; k < m; k++) b[j][k] = (x / pw[j]) % pw[k-j+1];
		}
		a[0] = x;
		for (int j = 1; j < bit(m-1); j++) {
			int k = ctzi(j), _j = j - (j & -j), l = ctzi(_j);
			if (_j == 0) a[j] = b[0][k] + b[k+1][m-1];
			else a[j] = a[_j] - b[0][l] + b[0][k] + b[k+1][l];
		}
		dp[i] = 100;
		for (int j = 1; j < bit(m-1); j++) {
			int temp = dp[(a[j]-r)/9]+1;
			if (dp[i] > temp) {
				dp[i] = temp;
				p[i] = j;
				nxt[i] = (a[j]-r)/9;
			}
		}
	}
	if (n <= 6) {
		print((atoi(s)-r)/9, 3);
		return 0;
	}
	int temp = (sum - r) / 9;
	if (dp[temp] <= 2) {
		for (int j = 0; j < n; j++) {
			if (j) putchar('+');
			putchar(s[j]);
		}
		puts("");
		print(temp, 2);
		return 0;
	}
	chk[0][0] = 1;
	for (int i = 1; i <= n-1; i++) {
		for (int j = 0; j <= 50; j++) chk[j][i] = chk[j][i-1];
		if (i > 1) {
			int x = s[i-1]-'0';
			for (int j = 0; j <= 50-x; j++) if (chk[j][i-2] && !chk[j+x][i]) chk[j+x][i] = 1, pr[j+x][i] = 1;
		}
	}
	for (int add = 1; add <= 50; add++) {
		if (chk[add][n-1] && dp[temp+add] <= 2) {
			int last = n-1, cur = add;
			while (last > 0) {
				if (pr[cur][last]) vis[last] = 1, cur -= s[last-1]-'0', last -= 2;
				else last--;
			}
			for (int j = 0; j < n; j++) {
				if (j && !vis[j]) putchar('+');
				putchar(s[j]);
			}
			puts("");
			print(temp+add, 2);
			return 0;
		}
	}
	return 0;
}