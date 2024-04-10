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

int x[5010], y[5010];

int query(int u, int v) {
	cout << "? " << u << ' ' << v << endl;
	int ret; scanf("%d", &ret);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) x[i] = query(0, i);
	for (int i = 1; i < n; i++) y[i] = query(i, 0) ^ x[0];
	int ans = 0, p0 = -1;
	for (int i = 0; i < n; i++) {
		if (x[i] != i) continue;
		int flg = 1;
		for (int j = 0; flg && j < n; j++) {
			int u = x[j] ^ i, v = y[j] ^ i;
			flg &= (u < n && v < n && y[u] == (j ^ i));
		}
		if (flg) {
			ans++;
			p0 = i;
		}
	}
	puts("!");
	printf("%d\n", ans);
	if (p0 >= 0) {
		for (int j = 0; j < n; j++) printf("%d ", y[j] ^ p0);
		puts("");
	}
	fflush(stdout);
	return 0;
}