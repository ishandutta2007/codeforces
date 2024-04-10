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

VPII V;
char s[222222];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, a, b, k; cin >> n >> a >> b >> k;
	scanf("%s", s);
	int last = -1;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			if (i - last - 1 >= b) V.push_back(PII(last+1, i-1));
			last = i;
		}
	}
	if (n - 1 - last >= b) V.push_back(PII(last+1, n-1));
	int tot = 0;
	for (int i = 0; i < V.size(); i++) tot += (V[i].second - V[i].first + 1) / b;
	int ans = tot - a + 1;
	cout << ans << endl;
	vector<int> ret;
	for (int i = 0; i < sz(V) && ans > 0; i++) {
		for (int j = V[i].first+b-1; ans > 0 && j <= V[i].second; j += b) ret.push_back(j), ans--;
	}
	assert(sz(ret) == tot - a + 1);
	for (int i = 0; i < sz(ret); i++) printf("%d%c", ret[i]+1, i < sz(ret)-1 ? ' ' : '\n');
	return 0;
}