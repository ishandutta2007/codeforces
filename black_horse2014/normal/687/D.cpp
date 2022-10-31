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

const int MX = 1111;
int L[MX], R[MX], f[MX], c[MX], sz[MX];

struct Edge {
	int u, v, w, id;
	Edge(int u = 0, int v = 0, int w = 0, int id = 0) : u(u), v(v), w(w), id(id) {}
	bool operator<(const Edge &rhs) const {
		return w > rhs.w;
	}
}E[MX*MX];

int get(int u) {
	return f[u] == 0 ? u : f[u] = get(f[u]);
}

vector<int> V[MX];

int main() {
	int n, m, q; cin >> n >> m >> q;
	for (int i = 1; i <= m; i++) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		E[i] = Edge(u, v, w, i);
	}
	sort(E + 1, E + m + 1);
	for (int j = 1; j <= q; j++) {
		scanf("%d%d", &L[j], &R[j]);
		memset(f, 0, sizeof f);
		memset(c, 0, sizeof c);
		for (int i = 1; i <= n; i++) {
			V[i].clear();
			V[i].push_back(i);
			sz[i] = 1;
		}
		int ans = 0;
		for (int i = 1; i <= m; i++) {
			int u = E[i].u, v = E[i].v, w = E[i].w, id = E[i].id;
			if (L[j] <= id && id <= R[j]) {
				int x = get(u), y = get(v);
				if (x == y) {
					if (c[u] == c[v]) {
						ans = w;
						break;
					}
				} else {
					int dd = c[u]^c[v]^1;
					if (sz[x] < sz[y]) {
						swap(x, y);
					}
					for (int j = 0; j < sz[y]; j++) {
						V[x].push_back(V[y][j]);
						c[V[y][j]] ^= dd;
					}
					V[y].clear();
					f[y] = x, sz[x] += sz[y];
				}
			}
		}
		if (!ans) {
			puts("-1");
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
}