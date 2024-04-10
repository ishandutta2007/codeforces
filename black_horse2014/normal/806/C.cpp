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

long long a[110000];

int b[41], cnt[41], cnt1[42];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++) {
		long long x = a[i];
		for (int j = 0; j < 41; j++) if (bitl(j) >= x) {
			if (bitl(j) > x) cnt1[j]++;
			else cnt[j]++;
			break;
		}
	}
	bool found = 0;
	for (int k = 0; k <= cnt[0]; k++) {
		int cur = k;
		for (int j = 0; j < 41; j++) chkmin(cur, cnt[j]), b[j] = cur;
		int sum = 0;
		bool flg = 1;
		for (int j = 40; flg && j >= 0; j--) {
			sum += cnt1[j+1];
			sum += cnt[j] - b[j];
			if (sum > b[j]) flg = 0;
		}
		if (flg) printf("%d ", k), found = 1;
	}
	if (!found) puts("-1");
	return 0;
}