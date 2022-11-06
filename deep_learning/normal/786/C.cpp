#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
int dp[100005], arr[100005], n; 
bool vis[100005]; 
inline int calc(int x)
{
	if (dp[x])
		return dp[x]; 
	int lst = 0, res = 0, cnt = 0; 
	memset(vis, false, sizeof(vis)); 
	for (int i = 0; i < n; i++)
	{
		cnt += !vis[arr[i]]; 
		vis[arr[i]] = true; 
		if (cnt > x)
		{
			res++; 
			cnt = 1; 
			for (int j = lst; j <= i; j++)
				vis[arr[j]] = false; 
			vis[arr[i]] = true; 
			lst = i; 
		}
	}
	return dp[x] = res + 1; 
}
int main()
{
	// freopen("C.in", "r", stdin); 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i); 
	for (int j = 1; j <= n;)
	{
		int l = j, r = n, res = calc(j), mx; 
		while (l <= r)
		{
			int m = l + r >> 1;
			if (calc(m) == res)
			{
				mx = m; 
				l = m + 1; 
			}
			else
				r = m - 1; 
		}
		for (; j <= mx; j++)
			printf("%d%c", res, " \n"[j == n]);
	}
	return 0; 
}