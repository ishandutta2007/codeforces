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

const int MAXN = 1<<19;

int a[MAXN];
double p[MAXN], S[MAXN], L[MAXN], R[MAXN], D[MAXN];

int N, M, C;

void build(int u, int l, int r) {
	if (l == r) {
		S[u] = 0.5 * (a[l+1] - a[l]) - p[l] * C;
		L[u] = R[u] = D[u] = max(S[u], 0.0);
		return;
	}
	int mid = l + r >> 1;
	build(u + u, l, mid);
	build(u + u + 1, mid + 1, r);
	S[u] = S[u + u] + S[u + u + 1];
	D[u] = max(max(D[u + u], D[u + u + 1]), R[u + u] + L[u + u + 1]);
	L[u] = max(L[u + u], S[u + u] + L[u + u + 1]);
	R[u] = max(R[u + u + 1], S[u + u + 1] + R[u + u]);
}

double ans, sum;

void get(int u, int l, int r, int ll, int rr) {
	if (ll <= l && r <= rr) {
		ans = max(ans, max(sum + L[u], D[u]));
		sum = max(R[u], S[u] + sum);
		return;
	}
	int mid = l + r >> 1;
	if (ll <= mid) get(u + u, l, mid, ll, rr);
	if (mid < rr) get(1 + u + u, mid + 1, r, ll, rr);
}

int main() {
	cin >> N >> M >> C;
	for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= N-1; i++) scanf("%lf", &p[i]), p[i] /= 100;
	build(1, 1, N-1);
	double ret = 0;
	for (int i = 0; i < M; i++) {
		int l, r; scanf("%d%d", &l, &r), r--;
		ans = sum = 0;
		get(1, 1, N-1, l, r);
		ret += ans;
	}
	printf("%.10lf\n", ret);
	return 0;
}