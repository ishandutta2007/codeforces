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

const int MAXN = 444444;

int N;

long long L, A, B, M;
long long a[MAXN], b[MAXN], ans[MAXN];
int cnt[MAXN];

int main() {
	
	scanf("%d%lld%lld%lld", &N, &L, &A, &B);
	for (int i = 1; i <= N; i++) scanf("%lld", &a[i]), a[i] *= A+B;
	int bn = 0;
	long long M = B*L;
	L *= A+B;
	for (int i = 1; i <= N; i++) {
		b[bn++] = a[i]-M, b[bn++] = a[i];
		b[bn++] = a[i]-M+2*L, b[bn++] = a[i]+2*L;
	}
	b[bn++] = M, b[bn++] = M+2*L;
	sort(b, b + bn);
	bn = unique(b, b + bn) - b;
	for (int i = 1; i <= N; i++) {
		cnt[lower_bound(b, b + bn, a[i]-M) - b]++;
		cnt[lower_bound(b, b + bn, a[i]) - b]--;
		cnt[lower_bound(b, b + bn, a[i]-M+2*L) - b]++;
		cnt[lower_bound(b, b + bn, a[i]+2*L) - b]--;
	}
	int st = lower_bound(b, b + bn, M) - b;
	int en = lower_bound(b, b + bn, 2*L+M) - b - 1;
	for (int i = 0; i < bn; i++) {
		cnt[i+1] += cnt[i];
		if (i >= st && i <= en) {
			ans[cnt[i]] += b[i+1] - b[i];
		}
	}
	for (int i = 0; i <= N; i++) printf("%.12lf\n", 0.5 * ans[i] / L);
	return 0;
}