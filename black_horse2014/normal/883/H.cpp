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

const int MAXN = 4e5 + 10;

char str[MAXN];

char a[MAXN];
char b[MAXN];

int cnt[256];

void print(int n, int m) {
	for (int j = 0; j < n/m; j++) {
		int len = 0;
		for (int k = 0; len < m/2 && k < 256; k++) {
			while (cnt[k] > 1 && len < m/2) a[len++] = k, cnt[k] -= 2;
		}
		int odd = 0, even = 0;
		for (int k = 1; k < 256; k++) {
			if (cnt[k] & 1) {
				odd = k;
				break;
			} else if (cnt[k] > 0) {
				even = k;
			}
		}
		if (!odd) odd = even;
		for (int k = 0; k < m/2; k++) putchar(a[k]);
		if (m & 1) {
			putchar((char)odd);
			cnt[odd]--;
		}
		for (int k = m/2-1; k >= 0; k--) putchar(a[k]);
		putchar(' ');
	}
}

int main() {
	int n; scanf("%d%s", &n, str);
	for (int i = 0; str[i]; i++) cnt[str[i]]++;
	int sum = 0;
	for (int i = 0; i < 256; i++) sum += cnt[i] & 1;
	for (int i = 1; i <= n; i++) if (n % i == 0) {
		int m = n / i;
		if (m & 1) {
			if (sum > i) continue;
			if (sum + i & 1) continue;
		} else {
			if (sum) continue;
		}
		printf("%d\n", i);
		print(n, m);
		return 0;
	}
	return 0;
}