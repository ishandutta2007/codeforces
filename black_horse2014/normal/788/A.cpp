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

const int MAXN = 111111;

int a[MAXN];
long long mx[2], mn[2];
long long s[MAXN], b[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i < n; i++) b[i] = abs(a[i+1] - a[i]);
	mn[0] = mx[0] = 0;
	mn[1] = bitl(60), mx[1] = -bitl(60);
	long long ans = 0;
	for (int i = 1; i < n; i++) {
		if (i & 1) s[i] = s[i-1] + b[i];
		else s[i] = s[i-1] - b[i];
		if (i & 1) {
			chkmax(ans, s[i] - mn[0]);
			chkmax(ans, -(s[i] - mx[1]));
		} else {
			chkmax(ans, -(s[i] - mx[1]));
			chkmax(ans, s[i] - mn[0]);
		}
		chkmax(mx[i&1], s[i]);
		chkmin(mn[i&1], s[i]);
	}
	cout << ans << endl;
	return 0;
}