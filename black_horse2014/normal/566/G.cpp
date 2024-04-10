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

struct PT {
	int x, y;
	PT(int x = 0, int y = 0) : x(x), y(y) {}
	bool operator<(const PT &p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
} P[MAXN], Q[MAXN];

long long cross(PT p, PT p1, PT p2) {
	return 1LL * (p1.x - p.x) * (p2.y - p.y) - 1LL * (p1.y - p.y) * (p2.x - p.x);
}

vector<PT> R;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m; scanf("%d%d", &n, &m);
	int x, y; scanf("%d%d", &x, &y);
	for (int i = 0; i < n; i++) scanf("%d%d", &P[i].x, &P[i].y);
	for (int i = 0; i < m; i++) scanf("%d%d", &Q[i].x, &Q[i].y);
	sort(Q, Q + m);
	int ymax = 0, xmax = Q[m-1].x;
	for (int i = m-1; i >= 0; i--) {
		if (Q[i].y <= ymax) continue;
		ymax = Q[i].y;
		R.push_back(Q[i]);
	}
	reverse(all(R));
	m = 0;
	for (int i = 0; i < sz(R); i++) {
		while (m > 1 && cross(Q[m-2], Q[m-1], R[i]) >= 0) m--;
		Q[m++] = R[i];
	}
	for (int i = 0; i < n; i++) {
		if (P[i].x >= xmax || P[i].y >= ymax) {
			puts("Max");
			return 0;
		}
		if (P[i].x <= Q[0].x) continue;
		int lo = 0, hi = m-1;
		while (hi - lo > 1) {
			int mid = lo + hi >> 1;
			if (P[i].x > Q[mid].x) lo = mid;
			else hi = mid;
		}
		if (cross(Q[lo], Q[hi], P[i]) >= 0) {
			puts("Max");
			return 0;
		}
	}
	puts("Min");
	return 0;
}