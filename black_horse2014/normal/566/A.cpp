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

int m = 1;
long long ans;

VPII ret;

const int MAXM = 810000;

char s[MAXM];
int next[MAXM][26];

VI A[MAXM], B[MAXM];

void dfs(int u, int d) {
	for (int i = 0; i < 26; i++) {
		int v = next[u][i];
		if (v) {
			dfs(v, d + 1);
			for (int j = 0; j < sz(A[v]); j++) A[u].push_back(A[v][j]);
			for (int j = 0; j < sz(B[v]); j++) B[u].push_back(B[v][j]);
//			A[v].clear(), B[v].clear();
		}
	}
	int cnt = min(sz(A[u]), sz(B[u]));
	ans += 1LL * d * cnt;
	for (int j = 0; j < cnt; j++) {
		ret.push_back(make_pair(A[u].back(), B[u].back()));
		A[u].pop_back(), B[u].pop_back();
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 1; i <= 2*n; i++) {
		scanf("%s", s);
		int u = 1;
		for (int j = 0; s[j]; j++) {
			int c = s[j] - 'a';
			int &v = next[u][c];
			if (!v) v = ++m;
			u = v;
		}
		if (i <= n) A[u].push_back(i);
		else B[u].push_back(i-n);
	}
	dfs(1, 0);
	cout << ans << endl;
	for (int i = 0; i < n; i++) printf("%d %d\n", ret[i].first, ret[i].second);
	return 0;
}