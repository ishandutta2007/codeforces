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

char s[2][333333];
char str[333333];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%s%s", s[0], s[1]);
	int n = strlen(s[0]);
	sort(s[0], s[0] + n);
	sort(s[1], s[1] + n);
	reverse(s[1], s[1] + n);
	int i = 0, j = 0;
	int k = 0;
	while (k < n && s[0][i] < s[1][j]) {
		if (k % 2 == 0) str[k++] = s[0][i++];
		else str[k++] = s[1][j++];
	}
	if (k < n) {
		if (k + n & 1) {
			while (k < n) {
				if (k & 1) str[k++] = s[1][j++];
				else str[k++] = s[0][i++];
			}
		} else {
			while (k < n) {
				if (k & 1) str[k++] = s[0][i++];
				else str[k++] = s[1][j++];
			}
		}
	}
	puts(str);
	return 0;
}