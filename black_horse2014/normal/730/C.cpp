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

int n, m, C;
LL ret;
set<int> S;

const int MAXN = 222222;

int cnt[MAXN], val[MAXN], cst[MAXN], q[MAXN], dis[MAXN];
VI adj[MAXN], con[MAXN];

void process(int k) {
	int temp = cnt[k];
	if (C > 0) {
		int cur = min(C, temp);
		ret += (LL)cur * cst[k];
		S.insert(-cst[k]);
		val[cst[k]] += cur;
		C -= cur;
		temp -= cur;
	}
	if (C == 0) {
		while (!S.empty() && temp) {
			set<int> :: iterator it = S.begin();
			int ccst = -(*it);
			if (cst[k] >= ccst) break;
			int cur = min(temp, val[ccst]);
			ret += (LL)cur * (cst[k] - ccst);
			val[ccst] -= cur;
			if (val[ccst] == 0) S.erase(it);
			S.insert(-cst[k]);
			val[cst[k]] += cur, temp -= cur;
		}
	}
}

int main() {
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v), adj[v].push_back(u);
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int u; scanf("%d%d%d", &u, &cnt[i], &cst[i]);
		con[u].push_back(i);
	}
	int Q; cin >> Q;
	for (int i = 0; i < Q; i++) {
		int s, L; scanf("%d%d%d", &s, &C, &L); S.clear();
		for (int j = 1; j <= m; j++) val[cst[j]] = 0;
		for (int j = 1; j <= n; j++) dis[j] = -1;
		int h = 0, t = 0; q[t++] = s; dis[s] = 0;
		ret = 0;
		bool found = 0;
		while (h < t) {
			int u = q[h++];
			for (int j = 0; j < con[u].size(); j++) process(con[u][j]);
			if (!C && ret <= L) {
				printf("%d\n", dis[u]);
				found = 1;
				break;
			}
			for (int j = 0; j < adj[u].size(); j++) {
				int v = adj[u][j];
				if (!~dis[v]) {
					dis[v] = dis[u] + 1;
					q[t++] = v;
				}
			}
		}
		if (!found) puts("-1");
	}
	return 0;
}