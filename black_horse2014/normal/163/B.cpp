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

int n, m, h;
int id[MAXN], a[MAXN], b[MAXN];
int chk[MAXN];

bool cmp(int x, int y) {
	if (a[x] != a[y]) return a[x] < a[y];
	return b[x] < b[y];
}

bool can(double t) {
	int cur = m;
	double curt = cur * h / t;
	for (int i = 1; i <= n; i++) chk[i] = 0;
	for (int i = n; i > 0; i--) {
		int u = id[i];
		if (b[u] >= curt) {
			cur--;
			curt -= h / t;
			chk[u] = 1;
		}
		if (cur == 0) return 1;
	}
	return 0;
}

int main() {
	
	cin >> n >> m >> h;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), id[i] = i;
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	sort(id + 1, id + n + 1, cmp);
	double lo = 0, hi = 1e9 + 1;
	for (int i = 0; i < 200; i++) {
		double mid = (lo + hi) / 2;
		if (can(mid)) hi = mid;
		else lo = mid;
	}
	can(hi);
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		if (chk[id[i]]) {
			ans.pb(id[i]);
		}
	}
	for (int i = 0; i < m; i++) printf("%d%c", ans[i], i < m-1 ? ' ' : '\n');
	return 0;
}