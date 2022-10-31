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

int a[30];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	int g = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		g = __gcd(g, a[i]);
	}
	if (g % 2 == 1) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] & 1) cnt++;
		}
		if (cnt > 1) {
			puts("0");
			for (int i = 1; i <= n; i++) {
				for (int j = 0; j < a[i]; j++) putchar('a'+i-1);
			}
			return 0;
		}
		cout << g << endl;
		int id = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] & 1) id = i;
		}
		for (int j = 0; j < g; j++) {
			for (int i = 1; i <= n; i++) {
				if (id != i) {
					for (int j = 0; j < a[i]/g/2; j++) putchar('a'+i-1);
				}
			}
			for (int j = 0; j < a[id]/g; j++) putchar('a'+id-1);
			for (int i = n; i >= 1; i--) {
				if (id != i) {
					for (int j = 0; j < a[i]/g/2; j++) putchar('a'+i-1);
				}
			}
		}
		return 0;
	}
	cout << g << endl;
	for (int j = 0; j < g/2; j++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < a[i]/g; j++) putchar('a'+i-1);
		}
		for (int i = n; i >= 1; i--) {
			for (int j = 0; j < a[i]/g; j++) putchar('a'+i-1);
		}
	}
	return 0;
}