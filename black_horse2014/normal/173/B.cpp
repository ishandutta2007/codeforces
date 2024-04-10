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

const int MAXN = 2222;

char s[MAXN][MAXN];
vector<int> con[MAXN];
int q[MAXN], qn;
int dis[MAXN];

int main() {
	
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '#') con[i].push_back(j+n), con[j+n].push_back(i);
		}
	}
	q[qn++] = 0, dis[0] = 1;
	for (int i = 0; i < qn; i++) {
		int u = q[i];
		for (int j = 0; j < con[u].size(); j++) {
			int v = con[u][j];
			if (dis[v]) continue;
			dis[v] = dis[u] + 1;
			q[qn++] = v;
		}
	}
	printf("%d\n", dis[n-1]-1);
	return 0;
}