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

int main() {

	int n, h, d;
	
	scanf("%d%d%d", &n, &d, &h);
	if (2 * h < d) {
		puts("-1");
		return 0;
	}
	if (n > 2 and h == 1 and d == 1) {
		puts("-1");
		return 0;
	}
	if (n == 2 and h == 1 and d == 1) {
		puts("1 2");
		return 0;
	}
	if (h == d) {
		for (int i = 2; i <= h + 1; i++) {
			printf("%d %d\n", i - 1, i);
		}
		for (int i = h + 2; i <= n; i++) {
			printf("2 %d\n", i);
		}
		return 0;
	}
	for (int i = 2; i <= h + 1; i++) {
		printf("%d %d\n", i - 1, i);
	}
	for (int i = h + 2; i <= d + 1; i++) {
		if (i == h + 2) printf("1 %d\n", i);
		else printf("%d %d\n", i - 1, i);
	}
	for (int i = d + 2; i <= n; i++) {
		printf("1 %d\n", i);
	}
	return 0;
}