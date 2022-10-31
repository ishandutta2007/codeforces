#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
#include <complex>
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

int id[111], chk[111];
char s[111][111], ans[111];

int main() {
	
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) scanf("%s", s[i]);
	int L = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d", &id[i]), id[i]--;
		if (!i) L = strlen(s[id[i]]);
		else if (L != strlen(s[id[i]])) {
			puts("No");
			return 0;
		}
	}
	for (int i = 0; i < L; i++) {
		char x = 0;
		bool flg = 1;
		for (int j = 0; j < m; j++) {
			if (!j) x = s[id[j]][i];
			else if (x != s[id[j]][i]) {
				flg = 0;
				break;
			}
		}
		if (flg) ans[i] = x;
		else ans[i] = '?';
	}
	ans[L] = 0;
	for (int i = 0; i < m; i++) chk[id[i]] = 1;
	for (int i = 0; i < n; i++) if (!chk[i]) {
		if (strlen(s[i]) != L) continue;
		bool flg = 1;
		for (int j = 0; flg && j < L; j++) {
			if (s[i][j] != ans[j] && ans[j] != '?') flg = 0;
		}
		if (flg) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	puts(ans);
	return 0;
}