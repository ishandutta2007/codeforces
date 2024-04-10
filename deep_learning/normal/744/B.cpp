#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
int ans[1005], arr[1005], res[1005], cnt, n; 
int orig[1005][1005]; 
inline void init()
{
	scanf("%d", &n); 
#ifndef ONLINE_JUDGE
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%d", orig[i] + j); 
	}
#endif
}
inline void query()
{
#ifdef ONLINE_JUDGE
	printf("%d\n", cnt);
	for (int k = 0; k < cnt; k++)
		printf("%d%c", arr[k] + 1, " \n"[k + 1 == cnt]);
	fflush(stdout); 
	for (int i = 0; i < n; i++)
		scanf("%d", res + i); 
#else
	memset(res, 0x3f, sizeof(res)); 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < cnt; j++)
			res[i] = min(res[i], orig[i][arr[j]]); 
	}
#endif
}
inline void print()
{
	printf("-1\n");
	for (int i = 0; i < n; i++)
		printf("%d%c", ans[i], " \n"[i + 1 == n]);
	fflush(stdout); 
#ifndef ONLINE_JUDGE
	for (int i = 0; i < n; i++)
	{
		int mn = 1e9; 
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			mn = min(mn, orig[i][j]); 
		}
		if (mn != ans[i])
		{
			printf("Wrong Answer line %d wrong.\n", i + 1);
			return; 
		}
	}
	printf("Correct.\n");
#endif
}
int main()
{
	// freopen("B.in", "r", stdin); 
	memset(ans, 0x3f, sizeof(ans)); 
	init(); 
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cnt = 0; 
			for (int k = 0; k < n; k++)
			{
				if (((k >> i) & 1) == j)
					arr[cnt++] = k; 
			}
			if (!cnt)
				continue; 
			query(); 
			for (int k = 0; k < n; k++)
			{
				if (((k >> i) & 1) != j)
					ans[k] = min(ans[k], res[k]); 
			}
		}
	}
	print(); 
	return 0; 
}