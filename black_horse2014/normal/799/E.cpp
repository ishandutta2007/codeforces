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

const int MAXN = 222222;

int a[MAXN];
int s[MAXN];

long long sum[4][MAXN];
vector<int> V[4];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int N, M, K; scanf("%d%d%d", &N, &M, &K);
	if (M < K) {
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
	for (int j = 0; j < 2; j++) {
		int A; scanf("%d", &A);
		if (A < K) {
			puts("-1");
			return 0;
		}
		for (int i = 1; i <= A; i++) {
			int id; scanf("%d", &id); s[id] |= bit(j);
		}
	}
	for (int i = 1; i <= N; i++) V[s[i]].push_back(a[i]);
	for (int i = 0; i < 4; i++) {
		sort(all(V[i]));
		long long cur = 0;
		for (int j = 0; j < sz(V[i]); j++) sum[i][j] = cur, cur += V[i][j];
		sum[i][sz(V[i])] = cur;
	}
	long long ans = 1LL<<60;
	for (int i = max(0, max(2 * K - M, max(K - sz(V[1]), K - sz(V[2])))); i <= M && i <= sz(V[3]); i++) {
		long long cur = sum[3][i];
		if (i < K) cur += sum[2][K-i] + sum[1][K-i];
		int lo = 0, hi = 1e9+7;
		while (hi - lo > 1) {
			int mid = lo + hi >> 1;
			int cnt = 0;
			for (int j = 0; j <= 2; j++) cnt += max(0, (int)(upper_bound(all(V[j]), mid) - V[j].begin()) - ((j > 0) * max(K-i, 0)));
			if (cnt >= M-i-max(K-i,0)*2) {
				hi = mid;
			} else {
				lo = mid;
			}
		}
		if (hi == 1e9 + 7) continue;
		int cnt = M-i-2*max(0,K-i);
		for (int j = 0; j <= 2; j++) {
			int temp = lower_bound(all(V[j]), hi) - V[j].begin();
			cnt -= max(0, temp - ((j > 0) * max(K-i, 0)));
			if (j > 0) cur += sum[j][max(temp, max(K-i, 0))] - sum[j][max(K-i, 0)];
			else cur += sum[j][temp];
		}
		if (cnt > 0) cur += 1LL * hi * cnt;
		chkmin(ans, cur);
	}
	if (ans == (1LL<<60)) puts("-1");
	else printf("%lld\n", ans);
	return 0;
}