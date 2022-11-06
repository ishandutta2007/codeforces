#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
char ans[2000005], str[2000005]; 
int main()
{
	// freopen("A.in", "r", stdin); 
	int n, mx = 0; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str); 
		int len = strlen(str), cnt, cur = 0; 
		scanf("%d", &cnt); 
		for (int j = 0; j < cnt; j++)
		{
			int x; 
			scanf("%d", &x); 
			x--; 
			for (int k = max(cur, x); k < x + len; k++)
				ans[k] = str[k - x]; 
			cur = max(cur, x + len); 
		}
		mx = max(mx, cur); 
	}
	for (int i = 0; i < mx; i++)
	{
		if (!ans[i])
			ans[i] = 'a'; 
	}
	printf("%s\n", ans);
	return 0; 
}