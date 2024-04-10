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

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	if (n % 4 == 2 || n % 4 == 3) {
		puts("NO");
		return 0;
	}
	puts("YES");
	for (int i = n % 4 + 1; i < n; i += 4) {
		for (int x = i; x < i + 4; x += 2) {
			for (int j = 1; j < i; j++) {
				printf("%d %d\n", j, x);
			}
			printf("%d %d\n", x, x + 1);
			for (int j = i - 1; j > 0; j--) {
				printf("%d %d\n", j, x + 1);
			}
		}
		printf("%d %d\n", i, i + 3);
		printf("%d %d\n", i + 1, i + 2);
		printf("%d %d\n", i, i + 2);
		printf("%d %d\n", i + 1, i + 3);
	}
	return 0;
}