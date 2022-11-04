#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

char s[1000005];
int dp[1 << 20], ndp[1 << 20];

int main() {
	scanf("%s", s + 1);
	int N = strlen(s + 1);
	repi(i, N) {
		int msk = 0;
		for (int l = 1; l <= 20; ++l) {
			int j = i + l - 1;
			if (j > N) break;
			int ch = s[j] - 'a';
			if ((msk >> ch) & 1) break;
			msk |= 1 << ch;
			dp[msk] = l;
		}
	}
	rep(i, 1 << 20) ndp[((1 << 20) - 1) ^ i] = dp[i];
	rep(i, 20) rep(j, 1 << 20) if (!((j >> i) & 1)) dp[j | (1 << i)] = max(dp[j | (1 << i)], dp[j]);
	int ans = 0;
	rep(i, 1 << 20) ans = max(ans, dp[i] + ndp[i]);
	printf("%d\n", ans);
	return 0;
}