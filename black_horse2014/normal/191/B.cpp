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

int id[MAXN];
long long a[MAXN];

bool cmp(int u, int v) {
	return a[u] > a[v];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n, k; long long b; cin >> n >> k >> b;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]), id[i] = i;
	}
	sort(id + 1, id + n, cmp);
	long long sum = 0;
	for (int i = 1; i <= k; i++) sum += a[id[i]];
	if (sum <= b) {
		printf("%d\n", n);
		return 0;
	}
	int ans = n;
	for (int i = 1; i <= n-1; i++) {
		if (i <= k) {
			chkmin(ans, id[i]);
		} else {
			if (sum - a[id[k]] + a[id[i]] > b) {
				chkmin(ans, id[i]);
			} else {
				break;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}