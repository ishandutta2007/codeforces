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

int chk[MAXN], cnt[MAXN], pre[MAXN];
vector<int> V[MAXN];

int ans[MAXN];

void extEuclid(int a, int b, int &x, int &y) {
	if (!b) {
		x = 1, y = 0;
		return;
	}
	extEuclid(b, a % b, y, x);
	y -= (a / b) * x;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x); chk[x] = 1;
	}
	for (int i = 0; i < m; i++) if (!chk[i%m]) cnt[__gcd(i, m)]++, V[__gcd(i, m)].push_back(i);
	for (int i = m; i > 0; i--) {
		if (m % i != 0) continue;
		int add = -1, nxt = 0;
		for (int j = i*2; j <= m; j += i) {
			if (cnt[j] > add) {
				nxt = j, add = cnt[j];
			}
		}
		if (nxt == 0) {
			add = 0, nxt = i;
		}
		cnt[i] += add;
		pre[i] = nxt;
	}
	int last = 1;
	int ansn = 0;
	for (int i = 1; i <= m; i = pre[i]) {
		if (V[i].empty()) {
			if (i == pre[i]) break;
		}
		for (int j = 0; j < sz(V[i]); j++) {
			int g = __gcd(last, m);
			int A = last / g, B = V[i][j] / g, M = m / g;
			int x, y; extEuclid(A, M, x, y);
			x = (x % M + M) % M;
			ans[ansn++] = 1LL * x * B % M;
			last = V[i][j];
		}
		if (i == pre[i]) break;
	}
	cout << ansn << endl;
	for (int i = 0; i < ansn; i++) printf("%d ", ans[i]);
	cout << endl;
	return 0;
}