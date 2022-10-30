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

VI V[110000];

int a[110000];
int d[110000];
int n;

void add(int u) {
	for (; u <= n; u += u & -u) d[u]++;
}

int get(int u) {
	int ret = 0;
	for (; u; u -= u & -u) ret += d[u];
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), V[a[i]].push_back(i);
	int cur = 0, tot = 0;
	long long ans = 0;
	for (int x = 1; x <= 100000; x++) if (!V[x].empty()) {
		int st = 0;
		while (st < V[x].size() && V[x][st] < cur) st++;
		for (int i = 0; i < V[x].size(); i++) {
			int k = V[x][(st+i)%V[x].size()];
			if (cur < k) ans += k - cur - get(k - 1) + get(cur);
			else ans += k + n - cur - tot + get(cur) - get(k - 1);
			cur = k;
			add(cur);
			tot++;
		}
	}
	cout << ans << endl;
	return 0;
}