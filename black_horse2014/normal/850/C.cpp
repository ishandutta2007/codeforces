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

const int MAXN = 60000;

int a[MAXN];
int prn, prm[MAXN], chk[MAXN];

map<int, int> H;

int get(int s) {
	if (s == 0) return 0;
	if (H.count(s)) return H[s];
	int d = 31 - __builtin_clz(s);
	int t = 0;
	for (int i = 1; i <= d; i++) t |= 1<<get((s>>i)|(s&(bit(i)-2)));
	for (int i = 0; i <= d; i++) if (~t>>i&1) return H[s] = i;
	assert(0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 2; i < MAXN; i++) if (!chk[i]) {
		prm[prn++] = i;
		for (int j = 2*i; j < MAXN; j += i) chk[j] = 1;
	}
	VI S;
	for (int i = 0; i < n; i++) {
		int m; scanf("%d", &m);
		for (int j = 0; j < prn && 1LL * prm[j] * prm[j] <= m; j++) if (m % prm[j] == 0) {
			int k = 0;
			while (m % prm[j] == 0) k++, m /= prm[j];
			a[j] |= 1 << k;
		}
		if (m > prm[prn-1]) S.pb(m);
		else if (m > 1) {
			int j = lower_bound(prm, prm + prn, m) - prm;
			a[j] |= 2;
		}
	}
	sort(all(S));
	S.erase(unique(all(S)), S.end());
	int ans = S.size()&1;
	for (int i = 0; i < prn; i++) ans ^= get(a[i]);
	puts(ans ? "Mojtaba" : "Arpa");
	return 0;
}