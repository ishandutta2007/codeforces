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

const int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int a[44], T;

int chk[301][301][8];
int vis[301][301];
int q[8000000];
int _q[8000000];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	vis[150][150] = 1;
	for (int j = 1; j <= a[1]-1; j++) vis[150+j][150] = 1;
	int qn = 0, _qn = 0;
	q[qn++] = 149 + a[1], q[qn++] = 150, q[qn++] = 0;
	for (int i = 2; i <= n; i++) {
		T++;
		_qn = 0;
		for (int j = 0; j < qn; j += 3) {
			int x = q[j], y = q[j+1], d = q[j+2];
			for (int k = -1; k <= 1; k += 2) {
				int nd = (d + k + 8) % 8, nx = x, ny = y;
				for (int l = 1; l <= a[i]; l++) {
					nx += dx[nd], ny += dy[nd];
					vis[nx][ny] = 1;
				}
				if (chk[nx][ny][nd] == T) continue;
				chk[nx][ny][nd] = T;
				_q[_qn++] = nx, _q[_qn++] = ny, _q[_qn++] = nd;
			}
		}
		for (int j = 0; j < _qn; j++) q[j] = _q[j];
		qn = _qn;
	}
	int ans = 0;
	for (int i = 0; i <= 300; i++) for (int j = 0; j <= 300; j++) if (vis[i][j]) ans++;
	cout << ans << endl;
	return 0;
}