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

const int MAXN = 2000000 + 10;

long long cnt[MAXN], sum[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int N, X, Y; cin >> N >> X >> Y;
	for (int i = 0, x; i < N; i++) {
		scanf("%d", &x), cnt[x]++;
	}
	for (int i = 1; i <= 2000000; i++) sum[i] = sum[i-1] + i * cnt[i];
	for (int i = 1; i <= 2000000; i++) cnt[i] += cnt[i-1];
	long long ans = 1LL<<60;
	for (int i = 2; i <= 1000000; i++) {
		long long ret = 0;
		for (int j = 0; j < 1000000; j += i) {
			int mid = j+i-min(i-1, X/Y)-1;
			ret += 1LL * Y * ((cnt[j+i] - cnt[mid]) * (j+i) - (sum[j+i] - sum[mid])) + 1LL * X * (cnt[mid] - cnt[j]);
		}
		chkmin(ans, ret);
	}
	cout << ans << endl;
	return 0;
}