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

char s[111][111];
int a[111], b[111], c[10];
int a1[111], b1[111];

int main() {
	
	int n, m, p; cin >> n >> m >> p;
	for (int i = 0; i < n; i++) scanf("%s", s[i]);
	int f1 = 0, f2 = 0;
	if (m == 1) {
		puts("Second");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		a[i] = b[i] = -1;
		a1[i] = b1[i] = -1;
		for (int j = 0; j < m; j++) {
			if (s[i][j] == 'G') {
				if (!~a[i]) a[i] = j;
				else a1[i] = j;
			}
			if (s[i][j] == 'R') {
				if (!~b[i]) b[i] = j;
				else b1[i] = j;
			}
		}
		if (!~a[i] && !~b[i]) continue;
		if (!~b[i]) f1++;
		if (!~a[i]) f2++;
	}
	if (m == 2) {
		for (int i = 0; i < n; i++) {
			if (~a[i] && ~a1[i]) f1--, a[i] = a1[i] = -1;
			if (~b[i] && ~b1[i]) f2--, b[i] = b1[i] = -1;
		}
	}
	if (f1 && f2) {
		puts("Draw");
		return 0;
	}
	if (f1) {
		puts("First");
		return 0;
	} else if (f2) {
		puts("Second");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (!~a[i] || !~b[i]) continue;
		int d = abs(a[i] - b[i]) - 1;
		for (int j = 7; j >= 0; j--) {
			if (d >> j & 1) c[j]++;
		}
	}
	int flg = 0;
	for (int j = 7; !flg && j >= 0; j--) {
		if (c[j] % (p+1) != 0) {
			flg = 1;
			break;
		}
	}
	if (flg) {
		puts("First");
	} else {
		puts("Second");
	}
	return 0;
}