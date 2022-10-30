#include <bits/stdc++.h>
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

#define prev asdf
#define next asdf1

const int MAXN = 2e5 + 10;

int last[100], next[MAXN], prev[MAXN], a[MAXN];
map<int, int> H;

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		chkmax(prev[i], H[a[i]]);
		for (int j = 0; j < 30; j++) {
			if (a[i] >> j & 1) last[j] = i;
			else chkmax(prev[i], last[j]);
		}
		H[a[i]] = i;
	}
	for (int i = 0; i < 30; i++) last[i] = n + 1;
	for (int i = n; i > 0; i--) {
		next[i] = n + 1;
		for (int j = 0; j < 30; j++) {
			if (a[i] >> j & 1) last[j] = i;
			else chkmin(next[i], last[j]);
		}
	}
	long long ans = 1LL * n * (n + 1) / 2;
	for (int i = 1; i <= n; i++) ans -= 1LL * (i - prev[i]) * (next[i] - i);
	cout << ans << endl;
	return 0;
}