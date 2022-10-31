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

const int MAXM = 1e6 + 5;
const int MOD = 1e9 + 7;

int pw[7];
int cnt[MAXM], sum[MAXM], sum2[MAXM], b[MAXM], B[MAXM];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		cnt[x]++, sum[x] = (sum[x] + x) % MOD, sum2[x] = (sum2[x] + 1LL * x * x) % MOD;
	}
	for (int i = 0; i < 7; i++) pw[i] = (i == 0 ? 1 : pw[i-1] * 10);
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < pw[6]; j++) {
			int k = j / pw[i] % 10, cur = j;
			while (k < 9) {
				cur += pw[i];
				k++;
				cnt[j] += cnt[cur];
				sum[j] = (sum[j] + sum[cur]) % MOD;
				sum2[j] = (sum2[j] + sum2[cur]) % MOD;
			}
		}
	}
	for (int i = 0; i <= n; i++) b[i] = (i == 0 ? 1 : 2LL * b[i-1] % MOD);
	for (int i = 0; i < pw[6]; i++) {
		if (cnt[i] == 0) continue;
		if (cnt[i] == 1) B[i] = sum2[i];
		else B[i] = (sum2[i] + 1LL * sum[i] * sum[i]) % MOD * b[cnt[i]-2] % MOD;
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < pw[6]; j++) {
			int k = j / pw[i] % 10;
			if (k < 9) B[j] = (B[j] - B[j + pw[i]] + MOD) % MOD;
		}
	}
	long long ans = 0;
	for (int j = 0; j < pw[6]; j++) {
		ans ^= 1LL * j * B[j];
	}
	cout << ans << endl;
	return 0;
}