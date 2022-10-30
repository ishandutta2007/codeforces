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
const int MAXM = 22222;

int fst[MAXN], chk[MAXN];
int nxt[MAXM], b[MAXM], cap[MAXM];
long long cost[MAXM];
long long dis[MAXN];
int prv[MAXN], q[MAXN];
int E;

void add(int u, int v, int f, long long w) {
	b[E] = v, cap[E] = f, cost[E] = w, nxt[E] = fst[u], fst[u] = E++;
	b[E] = u, cap[E] = 0, cost[E] = -w, nxt[E] = fst[v], fst[v] = E++;
}

const long long INF = 1LL<<60;

long long MCMF(int S, int T, int n) {
	long long ret = 0;
	while (1) {
		int h = 0, t = 0;
		for (int j = 0; j < n; j++) {
			dis[j] = INF;
			prv[j] = -1;
		}
		dis[S] = 0, q[t++] = S, chk[S] = 1;
		while (h != t) {
			int u = q[h++]; chk[u] = 0;
			if (h == MAXN) h = 0;
			for (int j = fst[u]; ~j; j = nxt[j]) if (cap[j]) {
				int v = b[j];
				if (dis[v] > dis[u] + cost[j]) {
					dis[v] = dis[u] + cost[j], prv[v] = j;
					if (!chk[v]) {
						q[t++] = v;
						if (t == MAXN) t = 0;
					}
				}
			}
		}
		if (!~prv[T]) {
			return ret;
		}
		int flw = 1e9;
		for (int u = T; u != S; u = b[prv[u]^1]) {
			flw = min(flw, cap[prv[u]]);
		}
		ret += dis[T] * flw;
		for (int u = T; u != S; u = b[prv[u]^1]) {
			cap[prv[u]] -= flw, cap[prv[u]^1] += flw;
		}
	}
	return ret;
}

int a[MAXN], c[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	int S = 0, T = 2*n+1;
	memset(fst, -1, sizeof fst);
	for (int i = 0; i < n; i++) {
		add(S, i+1, (i == 0 ? m : 1), 0);
		for (int j = i+1; j <= n; j++) {
			add(i+1, j+n, 1, (a[i] == a[j] ? 0 : c[a[j]]));
		}
	}
	for (int i = n+1; i <= 2*n; i++) add(i, T, 1, 0);
	cout << MCMF(S, T, T + 1) << endl;
	return 0;
}