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

long long dp[2][120][2];
long long b[60];
int s[3];

long long calc1(int A, int C, long long N) {
	if (N > bitl(A+1)-2) return 0;
	if (cntl(N) == C) return 1;
	return 0;
}

long long calc(int A, int B, int C, long long N) {
	if (N > bitl(A+1)-2 + bitl(B+1)-2) return 0;
	int now = 0, max_cnt = 0;
	dp[0][0][0] = 1;
	dp[0][0][1] = 0;
	for (int i = max(A, B)+1; i >= 1; i--) {
		now ^= 1;
		int cur_cnt = (i <= A) + (i <= B);
		for (int j = 0; j <= min(C, max_cnt + cur_cnt); j++) dp[now][j][0] = dp[now][j][1] = 0;
		s[0] = s[1] = s[2] = 0;
		s[0] = s[cur_cnt] = 1;
		if (cur_cnt == 2) s[1] = 2;
		int cur_bit = N >> i & 1;
		for (int j = 0; j <= max_cnt; j++) {
			if (dp[!now][j][0]) {
				dp[now][j+cur_bit][0] += dp[!now][j][0] * s[cur_bit];
				if (cur_bit) dp[now][j][1] += dp[!now][j][0];
			}
			if (dp[!now][j][1]) {
				dp[now][j+cur_bit+1][1] += dp[!now][j][1] * s[cur_bit+1];
				if (!cur_bit) dp[now][j+cur_bit+2][0] += dp[!now][j][1] * s[2];
			}
		}
		max_cnt = min(max_cnt + cur_cnt, C);
	}
	return (C > max_cnt ? 0 : dp[now][C][0]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	long long n; cin >> n;
	for (int i = 0; i <= 50; i++) b[i] = (1LL<<i)-1;
	long long ans = 0;
	for (int i = 0; i < 50; i++) {
		if (b[i+1] > n) break;
		for (int j = 0; j < 50; j++) {
			if (b[i+1]+b[j+1]-1 > n) break;
			long long mod = b[i+1] + b[j+1] - 1;
			long long ret = n - b[j];
			if (ret < mod) continue;
			ret %= mod;
			if (i == 0 && j == 0) {
				ans++;
				continue;
			}
			if (i == 0) {
				for (int k = 0; k <= j-1; k++) {
					if (ret + k & 1) continue;
					ans += calc1(j-1, k, ret+k);
				}
			} else if (j == 0) {
				for (int k = 0; k <= i-1; k++) {
					if (ret + k & 1) continue;
					ans += calc1(i-1, k, ret+k);
				}
			} else {
				for (int k = 0; k <= i-1+j-1; k++) {
					if (ret + k & 1) continue;
					ans += calc(i-1, j-1, k, ret+k);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}