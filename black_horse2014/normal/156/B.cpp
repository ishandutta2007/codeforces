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

const int MAXN = 111111;

int a[MAXN], b[MAXN], c[MAXN], chk[MAXN];
char s[155];

int main() {
	
	int n, m; cin >> n >> m;
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%s", s);
		int u = atoi(s+1);
		if (s[0] == '+') a[u]++, b[i] = 1;
		else tot++, a[u]--, b[i] = -1;
		c[i] = u;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (tot + a[i] == m) chk[i] = 1, cnt++;
	}
	for (int i = 1; i <= n; i++) {
		if (b[i] > 0) {
			if (!chk[c[i]]) {
				puts("Lie");
			} else if (cnt > 1) {
				puts("Not defined");
			} else {
				puts("Truth");
			}
		} else {
			if (!chk[c[i]]) {
				puts("Truth");
			} else if (cnt > 1) {
				puts("Not defined");
			} else {
				puts("Lie");
			}
		}
	}
	return 0;
}