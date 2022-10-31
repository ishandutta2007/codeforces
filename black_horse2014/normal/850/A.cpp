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

int a[5][205];

int calc(int u, int v, int w) {
	int ret = 0;
	for (int i = 0; i < 5; i++) ret += (a[i][v] - a[i][u]) * (a[i][w] - a[i][u]);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	if (n > 200) return puts("0"), 0;
	for (int i = 1; i <= n; i++) for (int j = 0; j < 5; j++) scanf("%d", &a[j][i]);
	VI ret;
	for (int i = 1; i <= n; i++) {
		bool flg = 1;
		for (int j = 1; flg && j <= n; j++) {
			if (i == j) continue;
			for (int k = j+1; flg && k <= n; k++) {
				if (i == k) continue;
				if (calc(i, j, k) > 0) flg = 0;
			}
		}
		if (flg) ret.push_back(i);
	}
	cout << ret.size() << endl;
	for (int i = 0; i < ret.size(); i++) printf("%d ", ret[i]);
	puts("");
	return 0;
}