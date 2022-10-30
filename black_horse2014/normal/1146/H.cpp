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

const int N = 330;

struct Point {
	int x, y;
	Point(int x = 0, int y = 0) : x(x), y(y) {}
	bool operator<(const Point &rhs) const {
		return x < rhs.x;
	}
} P[N];

vector< pair<int, int> > E;
const long long INF = 1LL<<50;

long double A[N][N];

long long dp[N][N][7];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
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
	int m = 5;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) for (int k = 0; k < m; k++) dp[i][j][k] = 0;
	for (int i = 0; i < n; i++) dp[i][i][0] = 1;
	for (int i = 0; i < E.size(); i++) {
		int u = E[i].first, v = E[i].second;
		for (int j = 0; j <= u; j++) {
			for (int k = 0; k < m-1; k++) {
                dp[j][v][k+1] += dp[j][u][k];
			}
		}
		for (int j = v; j < n; j++) {
			for (int k = 0; k < m-1; k++) dp[j][u][k+1] += dp[j][v][k];
		}
	}
	long long ans = 0;
	for (int j = 0; j < n; j++) for (int k = j+1; k < n; k++) for (int l = 1; l < m; l++) ans += dp[j][k][l] * dp[k][j][m-l];
    cout << ans << endl;
	return 0;
}