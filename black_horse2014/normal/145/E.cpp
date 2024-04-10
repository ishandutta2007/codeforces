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

const int MAXN = 1<<21;

char s[MAXN];

int c[2][MAXN];
int a[2][MAXN];
int d[MAXN];

void renew(int u) {
	d[u] ^= 1;
	swap(c[0][u], c[1][u]);
	swap(a[0][u], a[1][u]);
}

void down(int u) {
	if (!d[u]) return;
	renew(u+u), renew(u+u+1);
	d[u] = 0;
}

void up(int u) {
	for (int j = 0; j < 2; j++) c[j][u] = c[j][u+u] + c[j][u+u+1];
	for (int j = 0; j < 2; j++) a[j][u] = max(a[j][u+u] + c[j^1][u+u+1], c[j][u+u] + a[j][u+u+1]);
}

void build(int u, int l, int r) {
	d[u] = 0;
	if (l == r) {
		c[1][u] = (s[l] == '7'), c[0][u] = (s[l] == '4');
		a[1][u] = a[0][u] = 1;
		return;
	}
	int mid = l + r >> 1;
	build(u + u, l, mid);
	build(1 + u + u, mid + 1, r);
	up(u);
}

void update(int u, int l, int r, int ll, int rr) {
	if (ll <= l && r <= rr) {
		renew(u);
		return;
	}
	down(u);
	int mid = l + r >> 1;
	if (ll <= mid) update(u + u, l, mid, ll, rr);
	if (mid < rr) update(u + u + 1, mid + 1, r, ll, rr);
	up(u);
}

int main() {
	
	int n, m; scanf("%d%d%s", &n, &m, s+1);
	build(1, 1, n);
	for (int i = 0; i < m; i++) {
		char t[15];
		scanf("%s", t);
		if (t[0] == 'c') {
			printf("%d\n", a[0][1]);
		} else {
			int l, r; scanf("%d%d", &l, &r);
			update(1, 1, n, l, r);
		}
	}
	return 0;
}