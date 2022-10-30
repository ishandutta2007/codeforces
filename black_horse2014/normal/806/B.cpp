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

int a[5][120], c[5][6], b[5], L[2][5];
int pw[6];
int cnt[30000];

const int INF = 1e9;

int get(int m, int n) {
	for (int i = 1; i < 6; i++) if (m * bit(i) > n) return i;
	return 6;
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &a[j][i]);
			if (a[j][i] >= 0) b[j]++;
		}
	}
	for (int j = 0; j < 6; j++) pw[j] = (j == 0 ? 1 : pw[j-1] * 7);
	for (int s = 0; s < pw[5]; s++) {
		int scr[2] = {0, 0};
		cnt[s] = 1;
		for (int t = s, j = 0; j < 5; j++) {
			int d = t % 7; t /= 7;
			if (d == 0) cnt[s] = 0;
			for (int i = 0; i < 2; i++) if (a[j][i] >= 0) scr[i] += d * 2 

* (250 - a[j][i]);
		}
		if (scr[0] <= scr[1]) cnt[s] = 0;
	}
	for (int i = 0; i < 5; i++) {
		for (int s = 0; s < pw[5]; s++) {
			int x = s / pw[i] % 7;
			if (x > 0) cnt[s] += cnt[s - pw[i]];
		}
	}
	for (int ans = 0; ans <= 32 * n; ans++) {
		for (int j = 0; j < 5; j++) {
			if (a[j][0] == -1) {
				L[0][j] = L[1][j] = b[j];
			} else {
				L[0][j] = b[j], L[1][j] = b[j] + ans;
			}
			L[0][j] = get(L[0][j], ans+n);
			L[1][j] = get(L[1][j], ans+n);
			L[1][j]--;
		}
		int tot = 0;
		for (int s = 0; s < 32; s++) {
			int st = 0;
			for (int j = 4; j >= 0; j--) st *= 7, st += L[s>>j&1][j];
			if (cnti(s) & 1) tot -= cnt[st];
			else tot += cnt[st];
		}
		if (tot > 0) {
			cout << ans << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}