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

const int MAXN = 4005;

struct Node {
	int c, h, t;
	Node(int c = 0, int h = 0, int t = 0) : c(c), h(h), t(t) {}
	bool operator<(const Node &rhs) const {
		return t < rhs.t;
	}
} a[MAXN];

VI V[22222];

int L[MAXN][MAXN], R[MAXN][MAXN], b[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, p; scanf("%d%d", &n, &p);
	for (int i = 1; i <= n; i++) scanf("%d%d%d", &a[i].c, &a[i].h, &a[i].t);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) V[(a[i].t+p-1)/p].push_back(i);
	for (int i = 1; i <= 9999/p+1; i++) {
		for (int j = 0; j < sz(V[i]); j++) {
			int u = V[i][j];
			if (j == 0) {
				for (int k = 0; k < MAXN; k++) L[u][k] = (k >= a[u].c ? a[u].h : 0);
			} else {
				assert(V[i][j-1] == u-1);
				for (int k = 0; k < MAXN; k++) {
					L[u][k] = L[u-1][k];
					if (k >= a[u].c) chkmax(L[u][k], L[u-1][k - a[u].c] + a[u].h);
				}
			}
		}
		for (int j = sz(V[i])-1; j >= 0; j--) {
			int u = V[i][j];
			if (j == sz(V[i])-1) {
				for (int k = 0; k < MAXN; k++) R[u][k] = (k >= a[u].c ? a[u].h : 0);
			} else {
				assert(V[i][j+1] == u+1);
				for (int k = 0; k < MAXN; k++) {
					R[u][k] = R[u+1][k];
					if (k >= a[u].c) chkmax(R[u][k], R[u+1][k - a[u].c] + a[u].h);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) b[i] = a[i].t;
	int q; scanf("%d", &q);
	while (q--) {
		int x, y; scanf("%d%d", &x, &y);
		int l = upper_bound(b + 1, b + n + 1, x - p) - b;
		int r = upper_bound(b + 1, b + n + 1, x) - b - 1;
		if (l > r) {
			puts("0");
			continue;
		}
		int u = (a[l].t + p - 1) / p, v = (a[r].t + p - 1) / p;
		if (u == v) {
			if (l == V[u][0]) {
				printf("%d\n", L[r][y]);
			} else {
				printf("%d\n", R[l][y]);
			}
		} else {
			int ans = 0;
			for (int j = 0; j <= y; j++) chkmax(ans, R[l][j] + L[r][y - j]);
			printf("%d\n", ans);
		}
	}
	return 0;
}