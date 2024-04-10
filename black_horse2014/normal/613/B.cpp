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

int id[MAXN], a[MAXN], b[MAXN];
long long s[MAXN];

bool cmp(int u, int v) {
	return a[u] < a[v];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n;
	long long A, cf, cm, m;
	cin >> n >> A >> cf >> cm >> m;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), id[i] = i;
	sort(id + 1, id + n + 1, cmp);
	for (int i = 1; i <= n; i++) s[i] = s[i-1] + a[id[i]];
	for (int i = 1; i <= n; i++) b[i] = a[id[i]];
	long long cur = 0, ans = -1, cmin = -1, cmax = 0;
	for (int i = n; i >= 0 && cur <= m; i--) {
		int lo = 0, hi = A+1;
		while (hi - lo > 1) {
			int mid = lo + hi >> 1;
			int j = lower_bound(b + 1, b + i + 1, mid) - b - 1;
			long long cost = 1LL * mid * j - s[j];
			if (cost <= m - cur) lo = mid;
			else hi = mid;
		}
		long long ret = (n - i) * cf + lo * cm;
		if (ret > ans) ans = ret, cmax = n - i, cmin = lo;
		cur += A - b[i];
	}
	cout << ans << endl;
	for (int i = n; i > n - cmax; i--) a[id[i]] = A;
	for (int i = 1; i <= n; i++) {
		a[i] = max(cmin, (LL)a[i]);
		printf("%d ", a[i]);
	}
	puts("");
	return 0;
}