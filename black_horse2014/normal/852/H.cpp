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

struct Point {
	int x, y;
	Point(int x = 0, int y = 0) : x(x), y(y) {}
	bool operator<(const Point &rhs) const {
		return x < rhs.x;
	}
} P[256];

vector< pair<int, int> > E;
const long long INF = 1LL<<50;

double A[256][256];
bool chk[256][256][256];

long long dp[200][200][51];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d%d", &P[i].x, &P[i].y);
	sort(P, P + n);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1, u; j < n; j++) {
			E.push_back(make_pair(i, j));
			A[j][i] = A[i][j] = atan2(P[j].y - P[i].y, P[j].x - P[i].x);
		}
	}
	sort(E.begin(), E.end(), [](pair<int, int> lhs, pair<int, int> rhs) {
		return A[lhs.first][lhs.second] < A[rhs.first][rhs.second];
	});
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) if (i != j) {
			double low = -10, upp = 10;
			for (int l = min(i, j) + 1; l < max(i, j); l++) {
				if (A[i][l] < A[i][j]) {
					low = max(low, A[i][l]);
				} else {
					upp = min(upp, A[i][l]);
				}
			}
			for (int l = 0; l < n; l++) {
				if (l < j && j < i) {
					if (A[i][l] < low || A[i][l] > upp) chk[l][j][i] = 1;
				}
				if (i < j && j < l) {
					if (A[i][l] < low || A[i][l] > upp) chk[i][j][l] = 1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) for (int k = 0; k < m; k++) dp[i][j][k] = -INF;
	for (int i = 0; i < n; i++) dp[i][i][0] = 0;
	for (int i = 0; i < E.size(); i++) {
		int u = E[i].first, v = E[i].second;
		long long w = 1LL * P[v].y * P[u].x - 1LL * P[v].x * P[u].y;
		for (int j = 0; j <= u; j++) if (!chk[j][u][v]) {
			for (int k = 0; k < m-1; k++) {
				dp[j][v][k+1] = max(dp[j][v][k+1], dp[j][u][k] + w);
			}
		}
		for (int j = v; j < n; j++) if (!chk[u][v][j]) {
			for (int k = 0; k < m-1; k++) dp[j][u][k+1] = max(dp[j][u][k+1], dp[j][v][k] - w);
		}
	}
	long long ans = 0;
	for (int j = 0; j < n; j++) for (int k = j+1; k < n; k++) for (int l = 1; l < m; l++) ans = max(ans, dp[j][k][l] + dp[k][j][m-l]);
	if (ans & 1) printf("%lld.50\n", ans / 2);
	else printf("%lld.00\n", ans / 2);
	return 0;
}