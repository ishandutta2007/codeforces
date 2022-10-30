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

const int MAXN = 1111;

int id[MAXN], cost[MAXN], tp[MAXN], ret[MAXN];
int chk[MAXN];

VI V[MAXN];

bool cmp(int x, int y) {
	return cost[x] < cost[y];
}

int main() {
	int n, m; cin >> n >> m;
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &cost[i], &tp[i]), id[i] = i;
	}
	sort(id + 1, id + n + 1, cmp);
	int cnt = 0, i;
	long long ans = 0;
	int rem = n;
	for (i = n; i > 0 && cnt < m; i--) {
		int u = id[i];
		if (chk[u]) continue;
		chk[u] = ++cnt;
		rem--;
		if (tp[u] == 2 && rem > m - cnt) {
			int v = 0;
			for (int j = i-1; j > 0; j--) {
				int w = id[j];
				if (chk[w]) continue;
				if (tp[w] == 1) {
					v = w;
					break;
				}
			}
			if (v) {
				chk[v] = cnt;
				rem--;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int u = id[i];
		if (!chk[u]) chk[u] = min(m, ++cnt);
	}
	for (int i = 1; i <= m; i++) ret[i] = 1e9+5;
	for (int i = 1; i <= n; i++) {
		ans += 2 * cost[i];
		chkmin(ret[chk[i]], cost[i]);
		V[chk[i]].push_back(i);
	}
	for (int i = 1; i <= m; i++) {
		bool flg = 0;
		for (int j = 0; !flg && j < V[i].size(); j++) {
			if (tp[V[i][j]] == 1) flg = 1;
		}
		if (flg) ans -= ret[i];
	}
	printf("%.1lf\n", ans*0.5);
	for (int i = 1; i <= m; i++) {
		printf("%d", V[i].size());
		for (int j = 0; j < V[i].size(); j++) printf(" %d", V[i][j]);
		puts("");
	}
	return 0;
}