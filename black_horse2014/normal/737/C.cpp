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

int a[222222], cnt[222222];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, s; cin >> n >> s;
	int cur = 0, d = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (s == i) {
			if (a[i] != 0) cur++;
		} else {
			if (a[i] == 0) cur++;
			cnt[a[i]]++;
			chkmax(d, a[i]);
		}
	}
	if (n == 1) {
		cout << cur << endl;
		return 0;
	}
	int tot = n - 1, sum = 0, ans = n-1;
	for (int i = 1; i <= d; i++) {
		tot -= cnt[i];
		if (!cnt[i]) sum++;
		chkmin(ans, max(tot, sum));
	}
	printf("%d\n", ans + (a[s] != 0));
	return 0;
}