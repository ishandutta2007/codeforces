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

long long X[2], A, B;

int main() {
	scanf("%lld%lld%lld%lld", &X[0], &X[1], &A, &B);
	if (X[1] >= X[0] + A && X[1] <= X[0] + B) {
		puts("FIRST");
		printf("%lld\n", X[1]);
		return 0;
	}
	if (A <= 0 && B >= 0) {
		puts("DRAW");
		return 0;
	}
	long long C = A + B;
	if (C < 0) {
		C = -C;
		if (X[1] < X[0]) {
			if ((X[0] - X[1]) % C >= -B && (X[0] - X[1]) % C <= -A) {
				long long d = (X[0] - X[1]) % C;
				puts("FIRST");
				printf("%lld\n", X[0] - d);
			} else if ((X[0] - X[1]) % C == 0) {
				puts("SECOND");
			} else {
				puts("DRAW");
			}
			return 0;
		}
		puts("DRAW");
		return 0;
	}
	if (X[1] < X[0]) {
		puts("DRAW");
		return 0;
	}
	if ((X[1] - X[0]) % C == 0) {
		puts("SECOND");
	} else if ((X[1] - X[0]) % C >= A && (X[1] - X[0]) % C <= B) {
		long long d = (X[1] - X[0]) % C;
		puts("FIRST");
		printf("%lld\n", X[0] + d);
	} else {
		puts("DRAW");
	}
	return 0;
}