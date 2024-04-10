#include <bits/stdc++.h>
#define p2 p << 1
#define p3 p << 1 | 1

const int N = 150000, M = 1e6 + 5, INF = 0x3f3f3f3f;

int n, sum[27][N], f[M][27];
char s[N];

void dp(int l, int r, int p)
{
	if (l == r)
	{
		for (int c = 0; c < 26; c++) f[p][c] = c + 'a' != s[l];
		return (void) (f[p][26] = INF);
	}
	int mid = l + r >> 1;
	dp(l, mid, p2); dp(mid + 1, r, p3);
	for (int c = 0; c < 26; c++)
		f[p][c] = std::min(sum[c][mid] - sum[c][l - 1] + f[p3][c + 1],
			sum[c][r] - sum[c][mid] + f[p2][c + 1]);
	f[p][26] = INF;
}

void work()
{
	scanf("%d%s", &n, s + 1);
	for (int c = 0; c < 26; c++)
		for (int i = 1; i <= n; i++) sum[c][i] = sum[c][i - 1] + (s[i] != c + 'a');
	printf("%d\n", (dp(1, n, 1), f[1][0]));
}

int main()
{
	int T; std::cin >> T;
	while (T--) work();
	return 0;
}