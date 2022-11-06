#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
int fst[5005], lst[5005], dp[5005], arr[5005]; 
bool vis[5005]; 
int main()
{
	// freopen("811C.in", "r", stdin);
	int n; 
	scanf("%d", &n); 
	memset(fst, -1, sizeof(fst)); 
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i); 
		if (fst[arr[i]] == -1)
			fst[arr[i]] = i; 
		lst[arr[i]] = i; 
	}
	for (int i = 0; i < n; i++)
	{
		dp[i] = max(dp[i], i ? dp[i - 1] : 0); 
		if (lst[arr[i]] != i)
			continue; 
		memset(vis, false, sizeof(vis)); 
		int cur = 0, mn = 1e9; 
		for (int j = i; j >= 0; j--)
		{
			if (lst[arr[j]] > i)
				break; 
			mn = min(mn, fst[arr[j]]); 
			if (!vis[arr[j]])
			{
				cur ^= arr[j]; 
				vis[arr[j]] = true; 
			}
			if (j <= mn)
				dp[i] = max(dp[i], (j ? dp[j - 1] : 0) + cur); 
		}
	}
	printf("%d\n", dp[n - 1]);
	return 0; 
}