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

const int MAXN = 110000;

set<PII> S;

int a[MAXN], b[MAXN], c[MAXN], id[MAXN], p[MAXN];

VPII V[MAXN];

bool cmp(int u, int v) {
	return b[u] > b[v];
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
	for (int i = 1; i <= m; i++) scanf("%d", &p[i]);
	for (int i = 1; i <= m; i++) id[i] = i;
	sort(id + 1, id + m + 1, cmp);
	for (int i = n; i > 0; i--) c[i] = max(a[i], c[i+1]);
	for (int i = 1, j = 1; i <= n; i++) {
		while (j <= m && b[id[j]] > c[i]) j++;
		if (a[i] > c[i+1]) {
			while (j <= m && b[id[j]] > c[i+1]) V[i].push_back(PII(p[id

[j]], id[j])), j++;
		}
	}
	for (int i = 1; i <= n; i++) sort(all(V[i]));
	long long sum = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		sum += a[i];
		for (int j = 0; j < sz(V[i]); j++) {
			PII cur = V[i][j];
			if (sum >= cur.first) {
				sum -= cur.first;
				S.insert(cur);
				ans++;
			} else if (!S.empty()) {
				set<PII> :: iterator it = --S.end();
				if (it->first > cur.first) {
					sum += it->first;
					S.erase(it);
					S.insert(cur);
					sum -= cur.first;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}