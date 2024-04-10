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

map<long long, long long> f, g;

void solve(long long N) {
	if (N < 2) {
		f[N] = 1;
		g[N] = (N == 1);
		return;
	}
	solve(N / 2);
	f[N] = f[N/2] * 2 + 1;
	g[N] = g[N/2] * 2 + (N & 1);
}

long long get(long long N, long long R) {
	if (R == 0) return 0;
	if (R == f[N]) return g[N];
	if (f[N/2] >= R) return get(N/2, R);
	if (R == f[N/2] + 1) return g[N/2] + (N & 1);
	return g[N/2] + (N & 1) + get(N/2, R - f[N/2] - 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	long long N, L, R; cin >> N >> L >> R;
	solve(N);
	cout << get(N, R) - get(N, L-1) << endl;
	return 0;
}