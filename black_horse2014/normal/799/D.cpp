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

const int MAXN = 111111;

int x[MAXN];
int dp[2][MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int h, w, a, b, n; cin >> a >> b >> h >> w >> n;
	for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
	sort(x + 1, x + n + 1);
	reverse(x + 1, x + n + 1);
	if (a <= h && b <= w) {
		puts("0");
		return 0;
	}
	if (a <= w && b <= h) {
		puts("0");
		return 0;
	}
	int ans = n + 1;
	int H = h, W = w;
	for (int k = 0; k < 2; k++) {
		memset(dp, 0, sizeof dp);
		dp[0][1] = 1;
		h = (a + H - 1) / H, w = (b + W - 1) / W;
		for (int i = 1; i <= n; i++) {
			if (x[i] == 1) break;
			for (int j = h; j > 0; j--) dp[1][j] = min(1LL * w, 1LL * dp[0][j] * x[i]);
			for (int j = h; j > 0; j--) {
				if (dp[0][j]) chkmax(dp[1][min(1LL * h, 1LL * j * x[i])], dp[0][j]);
			}
			for (int j = h; j > 0; j--) dp[0][j] = dp[1][j];
			for (int j = h-1; j > 0; j--) chkmax(dp[0][j], dp[0][j + 1]);
			if (dp[0][h] >= w) {
				chkmin(ans, i);
				break;
			}
		}
		swap(a, b);
	}
	if (ans <= n) printf("%d\n", ans);
	else puts("-1");
	return 0;
}