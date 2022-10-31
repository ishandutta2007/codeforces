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

const int MAXN = 222222;

int a[MAXN], b[MAXN], ans[MAXN];
int l[MAXN], r[MAXN], s[MAXN], t[MAXN];
int last[1111][1111];

vector<int> V[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m, q; cin >> n >> m >> q;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a[i], &b[i]);
	}
	for (int i = 0; i < q; i++) {
		scanf("%d%d%d%d", &l[i], &r[i], &s[i], &t[i]);
		V[l[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			last[i][j] = m+1;
		}
	}
	for (int i = m; i > 0; i--) {
		int u = a[i], v = b[i];
		last[u][v] = last[v][u] = i;
		for (int j = 1; j <= n; j++) {
			if (last[u][j] < last[v][j]) {
				last[v][j] = last[u][j];
			} else {
				last[u][j] = last[v][j];
			}
		}
		for (int j = 0; j < sz(V[i]); j++) {
			int k = V[i][j], x = s[k], y = t[k];
			if (last[x][y] <= r[k]) {
				ans[k] = 1;
			} else {
				ans[k] = 0;
			}
		}
	}
	for (int i = 0; i < q; i++) {
		puts(ans[i] ? "Yes" : "No");
	}
	return 0;
}