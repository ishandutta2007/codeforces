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

const int MAGIC = 300;
const int MAXN = 111111;

int L[MAXN], R[MAXN], QID[MAXN], ans[MAXN];
VI A[MAXN], B[MAXN];

bool cmp(int u, int v) {
	if (L[u] / MAGIC != L[v] / MAGIC) return L[u] / MAGIC < L[v] / MAGIC;
	return R[u] < R[v];
}

struct DSU {
	int n;
	int sz[MAXN], rt[MAXN];
    struct Data {
		Data(){}
		Data(int a, int b, int _sz):a(a), b(b) {sz = _sz;}
		int a, b, sz;
	};
	vector <Data> stk;

	void init(int _n) {
		n = _n;
		for (int i = 1; i <= n; i++)
			rt[i] = i, sz[i] = 1;
		stk.clear();
	}

	int find_root(int u) {
		while (u != rt[u]) u = rt[u];
		return rt[u];
	}

	bool merge(int a, int b, int bf) {
		a = find_root(a), b = find_root(b);
		if (a == b) return 0;
		if (sz[a] < sz[b]) swap(a, b);
		if (bf) stk.pb(Data(a, b, sz[b]));
		sz[a] += sz[b], rt[b] = a;
		return 1;
	}

	void restore() {
		while (!stk.empty()) {
			Data tp = stk.back();
			stk.pop_back();
			sz[tp.a] -= tp.sz, sz[tp.b] = tp.sz;
			rt[tp.b] = tp.b;
		}
	}
} dsu;

int N, K, M, Q, cur;

void init() {
	cur = 0;
	dsu.init(N);
}

void add(int bf, int u, int l, int r) {
	if (bf == 0) {
		for (int j = 0; j < sz(B[u]); j++) {
			int v = B[u][j];
			if (v >= l && v <= r) cur += dsu.merge(u, v, bf);
		}
	} else {
		for (int j = 0; j < sz(A[u]); j++) {
			int v = A[u][j];
			if (v >= l && v <= r) cur += dsu.merge(u, v, bf);
		}
	}
}

void restore() {
	cur -= dsu.stk.size();
	dsu.restore();
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	cin >> N >> K >> M;
	for (int i = 0; i < M; i++) {
		int u, v; scanf("%d%d", &u, &v);
		if (u > v) swap(u, v);
		A[u].push_back(v);
		B[v].push_back(u);
	}
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		scanf("%d%d", &L[i], &R[i]);
		QID[i] = i;
	}
	sort(QID, QID + Q, cmp);
	for (int i = 0, j; i < Q; i = j) {
		int x = L[QID[i]] / MAGIC, l = (x+1) * MAGIC, r = (x+1) * MAGIC;
		init();
		for (j = i; j < Q && L[QID[j]] / MAGIC == x; j++) {
			int k = QID[j];
			while (r <= R[k]) add(0, r, l, r), r++;
			for (int ll = L[k]; ll < l && ll <= R[k]; ll++) add(1, ll, ll, R[k]);
			ans[k] = R[k] - L[k] + 1 - cur;
			restore();
		}
	}
	for (int i = 0; i < Q; i++) printf("%d\n", ans[i]);
	return 0;
}