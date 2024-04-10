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

int n, m, T;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

PII vis[1555][1555];
bool chk[1555][1555];

char s[1555][1555];
queue<int> Q;

bool bfs(int x, int y) {
	chk[x][y] = 1;
	vis[x][y] = PII(x, y);
	Q.push(x), Q.push(y);
	while (!Q.empty()) {
		int _x = Q.front(); Q.pop();
		int _y = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = _x + dx[i], ny = _y + dy[i];
			int xx = (nx % n + n) % n;
			int yy = (ny % m + m) % m;
			if (s[xx][yy] == '#') continue;
			if (chk[xx][yy]) {
				int tx = vis[xx][yy].first, ty = vis[xx][yy].second;
				if (nx == tx && ny == ty) continue;
				return 1;
			}
			chk[xx][yy] = 1, vis[xx][yy] = PII(nx, ny);
			Q.push(nx), Q.push(ny);
		}
	}
	return 0;
}

int main() {
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%s", s[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == 'S') {
				if (bfs(i, j)) {
					puts("Yes");
					return 0;
				}
			}
		}
	}
	puts("No");
	return 0;
}