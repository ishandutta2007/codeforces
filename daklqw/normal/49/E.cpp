#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 110;
int dp1[MAXN][MAXN][26];
int dp2[MAXN][MAXN][26];

int len1, len2, n;
int to[MAXN], ca[MAXN], cb[MAXN];
char buf[10], s1[MAXN], s2[MAXN];
void make(int dp[MAXN][MAXN][26], char * buf, int len) {
	for (int i = 1; i <= len; ++i) dp[i][i][buf[i] - 'a'] = true;
	for (int L = 2; L <= len; ++L)
		for (int l = 1; l + L - 1 <= len; ++l)
			for (int mid = l; mid < l + L - 1; ++mid)
				for (int k = 1; k <= n; ++k)
					dp[l][l + L - 1][to[k]] |= dp[l][mid][ca[k]] && dp[mid + 1][l + L - 1][cb[k]];
}
int dp[MAXN][MAXN];
inline void getmin(int & x, const int y) { if (x > y) x = y; }
int main() {
	scanf("%s%s%d", s1 + 1, s2 + 1, &n);
	len1 = strlen(s1 + 1); len2 = strlen(s2 + 1);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", buf);
		ca[i] = buf[3] - 'a'; cb[i] = buf[4] - 'a';
		to[i] = buf[0] - 'a';
	}
	make(dp1, s1, len1); make(dp2, s2, len2);
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	for (int i = 1; i <= len1; ++i)
		for (int j = 1; j <= len2; ++j)
			for (int k = 0; k < i; ++k)
				for (int l = 0; l < j; ++l) if (dp[k][l] != 0x3f3f3f3f)
					for (int c = 0; c != 26; ++c)
						if (dp1[k + 1][i][c] && dp2[l + 1][j][c])
							getmin(dp[i][j], dp[k][l] + 1);
#define reduce(X) (X == 0x3f3f3f3f ? -1 : X)
	printf("%d\n", reduce(dp[len1][len2]));
	return 0;
}