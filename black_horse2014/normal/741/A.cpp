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

int a[111], chk[111];

int main() {
	
	int n; cin >> n;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) if (a[i] == a[j]) {
			puts("-1");
			return 0;
		}
	}
	long long ans = 1;
	for (int i = 1; i <= n; i++) {
		if (!chk[i]) {
			long long len = 0;
			for (int j = i; !chk[j]; chk[j] = 1, len++, j = a[j]);
			ans /= __gcd(len, ans);
			ans *= len;
		}
	}
	if (ans % 2 == 0) ans /= 2;
	cout << ans << endl;
	return 0;
}