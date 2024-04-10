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

pair<int, int> p[MAXN];

int a[2][MAXN];
set< pair<int, int> > S[4];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i].first), p[i].second = i;
	for (int j = 0; j < 2; j++) for (int i = 1; i <= n; i++) scanf("%d", &a[j][i]);
	for (int i = 1; i <= n; i++) {
		S[a[0][i]].insert(p[i]);
		if (a[0][i] != a[1][i]) S[a[1][i]].insert(p[i]);
	}
	int m; scanf("%d", &m);
	while (m--) {
		int x; scanf("%d", &x);
		if (S[x].empty()) {
			printf("-1 ");
			continue;
		}
		set< pair<int, int> > :: iterator it = S[x].begin();
		printf("%d ", it->first);
		int id = it->second;
		S[a[0][id]].erase(p[id]);
		if (a[0][id] != a[1][id]) S[a[1][id]].erase(p[id]);
	}
	puts("");
	return 0;
}