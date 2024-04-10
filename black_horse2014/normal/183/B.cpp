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

const int MAXN = 1111111;

LL x[MAXN], y[MAXN];
int ans[MAXN];

LL cross(int i, int j, int k) {
	return (x[j] - x[i]) * (y[k] - y[i]) - (x[k] - x[i]) * (y[j] - y[i]);
}

int main() {
	
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%lld%lld", &x[i], &y[i]);
		if (x[i] <= n) ans[x[i]]++;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = i+1; j <= m; j++) {
			if (y[i] == y[j]) continue;
			LL A = y[j] * (x[i] - x[j]), B = y[i] - y[j];
			if (A % B != 0) continue;
			LL pos = x[j] - A / B;
			if (pos < 1 || pos > n) continue;
			int cnt = 2;
			for (int k = 1; k <= m; k++) {
				if (k == i || k == j) continue;
				if (cross(i, j, k) == 0) cnt++;
			}
			chkmax(ans[pos], cnt);
		}
	}
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		if (ans[i] == 0) ans[i]++;
		ret += ans[i];
	}
	cout << ret << endl;
	return 0;
}