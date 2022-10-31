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

const char vowels[] = "aeiou";

char s[3333];
int dp[3333], pr[3333], chk[3333];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%s", s);
	int n = strlen(s);
	for (int i = 0; i < n; i++) {
		int cmax = -1, cmin = 27, len = 0;
		dp[i+1] = n;
		for (int j = i; j >= 0; j--) {
			if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') {
				cmax = -1, cmin = 27, len = 0;
			}
			else {
				len++;
				cmax = max(cmax, s[j] - 'a');
				cmin = min(cmin, s[j] - 'a');
				if (len >= 3 && cmax != cmin) break;
			}
			chkmin(dp[i+1], dp[j] + 1);
			if (dp[i+1] == dp[j] + 1) {
				pr[i+1] = j;
			}
		}
	}
	int m = n;
	while(m > 0) chk[pr[m]] = 1, m = pr[m];
	for (int i = 0; i < n; i++) {
		putchar(s[i]);
		if (chk[i+1]) putchar(' ');
	}
	puts("");
	return 0;
}