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

int n, m;

int dp[10][bit(18)];
int f[10][bit(18)];
int g[10][bit(18)];

const int dx[][5] = {{0, 0, 0, 1, 2}, {0, 1, 1, 1, 2}, {0, 1, 2, 2, 2}, {0, 1, 1, 1, 2}};
const int dy[][5] = {{0, 1, 2, 1, 1}, {2, 0, 1, 2, 2}, {1, 1, 0, 1, 2}, {0, 0, 1, 2, 0}};

bool out(int x, int y) {
	return x > n || y >= m || y < 0;
}

int S;
char s[10][10];

void go(int r, int state, int nstate, int pos, long long add, int cnt) {
	if (pos == m) {
		if(dp[r][nstate] < cnt) {
			dp[r][nstate] = cnt;
			f[r][nstate] = add;
			g[r][nstate] = S;
		}
		return;
	}
	go(r, state, nstate, pos + 1, add, cnt);
	int x = r, y = pos;
	for (int i = 0; i < 4; i++) {
		bool flg = 1;
		for (int j = 0; flg && j < 5; j++) {
			int nx = x + dx[i][j], ny = y + dy[i][j];
			if (out(nx, ny)) {
				flg = 0;
				break;
			}
			if (nx <= r + 1) {
				if (state >> ((nx - r) * m + ny) & 1) {
					flg = 0;
					break;
				}
			} else {
				if (nstate >> (m + ny) & 1) {
					flg = 0;
					break;
				}
			}
		}
		if (!flg) continue;
		int cstate = state, cnstate = nstate, cadd = add | bitl(pos*4+i);
		for (int j = 0; flg && j < 5; j++) {
			int nx = x + dx[i][j], ny = y + dy[i][j];
			if (nx <= r + 1) {
				cstate |= bit((nx-r)*m+ny);
				if (nx == r + 1) {
					cnstate |= bit(ny);
				}
			} else {
				cnstate |= bit(ny + m);
			}
		}
		go(r, cstate, cnstate, pos + 1, cadd, cnt + 1);
	}
}

int main() {
	
	scanf("%d%d", &n, &m);
	if (n <= 2 || m <= 2) {
		puts("0");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) putchar('.');
			puts("");
		}
		return 0;
	}
	memset(dp, -1, sizeof dp);
	dp[0][0] = 0;
	for (int i = 1; i <= n-2; i++) {
		for (int j = 0; j < bit(2*m); j++) if (~dp[i-1][j]) {
			S = j;
			go(i, j, j >> m, 0, 0, dp[i-1][j]);
		}
	}
	int ans = 0, opt = 0;
	for (int j = 0; j < bit(2*m); j++) {
		if (dp[n-2][j] > ans) {
			ans = dp[n-2][j];
			opt = j;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) s[i][j] = '.';
		s[i][m] = 0;
	}
	int r = n-2;
	int tot = ans;
	cout << ans << endl;
	while (r > 0) {
		long long st = f[r][opt];
		for (int i = m-1; i >= 0; i--) {
			for (int j = 0; j < 4; j++) {
				if (st >> (4*i+j) & 1) {
					int x = r, y = i;
					for (int k = 0; k < 5; k++) {
						int nx = x + dx[j][k], ny = y + dy[j][k];
						s[nx][ny] = 'A' + tot - 1;
					}
					tot--;
				}
			}
		}
		opt = g[r][opt], r--;
	}
	for (int i = 1; i <= n; i++) {
		puts(s[i]);
	}
	return 0;
}