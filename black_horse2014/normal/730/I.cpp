#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
#include <complex>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
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

const int MAXN = 3333;

int chk[MAXN];
int id[MAXN], b[MAXN], a[MAXN], dp[MAXN], pr[MAXN][MAXN];

bool cmp(int u, int v) {
	return b[u] > b[v];
}

int main() {

	int n, p, s; cin >> n >> p >> s;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < n; i++) id[i] = i;
	sort(id, id + n, cmp);
	for (int i = 0; i < n; i++) {
		int u = id[i];
		for (int j = min(p, i+1); j > 0; j--) {
			if (j + s >= i+1 && j <= i) {
				int temp = dp[j-1] + a[u];
				dp[j] = max(temp, dp[j] + b[u]);
				pr[i][j] = (dp[j] == temp);
			} else {
				int temp = dp[j-1] + a[u];
				dp[j] = max(dp[j], temp);
				pr[i][j] = (dp[j] == temp);
			}
		}
		if (s >= i+1) {
			dp[0] += b[u];
		}
	}
	printf("%d\n", dp[p]);
	for (int i = n-1; p && i >= 0; i--) {
		if (pr[i][p]) {
			printf("%d%c", id[i]+1, (p>1) ? ' ' : '\n');
			chk[id[i]] = 1;
			p--;
		}
	}
	for (int i = 0; s && i < n; i++) {
		if (!chk[id[i]]) printf("%d%c", id[i]+1, (s>1) ? ' ' : '\n'), s--;
	}
	return 0;
}