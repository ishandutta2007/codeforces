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

const int MAXN = 210000;

int cnt[MAXN], a[MAXN], chk[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	int ans = 0;
	set<int> S;
	for (int i = 1; i <= n; i++) if (!cnt[i]) ans++, S.insert(i);
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++) {
		if (cnt[a[i]] > 1) {
			int x = *S.begin();
			if (x < a[i] || chk[a[i]]) {
				S.erase(S.begin());
				cnt[a[i]]--;
				cnt[x]++;
				a[i] = x;
			} else if (!chk[a[i]]) {
				chk[a[i]] = 1;
				continue;
			}
		}
	}
	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
	return 0;
}