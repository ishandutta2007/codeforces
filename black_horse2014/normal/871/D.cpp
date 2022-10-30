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

const int MAXN = 1e7 + 10;

int p[MAXN], phi[MAXN], cnt[MAXN], prm[MAXN], prn;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	long long ans = 0;
	for (int i = 2; i <= n; i++) {
		if (!p[i]) {
			p[i] = i;
			phi[i] = i-1;
			prm[prn++] = i;
		}
		int k = min(n / i, p[i]);
		for (int j = 0; j < prn && prm[j] <= k; j++) {
			p[prm[j] * i] = prm[j];
			phi[prm[j] * i] = phi[i] * (prm[j] - (prm[j] < p[i]));
		}
		ans -= 2 * (i - 1 - phi[i]);
	}
	for (int i = 2; i <= n; i++) cnt[p[i]]++;
	for (int i = 2; i <= n; i++) cnt[i] += cnt[i-1];
	int tot = n - 1;
	for (int i = 2; i <= n; i++) if (p[i] * 2 > n) tot--;
	for (int i = 2; i <= n; i++) {
		if (p[i] * 2 > n) continue;
		ans += 3 * (tot - 1) - (cnt[n / p[i]] - (1LL * p[i] * p[i] <= n));
	}
	cout << ans / 2 << endl;
	return 0;
}