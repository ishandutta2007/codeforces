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

const int MAXN = 110000;

int id[MAXN], sx[MAXN], sy[MAXN], d[MAXN], ansx[MAXN], ansy[MAXN];

bool cmp(int u, int v) {
	if (sx[u] + sy[u] != sx[v] + sy[v]) return sx[u] + sy[u] < sx[v] + sy[v];
	return sx[u] < sx[v];
}

bool cmp1(int u, int v) {
	if (d[u] != d[v]) return d[u] < d[v];
	if (d[u] == 1) return sx[u] < sx[v];
	else return sy[u] > sy[v];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, w, h; cin >> n >> w >> h;
	for (int i = 0; i < n; i++) {
		int p, t; scanf("%d%d%d", &d[i], &p, &t);
		if (d[i] == 1) {
			sx[i] = p, sy[i] = -t;
		} else {
			sy[i] = p, sx[i] = -t;
		}
		id[i] = i;
	}
	sort(id, id + n, cmp);
	for (int i = 0, j; i < n; i = j) {
		vector<int> V;
		for (j = i; j < n && sx[id[i]] + sy[id[i]] == sx[id[j]] + sy[id[j]]; j++) V.push_back(id[j]);
		sort(all(V), cmp1);
		for (j = i; j < n && sx[id[i]] + sy[id[i]] == sx[id[j]] + sy[id[j]]; j++) {
			int u = V[j - i];
			if (d[u] == 1) ansx[id[j]] = sx[u], ansy[id[j]] = h;
			else ansx[id[j]] = w, ansy[id[j]] = sy[u];
		}
	}
	for (int i = 0; i < n; i++) printf("%d %d\n", ansx[i], ansy[i]);
	return 0;
}