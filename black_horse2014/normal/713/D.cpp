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

int b[10][10][1002][1002];
int a[1002][1002];

int get_max(int sx, int ex, int sy, int ey) {
	assert(ex >= sx && ey >= sy);
	int k = 31 - clzi(ex - sx + 1), l = 31 - clzi(ey - sy + 1);
	return max(max(b[k][l][sx][ey - bit(l) + 1], b[k][l][ex - bit(k) + 1][sy]), max(b[k][l][sx][sy], b[k][l][ex - bit(k) + 1][ey - bit(l) + 1]));
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]), a[i][j] += a[i][j-1] + a[i-1][j] - a[i-1][j-1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int lo = 0, hi = min(n-i+1, m-j+1)+1;
			while (hi - lo > 1) {
				int mid = lo + hi >> 1;
				if (a[mid+i-1][mid+j-1] + a[i-1][j-1] - a[i-1][mid+j-1] - a[mid+i-1][j-1] == mid * mid) lo = mid;
				else hi = mid;
			}
			b[0][0][i][j] = lo;
		}
	}
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			if (i == 0 && j == 0) continue;
			for (int k = 1; k <= n; k++) {
				for (int l = 1; l <= m; l++) {
					if (j > 0) {
						b[i][j][k][l] = b[i][j-1][k][l];
						if (l + bit(j-1) <= m) chkmax(b[i][j][k][l], b[i][j-1][k][l+bit(j-1)]);
					} else {
						b[i][j][k][l] = b[i-1][j][k][l];
						if (k + bit(i-1) <= n) chkmax(b[i][j][k][l], b[i-1][j][k+bit(i-1)][l]);
					}
				}
			}
		}
	}
	int q; scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		int sx, sy, ex, ey;	scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
		int lo = 0, hi = min(ex - sx, ey - sy) + 2;
		while (hi - lo > 1) {
			int mid = lo + hi >> 1;
			if (get_max(sx, ex - mid + 1, sy, ey - mid + 1) >= mid) lo = mid;
			else hi = mid;
		}
		printf("%d\n", lo);
	}
	return 0;
}