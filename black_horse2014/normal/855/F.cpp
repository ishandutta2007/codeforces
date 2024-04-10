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

const int N = 100000;
const int M = 320;
const int INF = 1e9 + 7;

vector<PIL> V[2][M];

long long d[2][M], dp[2][N], sum[M];
int A[N], B[N], L[N], R[N];

long long get_sum(int l, int r) {
	int s = l / M;
	long long ret = 0;
	for (int i = l; i < r; i++) {
		long long p = min(d[0][s], dp[0][i]);
		long long q = min(d[1][s], dp[1][i]);
		if (p == INF || q == INF) continue;
		ret += p + q;
	}
	return ret;
}

long long calc(int l, int r) {
	int s = l / M, e = (r-1) / M;
	if (s == e) return get_sum(l, r);
	long long ret = get_sum(l, (s+1)*M) + get_sum(e*M, r);
	for (int i = s+1; i < e; i++) ret += sum[i];
	return ret;
}

void renew(int s) {
	int p0 = 0, q0 = 0;
	sum[s] = 0;
	V[0][s].clear(), V[1][s].clear();
	for (int i = s * M; i < N && i < (s+1) * M; i++) {
		int p = min(d[0][s], dp[0][i]);
		int q = min(d[1][s], dp[1][i]);
		chkmax(p0, p), chkmax(q0, q);
		if (p == INF || q == INF) continue;
		V[0][s].push_back(PIL(p, p)), V[1][s].push_back(PIL(q, q));
		sum[s] += p + q;
	}
	sort(all(V[0][s])), sort(all(V[1][s]));
	for (int i = 1; i < sz(V[0][s]); i++) {
		V[0][s][i].second += V[0][s][i-1].second;
		V[1][s][i].second += V[1][s][i-1].second;
	}
	d[0][s] = p0, d[1][s] = q0;
}

void process(int l, int r, long long k) {
	int flg = (k < 0);
	k = abs(k);
	int s = l / M, e = (r-1) / M;
	if (s == e) {
		for (int i = l; i < r; i++) chkmin(dp[flg][i], k);
		renew(s);
		return;
	}
	for (int i = l; i < (s+1)*M; i++) chkmin(dp[flg][i], k);
	renew(s);
	for (int i = e*M; i < r; i++) chkmin(dp[flg][i], k);
	renew(e);
	for (int i = s+1; i < e; i++) {
		if (d[flg][i] <= k) continue;
		if (d[flg][i] == INF) {
			d[flg][i] = k;
			renew(i);
		} else {
			d[flg][i] = k;
			int j0 = lower_bound(V[0][i].begin(), V[0][i].end(), PIL(d[0][i], 0)) - V[0][i].begin() - 1;
			int j1 = lower_bound(V[1][i].begin(), V[1][i].end(), PIL(d[1][i], 0)) - V[1][i].begin() - 1;
			sum[i] = (j0 == -1 ? 0 : V[0][i][j0].second) + (sz(V[0][i]) - 1 - j0) * d[0][i]
					+ (j1 == -1 ? 0 : V[1][i][j1].second) + (sz(V[1][i]) - 1 - j1) * d[1][i];
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int Q; scanf("%d", &Q);
	for (int i = 0; i < N; i++) dp[0][i] = dp[1][i] = INF;
	for (int i = 0; i < (N-1)/M+1; i++) d[0][i] = d[1][i] = INF;
	for (int i = 0; i < Q; i++) {
		scanf("%d%d%d", &A[i], &L[i], &R[i]), L[i]--, R[i]--;
		if (A[i] == 1) scanf("%d", &B[i]);
	}
	for (int i = 0; i < Q; i++) {
		if (A[i] == 1) process(L[i], R[i], B[i]);
		else printf("%lld\n", calc(L[i], R[i]));
	}
	return 0;
}