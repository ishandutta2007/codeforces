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

VI a, b;
char s[110000];

bool can(int t) {
	int last = -1;
	for (int i = 0; i < a.size(); i++) {
		if (last+1 == b.size()) return 1;
		if (b[last+1] < a[i] - t) return 0;
		int s = 0, d = abs(a[i] - b[last+1]);
		if (b[last+1] < a[i]) s = max(t - 2 * d, (t - d) / 2);
		else s = t;
		while (last + 1 < b.size() && b[last+1] <= a[i] + s) last++;
	}
	return last+1 == b.size();
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d%s", &n, s);
	for (int i = 0; i < n; i++) {
		if (s[i] == 'P') a.push_back(i);
		if (s[i] == '*') b.push_back(i);
	}
	int lo = 0, hi = n*2;
	while (hi - lo > 1) {
		int mid = lo + hi >> 1;
		if (can(mid)) hi = mid;
		else lo = mid;
	}
	cout << hi << endl;
	return 0;
}