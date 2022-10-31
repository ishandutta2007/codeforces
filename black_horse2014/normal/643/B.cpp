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

	int n, k;
	int a, b, c, d;
	
	scanf("%d%d", &n , &k);
	scanf("%d%d%d%d", &a, &b, &c, &d);
	if (n == 4) {
		puts("-1");
		return 0;
	}
	if (k <= n) {
		puts("-1");
		return 0;
	}
	printf("%d %d ", a, c);
	for (int i = 1; i <= n; i++) {
		if (i == a or i == b or i == c or i == d) continue;
		printf("%d ", i);
	}
	printf("%d %d\n", d, b);
	printf("%d %d ", c, a);
	for (int i = 1; i <= n; i++) {
		if (i == a or i == b or i == c or i == d) continue;
		printf("%d ", i);
	}
	printf("%d %d\n", b, d);
	return 0;
}