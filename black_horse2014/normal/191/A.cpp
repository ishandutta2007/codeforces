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

int f[26][26], g[26][26];

int main() {
	
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		char s[111]; scanf("%s", s);
		int l = strlen(s);
		int c1 = s[0] - 'a', c2 = s[l-1] - 'a';
		for (int j = 0; j < 26; j++) {
			g[j][c2] = 0;
			if (j == c1 || f[j][c1] != 0) {
				chkmax(g[j][c2], f[j][c1] + l);
			}
		}
		for (int j = 0; j < 26; j++) chkmax(f[j][c2], g[j][c2]);
	}
	int ans = 0;
	for (int i = 0; i < 26; i++) chkmax(ans, f[i][i]);
	cout << ans << endl;
	return 0;
}