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

const int MAXN = 2e5 + 10;

int f[MAXN];

int find_set(int u) {
	return f[u] == 0 ? u : f[u] = find_set(f[u]);
}

set<int> S;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, q; scanf("%d%d", &n, &q);
	for (int i = 1; i < n; i++) S.insert(i);
	for (int i = 1; i <= q; i++) {
		int t, l, r; scanf("%d%d%d", &t, &l, &r);
		if (t == 1) {
			l = find_set(l), r = find_set(r);
			if (l != r) f[l] = r;
		} else if (t == 2) {
			r--;
			for (set<int> :: iterator it = S.lower_bound(l); it != S.end() && *it <= r; it++) {
				int u = *it, x = find_set(u), y = find_set(u + 1);
				if (x != y) f[x] = y;
			}
			while (1) {
				set<int> :: iterator it = S.lower_bound(l);
				if (it == S.end() || *it > r) break;
				S.erase(it);
			}
		} else {
			l = find_set(l), r = find_set(r);
			puts(l == r ? "YES" : "NO");
		}
	}
	return 0;
}