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

int dp[110][2100];
int pr[110][2100];
int t[110], d[110], id[110], p[110];

bool cmp(int u, int v) {
	return d[u] < d[v];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d%d", &t[i], &d[i], &p[i]);
	for (int i = 1; i <= n; i++) id[i] = i;
	sort(id + 1, id + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		int u = id[i];
		for (int j = 0; j <= 2000; j++) {
			dp[i][j] = dp[i-1][j];
			pr[i][j] = j;
			int k = min(j, d[u]-1);
			if (k >= t[u] && dp[i][j] < dp[i-1][k-t[u]] + p[u]) {
				dp[i][j] = dp[i-1][k-t[u]] + p[u];
				pr[i][j] = k-t[u];
			}
		}
	}
	cout << dp[n][2000] << endl;
	int T = 2000;
	vector<int> ans;
	for (int i = n; i > 0; i--) {
		if (pr[i][T] < T) ans.push_back(id[i]);
		T = pr[i][T];
	}
	reverse(all(ans));
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
	return 0;
}