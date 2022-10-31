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

const int MAXN = 1100000;

int p[MAXN], C[MAXN], r[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int N, M, A, Q;
	cin >> N >> M >> A >> Q;
	int P = 0;
	for (int i = 0, cur = 1; P == 0; cur = 1LL * cur * A % Q, i++) {
		p[i] = cur;
		if (i > 0 && cur == 1) P = i;
	}
	r[1] = 1;
	for (int i = 2; i <= M; i++) r[i] = (LL)(P - r[P % i]) * (P / i) % P;
	for (int i = 0, cur = 1; i <= M; i++) C[i] = ((i == 0 ? 0 : C[i-1]) + cur) % P, cur = 1LL * cur * (M - i) % P * r[i+1] % P;
	for (int i = 0; i < N; i++) printf("%d ", p[C[min(M, N-1-i)]]);
	puts("");
	return 0;
}