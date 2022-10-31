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

bool solve(long long a, long long b) {
	if (a > b) swap(a, b);
	if (!a) return 0;
	if (!solve(a, b % a)) return 1;
	long long d = b / a - 1;
	if (a & 1) return d & 1;
	d %= (a + 1);
	if (d == 1 || d == a) return 1;
	return d & 1;
}

int main() {
	
	int ncase;
	for (scanf("%d", &ncase); ncase--; ) {
		long long n, m; scanf("%lld%lld", &n, &m);
		if (solve(n, m)) {
			puts("First");
		} else {
			puts("Second");
		}
	}
	return 0;
}