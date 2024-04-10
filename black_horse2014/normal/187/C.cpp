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

const int MAXN = 111111;

int chk[MAXN];
int dis[MAXN];
int val[MAXN];

vector<int> adj[MAXN];

int n, m, p;
int S, T;

struct data {
	int u, d1, d2;
	data(int u = 0, int d1 = 0, int d2 = 0) : u(u), d1(d1), d2(d2) {}
	bool operator<(const data &rhs) const {
		if (d1 != rhs.d1) return d1 > rhs.d1;
		return d2 > rhs.d2;
	}
};

priority_queue<data> Q;

int main() {
	
	cin >> n >> m >> p;
	for (int i = 1; i <= p; i++) {
		int x; scanf("%d", &x); chk[x] = 1;
	}
	for (int i = 0; i < m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].pb(v), adj[v].pb(u);
	}
	scanf("%d%d", &S, &T);
	for (int i = 1; i <= n; i++) val[i] = dis[i] = n;
	Q.push(data(S, 0, 0)), val[S] = 0;
	while (!Q.empty()) {
		data cur = Q.top(); Q.pop();
		int u = cur.u, d1 = cur.d1, d2 = cur.d2;
		if (d2 >= dis[u]) continue;
		dis[u] = d2;
		if (chk[u]) d2 = 0;
		if (u == T) {
			printf("%d\n", d1);
			return 0;
		}
		for (int i = 0; i < sz(adj[u]); i++) {
			int v = adj[u][i];
			int nd1 = max(d1, d2 + 1), nd2 = d2 + 1;
			if (nd1 >= val[v] && nd2 >= dis[v]) continue;
			if (nd1 < val[v]) {
				val[v] = nd1;
				Q.push(data(v, nd1, nd2));
			} else {
				Q.push(data(v, nd1, nd2));
			}
		}
	}
	puts("-1");
	return 0;
}