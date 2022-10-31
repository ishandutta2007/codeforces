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
	int h, m, s, A, B; scanf("%d%d%d%d%d", &h, &m, &s, &A, &B);
	double a = h % 12 + 1.0 * m / 60 + 1.0 * s / 3600;
	double b = 0.2 * m + 1.0 * s / 300;
	double c = 0.2 * s;
	for (int i = 0; i < 2; i++) {
		bool flg = 1;
		for (int x = A; x != B; x = x % 12 + 1) {
			if (x % 12 <= a && a <= x % 12 + 1) flg = 0;
			if (x % 12 <= b && b <= x % 12 + 1) flg = 0;
			if (x % 12 <= c && c <= x % 12 + 1) flg = 0;
		}
		if (flg) return puts("yes"), 0;
		swap(A, B);
	}
	puts("no");
	return 0;
}