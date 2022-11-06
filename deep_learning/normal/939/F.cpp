#include <algorithm>
#include <cstring>
#include <cstdio>
int dp[105][200005], n, k; 
inline int query(int idx, int pos)
{
	int res = 1e9; 
	for (pos += n + 1; pos; pos >>= 1)
		res = std::min(res, dp[idx][pos]); 
	return res; 
}
inline void modify(int idx, int l, int r, int x)
{
	if (r < 0 || l > n || l > r)
		return; 
	r = std::min(r, n); 
	l = std::max(l, 0); 
	for (l += n + 1, r += n + 2; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1)
		{
			dp[idx][l] = std::min(dp[idx][l], x); 
			l++; 
		}
		if (r & 1)
		{
			r--; 
			dp[idx][r] = std::min(dp[idx][r], x); 
		}
	}
}
int l[105], r[105]; 
int main()
{
	// freopen("939F.in", "r", stdin); 
	scanf("%d%d", &n, &k); 
	for (int i = 1; i <= k; i++)
		scanf("%d%d", l + i, r + i); 
	k++; 
	l[k] = r[k] = n << 1; 
	memset(dp, 0x3f, sizeof(dp)); 
	modify(0, 0, 0, 0); 
	for (int i = 0; i < k; i++)
	{
		// printf("%d\n", i);
		int t = l[i + 1] - r[i], len = r[i + 1] - l[i + 1]; 
		for (int j = 0; j + t <= r[i + 1]; j++)
		{
			int x = query(i, j);
			if (x >= 1e9)
				continue; 
			// printf("0 %d %d %d\n", j + t + len, j + t + len, x);
			modify(i + 1, j + t + len, j + t + len, x); 
			// printf("1 %d %d %d\n", std::max(0, r[i + 1] - j - t - len), std::max(0, r[i + 1] - j - t), x + 1);
			modify(i + 1, r[i + 1] - j - t - len, r[i + 1] - j - t, x + 1); 
			// printf("2 %d %d %d\n", j + t, std::min(n, j + t + len), x + 2);
			modify(i + 1, j + t, j + t + len, x + 2); 
		}
	}
	int res = query(k, n); 
	if (res >= 1e9)
		puts("Hungry"); 
	else
	{
		puts("Full"); 
		printf("%d\n", res);
	}
	return 0; 
}