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

VPII ans;

long long a[111111], b[111111];

int main() {
	
	int n, m, L, R;
	cin >> n >> m >> L >> R;
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i <= m; i++) scanf("%lld", &b[i]);
	for (int i = 1, j = 1; i <= n; i++) {
		while (j <= m && b[j] < a[i] - L) j++;
		if (j <= m && b[j] <= a[i] + R) {
			ans.pb(PII(i, j));
			j++;
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}