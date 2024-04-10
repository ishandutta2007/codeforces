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

int chk[26], seen[26];

char str[110], words[110];

int main() {
	int n; scanf("%d%s", &n, str);
	for (int i = 0; i < n; i++) {
		if (str[i] == '*') continue;
		seen[str[i] - 'a'] = 1;
	}
	int m; scanf("%d", &m);
	for (int i = 0; i < 26; i++) chk[i] = !seen[i];
	for (int i = 0; i < m; i++) {
		scanf("%s", words);
		bool flg = 1;
		int state = 0;
		for (int j = 0; flg && j < n; j++) {
			if (str[j] != '*') {
				if (str[j] != words[j]) flg = 0;
			} else {
				if (seen[words[j] - 'a']) flg = 0;
				state |= 1<<(words[j]-'a');
			}
		}
		if (!flg) continue;
		for (int j = 0; j < 26; j++) chk[j] &= state >> j & 1;
	}
	int ans = 0;
	for (int j = 0; j < 26; j++) ans += chk[j];
	cout << ans << endl;
	return 0;
}