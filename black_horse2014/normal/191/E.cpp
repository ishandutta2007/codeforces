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

int n; LL m;

const int MAXN = 111111;

LL a[MAXN], x[MAXN];
int xn;

int b[MAXN];
int cnt[MAXN];

void add(int u) {
	for (u++; u <= xn; u += u & -u) cnt[u]++;
}

int get(int u) {
	int ret = 0;
	for (; u; u -= u & -u) ret += cnt[u];
	return ret;
} 

LL calc(LL mid) {
	memset(cnt, 0, sizeof(int)*(xn+1));
	add(b[0]);
	LL ret = 0;
	for (int i = 1; i <= n; i++) {
		ret += get(upper_bound(x, x + xn, a[i] - mid) - x);
		add(b[i]);
		if (ret >= m) return ret;
	}
	return ret;
}

int main() {
	cin >> n >> m;
	x[xn++] = 0;
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), a[i] += a[i-1], x[xn++] = a[i];
	sort(x, x + xn);
	xn = unique(x, x + xn) - x;
	for (int i = 0; i <= n; i++) b[i] = lower_bound(x, x + xn, a[i]) - x;
	LL lo = -(1LL<<50), hi = 1LL<<50;
	while (hi - lo > 1) {
		LL mid = lo + hi >> 1;
		if (calc(mid) < m) hi = mid;
		else lo = mid;
	}
	cout << lo << endl;
	return 0;
}