#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
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

VPII V;

int a[110];
int b[110];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; long long k; cin >> n >> k;
	int M = 32000;
	long long asum = 0;
	for (int i = 1; i <= n; i++) cin >> a[i], asum += a[i];
	asum += k;
	for (int i = 1; i <= n; i++) {
		for (int x = a[i] + 1; x > 0; x--) {
			x = (a[i] - 1) / ((a[i] - 1) / x + 1) + 1;
			V.push_back(make_pair(x, i));
		}
	}
	sort(all(V));
	long long sum = 0;
	long long ans = 0;
	for (int j = 0, i; j < sz(V); j = i) {
		long long s = V[j].first;
		for (i = j; i < sz(V) && V[j].first == V[i].first; i++) {
			int l = V[i].second;
			sum -= b[l];
			b[l] = (a[l] + s - 1) / s;
			sum += b[l];
		}
		if (asum / sum >= s) chkmax(ans, asum / sum);
	}
	cout << ans << endl;
	return 0;
}