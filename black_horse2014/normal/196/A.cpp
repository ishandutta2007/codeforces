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

char s[111111];
int next[26][111111];
int seen[26];

int main() {
	
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for (int i = 0; i < 26; i++) seen[i] = n + 1;
	for (int i = n; i > 0; i--) {
		seen[s[i] - 'a'] = i;
		for (int j = 0; j < 26; j++) next[j][i] = seen[j];
	}
	int cur = 1;
	while (cur <= n) {
		bool flg = 0;
		for (int j = 25; j >= 0; j--) {
			if (next[j][cur] <= n) {
				putchar(j + 'a');
				cur = next[j][cur] + 1;
				flg = 1;
				break;
			}
		}
		if (!flg) break;
	}
	puts("");
	return 0;
}