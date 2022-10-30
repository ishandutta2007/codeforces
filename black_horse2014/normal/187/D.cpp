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

int N, G, R, Q, M;

const int MAXN = 1<<18;

long long dp[MAXN];
int seen[MAXN], x[MAXN], xn;
int S[MAXN], next[MAXN];
long long s[MAXN];

void update(int u, int x) {
	u += M;
	for (seen[u] = x, u >>= 1; u; u >>= 1) seen[u] = x;
}

int get(int st, int en) {
	st += M, en += M;
	int ret = N+1;
	while (st < en) {
		if (st & 1) chkmin(ret, seen[st]);
		if (en & 1) chkmin(ret, seen[en - 1]);
		st = st + 1 >> 1, en >>= 1;
	}
	return ret;
}

int main() {
	
	cin >> N >> G >> R;
	x[xn++] = 0;
	for (int i = 1; i <= N+1; i++) {
		int t; scanf("%d", &t);
		s[i] = s[i-1] + t;
		x[xn++] = s[i] % (G+R);
	}
	sort(x, x + xn);
	xn = unique(x, x + xn) - x;
	for (int i = 0; i <= N+1; i++) S[i] = lower_bound(x, x + xn, s[i]%(G+R)) - x;
	M = bit(32 - clzi(xn));
	memset(seen, 0x3f, sizeof seen);
	for (int i = N+1; i >= 0; i--) {
		int st = x[S[i]] + G, en = x[S[i]] + G+R-1;
		if (st >= G+R) {
			st -= G+R, en -= G+R;
			st = lower_bound(x, x + xn, st) - x;
			en = upper_bound(x, x + xn, en) - x;
			next[i] = get(st, en);
		} else {
			en -= G+R;
			st = lower_bound(x, x + xn, st) - x;
			en = upper_bound(x, x + xn, en) - x;
			next[i] = min(get(st, xn), get(0, en));
		}
		if (next[i] == N+1) {
			dp[i] = s[N+1] - s[i];
		} else {
			dp[i] = ((s[next[i]] - s[i]) / (G+R) + 1) * (G+R) + dp[next[i]];
		}
		if (i && i <= N) update(S[i], i);
	}
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int t; scanf("%d", &t);
		int tt = (-t) % (G+R);
		if (tt < 0) tt += G+R;
		int st = tt + G, en = tt + G+R-1;
		int ptr;
		if (st >= G+R) {
			st -= G+R, en -= G+R;
			st = lower_bound(x, x + xn, st) - x;
			en = upper_bound(x, x + xn, en) - x;
			ptr = get(st, en);
		} else {
			en -= G+R;
			st = lower_bound(x, x + xn, st) - x;
			en = upper_bound(x, x + xn, en) - x;
			ptr = min(get(st, xn), get(0, en));			
		}
		long long ans;
		if (ptr == N+1) {
			ans = t + s[N+1];
		} else {
			ans = dp[ptr] + ((t + s[ptr]) / (G+R) + 1) * (G+R);
		}
		printf("%lld\n", ans);
	}
	return 0;
}