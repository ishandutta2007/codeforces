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

int n;

int ans[1111];
int a[1111];
int chk[1111];

int main() {
	scanf("%d", &n);
	int T = 0;
	for (int i = 1; i <= n; i++) ans[i] = 1<<30;
	for (int i = 0; i < 10; i++) {
		VI V[2];
		for (int j = 1; j <= n; j++) {
			V[j >> i & 1].push_back(j);
		}
		for (int j = 0; j < 2; j++) {
			if (V[j].empty()) continue;
			printf("%d\n", V[j].size());
			++T;
			for (int k = 0; k < V[j].size(); k++) {
				printf("%d%c", V[j][k], k < sz(V[j])-1 ? ' ' : '\n');
				chk[V[j][k]] = T;
			}
			puts("");
			fflush(stdout);
			for (int k = 1; k <= n; k++) {
				scanf("%d", &a[k]);
				if (chk[k] < T) chkmin(ans[k], a[k]);
			}
		}
	}
	puts("-1");
	for (int i = 1; i <= n; i++) {
		printf("%d%c", ans[i] , i < n ? ' ' : '\n');
	}
	return 0;
}