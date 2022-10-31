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

int cnt[111], seen[111], ans[111];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int N, K, M, A; scanf("%d%d%d%d", &N, &K, &M, &A);
	for (int i = 1; i <= A; i++) {
		int x; scanf("%d", &x); cnt[x]++; seen[x] = i;
	}
	for (int i = 1; i <= N; i++) ans[i] = 3;
	for (int i = 1; i <= N; i++) {
		int pos = (M == A ? seen[i] : M);
		if (cnt[i] + M - A == 0) continue;
		int tot = 0;
		for (int j = 1; j <= N; j++) {
			if (i != j && cnt[j] > cnt[i] + M - A || (cnt[j] == cnt[i] + M - A && seen[j] < pos)) tot++;
		}
		if (tot < K) ans[i] = (A != M) + 1;
	}
	for (int i = 1; i <= N; i++) if (ans[i] == 2 && cnt[i]) {
		if (K == N) {
			ans[i] = 1;
			continue;
		}
		int tot = 0;
		VI V;
		for (int j = 1; j <= N; j++) if (j != i) {
			if (cnt[j] > cnt[i] || (cnt[i] == cnt[j] && seen[j] < seen[i])) tot++;
			else V.push_back(cnt[i]+1-cnt[j]);
		}
		sort(V.begin(), V.end());
		int sum = 0;
		for (int j = 0; j < K-tot; j++) sum += V[j];
		if (tot < K && sum > M-A) ans[i] = 1;
	}
	for (int i = 1; i <= N; i++) printf("%d ", ans[i]);
	return 0;
}