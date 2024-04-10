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

const int MAGIC = 35000;
const int MAXN = 111111;

int pw[MAXN], a[MAXN];

int modExp(int a, int n, int p) {
	int ret = 1;
	for (; n; n >>= 1, a = (LL)a * a % p) if (n & 1) ret = (LL)ret * a % p;
	return ret;
}

int main() {
	int M, N; cin >> M >> N;
	if (N == M) {
		puts("0 1");
		return 0;
	}
	int s = 0;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &a[i]);
		s = (s + a[i]) % M;
	}
	sort(a + 1, a + N + 1);
	if (N == 1) {
		printf("%d %d\n", a[1], 0);
		return 0;
	}
	s = (LL)s * modExp(N, M-2, M) % M;
	int t = 1;
	vector<int> V;
	if (N % 2 == 0) {
		for (int i = 1; i <= N; i++) t = 1LL * t * (a[i] - s + M) % M;
		if (t == 0) {
			puts("-1");
			return 0;
		}
		for (int i = 1; i < N; i += 2) t = 1LL * t * modExp(i, M-3, M) % M;
		t = 1LL * t * modExp(2, N, M) % M;
		if (N % 4 == 2) t = (M - t) % M;
	} else {
		bool flg = 0;
		for (int i = 1; i <= N; i++) {
			if (a[i] == s) {
				flg = 1;
				continue;
			}
			t = 1LL * t * (a[i] - s + M) % M;
		}
		if (!flg) {
			puts("-1");
			return 0;
		}
		for (int i = 1; i <= N/2; i++) t = 1LL * t * modExp(i, M-3, M) % M;
		if (N % 4 == 3) t = (M - t) % M;
	}
	int E = N/2*2;
	for (int i = 2; i <= N; i++) {
		int d = (a[i] - a[1] + M) % M;
		if (modExp(d, E, M) == t) V.push_back(d);
	}
	for (int j = 0; j < sz(V); j++) {
		int d = V[j];
		int st;
		if (N % 2 == 0) st = (s + 1LL * (M - d) * (N - 1) % M * modExp(2, M-2, M)) % M;
		else st = (s + 1LL * (M - d) * (N / 2) % M) % M;
		bool flg = 1;
		for (int i = 0; flg && i < N; i++) {
			if (!binary_search(a + 1, a + N + 1, (st + 1LL * d * i) % M)) {
				flg = 0;
				break;
			}
		}
		if (flg) {
			printf("%d %d\n", st, d);
			return 0;
		}
	}
	puts("-1");
	return 0;
}