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

VI d;

int main() {
	
	int n; cin >> n;
	for (int i = 1; 1LL * i * i <= n; i++) {
		if (n % i == 0) {
			d.push_back(i);
			if (i < n / i) d.push_back(n / i);
		}
	}
	sort(all(d));
	long long ansmin = 1LL<<60, ansmax = 0;
	for (int i = 0; i < d.size() && 1LL*d[i]*d[i] <= n; i++) {
		int m = n / d[i];
		for (int j = i; j < d.size() && 1LL*d[i]*d[j]*d[j] <= n; j++) if (m % d[j] == 0) {
			int x = d[i], y = d[j], z = m / d[j];
			chkmin(ansmin, 1LL*(x+1)*(y+2)*(z+2) - n);
			chkmax(ansmax, 1LL*(x+2)*(y+2)*(z+1) - n);
		}
	}
	printf("%lld %lld\n", ansmin, ansmax);
	return 0;
}