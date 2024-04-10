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

int cnt[2][1024];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m, p; scanf("%d%d%d", &n, &m, &p);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		cnt[0][x]++;
	}
	int now = 0;
	for (int i = 1; i <= m; i++) {
		now ^= 1;
		for (int j = 0; j < 1024; j++) cnt[now][j] = 0;
		int cur = 0;
		for (int j = 0; j < 1024; j++) {
			if (cnt[!now][j]) {
				cnt[now][j ^ p] += (cnt[!now][j] - cur + 1) / 2;
				cnt[now][j] += cnt[!now][j] - (cnt[!now][j] - cur + 1) / 2;
				cur ^= cnt[!now][j] & 1;
			}
		}
	}
	int amin = 1023, amax = 0;
	for (int i = 0; i < 1024; i++) {
		if (cnt[now][i]) amax = i;
	}
	for (int i = 0; i < 1024; i++) {
		if (cnt[now][1023-i]) amin = 1023-i;
	}
	cout << amax << ' ' << amin << endl;
	return 0;
}