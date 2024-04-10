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

const int MOD = 1e9 + 7;

int a[1<<20];
char s[5+(1<<20)];

template<typename T>
void Trans(T *b, int n, T m) {
	for (int j = 0, k = 1; k < n; k <<= 1, j++) {
		for (int i = 0; i < n; i++) {
			if (~i>>j & 1) {
				T x = (b[i] + b[i+k]) % m, y = (b[i] - b[i+k] + m) % m;
				b[i] = x, b[i+k] = y;
			}
		}
	}
}

template<typename T>
void Untrans(T *b, int n, T m) {
	for (int j = __builtin_ctz(n)-1, k = n/2; j >= 0; k /= 2, j--) {
		for (int i = 0; i < n; i++) {
			if (~i>>j & 1) {
				T x = (b[i] + b[i+k]) % m, y = (b[i] - b[i+k] + m) % m;
				if (x & 1) x += m; if (y & 1) y += m;
				b[i] = x>>1, b[i+k] = y>>1;
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d%s", &n, s);
	for (int i = 0; i < 1<<n; i++) a[i] = s[i] - '0';
	Trans(a, 1<<n, MOD);
	for (int i = 0; i < 1<<n; i++) a[i] = 1LL * a[i] * a[i] % MOD;
	Untrans(a, 1<<n, MOD);
	int ans = 0;
	for (int i = 0; i < 1<<n; i++) ans = (ans + 1LL*a[i]*bit(n-cnti(i))) % MOD;
	cout << ans*3LL%MOD << endl;
	return 0;
}