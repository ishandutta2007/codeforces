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

char A[1111], B[1111];

int ans[2];
const char pat[] = "RPS";

int main() {
	
	long long n;
	scanf("%lld%s%s", &n, A, B);
	int m = strlen(A), k = strlen(B);
	for (int i = 0; i < m * k; i++) {
		int u = strchr(pat, A[i % m]) - pat;
		int v = strchr(pat, B[i % k]) - pat;
		if (u == v) continue;
		if (u == (v + 1) % 3) {
			ans[1] += n / m / k;
			if (i < n % (m * k)) ans[1]++;
		} else {
			ans[0] += n / m / k;
			if (i < n % (m * k)) ans[0]++;
		}
	}
	cout << ans[0] << ' ' << ans[1] << endl;
	return 0;
}