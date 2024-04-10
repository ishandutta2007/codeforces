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

const char str[] = "ULDR";

const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};

int a[2], b[2];

int main() {
	
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		char s[10]; scanf("%s", s);
		if (!strcmp(s, "UL")) {
			a[0]++, b[0]++;
			a[1]++, b[1]--;
		} else if (!strcmp(s, "DR")) {
			a[0]--, b[0]--;
			a[1]++, b[1]--;
		} else if (!strcmp(s, "UR")) {
			a[1]++, b[1]++;
			a[0]++, b[0]--;
		} else if (!strcmp(s, "DL")) {
			b[1]--, a[1]--;
			a[0]++, b[0]--;
		} else {
			a[0]++, b[0]--;
			a[1]++, b[1]--;
		}
	}
	long long ans = 1LL * ((a[0] - b[0]) / 2 + 1) * ((a[1] - b[1]) / 2 + 1);
	cout << ans << endl;
	return 0;
}