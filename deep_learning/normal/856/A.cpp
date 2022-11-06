#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
int a[105], b[105]; 
bool vis[1000005]; 
int main()
{
	// freopen("856A.in", "r", stdin); 
	int t; 
	scanf("%d", &t); 
	while (t--)
	{
		int n; 
		scanf("%d", &n); 
		for (int i = 0; i < n; i++)
			scanf("%d", a + i); 
		sort(a, a + n); 
		memset(vis, false, sizeof(vis)); 
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
				vis[a[j] - a[i]] = true; 
		}
		int cur = 0; 
		for (int i = 1; i <= 1000000 && cur < n; i++)
		{
			bool f = true; 
			for (int j = 0; j < cur && f; j++)
			{
				if (vis[i - b[j]])
					f = false; 
			}
			if (f)
				b[cur++] = i; 
		}
		if (cur >= n)
		{
			printf("YES\n");
			for (int i = 0; i < n; i++)
				printf("%d%c", b[i], " \n"[i + 1 == n]);
		}
		else
			printf("NO\n");
	}
	return 0; 
}