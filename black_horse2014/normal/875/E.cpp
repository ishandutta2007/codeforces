#include <bits/stdc++.h>
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

const int MAXN = 1e5 + 10;

int f[17][MAXN], g[17][MAXN];
int a[MAXN];

int get_min(int l, int r) {
	assert(l <= r);
	int k = 31 - clzi(r-l+1);
	return min(f[k][l], f[k][r-bit(k)+1]);
}

int get_max(int l, int r) {
	assert(l <= r);
	int k = 31 - clzi(r-l+1);
	return max(g[k][l], g[k][r-bit(k)+1]);
}

VI V[MAXN];

bool can(int n, int D) {
	for (int i = 1; i <= n; i++) V[i].clear();
	for (int i = n; i > 0; i--) {
		int lo = i, hi = n+1;
		while (hi - lo > 1) {
			int mid = lo + hi >> 1;
			if (get_min(i, mid) >= a[i] - D && get_max(i, mid) <= a[i] + D) lo = mid;
			else hi = mid;
		}
		V[lo].push_back(i);
	}
	for (int i = n, j = n; i > 1; i--) {
		for (int k = 0; k < sz(V[i]); k++) chkmin(j, V[i][k]);
		if (j == i) return 0;
	}
	return 1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d%d%d", &n, &a[1], &a[2]);
	for (int i = 3; i <= n+2; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n+2; i++) f[0][i] = g[0][i] = a[i];
	for (int i = 1; i <= 16; i++) {
		for (int j = 1; j <= n+2; j++) {
			f[i][j] = f[i-1][j], g[i][j] = g[i-1][j];
			if (j + bit(i-1) <= n+2) {
				chkmin(f[i][j], f[i-1][j+bit(i-1)]);
				chkmax(g[i][j], g[i-1][j+bit(i-1)]);
			}
		}
	}
	int lo = abs(a[1]-a[2])-1, hi = 1e9;
	while (hi - lo > 1) {
		int mid = lo + hi >> 1;
		if (can(n+2, mid)) hi = mid;
		else lo = mid;
	}
	cout << hi << endl;
	return 0;
}