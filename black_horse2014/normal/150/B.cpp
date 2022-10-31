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

const int MOD = 1e9+7;

int f[2222];

int get(int x) {
	return f[x] == -1 ? x : f[x] = get(f[x]);
}

int main() {
	
	int n, m, p; cin >> n >> m >> p;
	memset(f, -1, sizeof f);
	int tot = n;
	for (int i = 1; i <= n-p+1; i++) {
		int st = i, en = i+p-1;
		for (int j = st; j <= (st+en)/2; j++) {
			int u = get(j), v = get(st+en-j);
			if (u != v) {
				f[u] = v;
				tot--;
			}
		}
	}
	int ans = 1;
	for (int i = 0; i < tot; i++) ans = (LL)ans * m % MOD;
	cout << ans << endl;
	return 0;
}