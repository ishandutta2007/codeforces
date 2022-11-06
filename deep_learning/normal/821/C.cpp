#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std; 
int arr[300005]; 
char str[105]; 
int main()
{
	// freopen("821C.in", "r", stdin); 
	int n, ans = 0, tot = 0, cur = 0; 
	scanf("%d", &n); 
	for (int i = 0; i < n << 1; i++)
	{
		scanf("%s", str); 
		if (str[0] == 'a')
		{
			int x; 
			scanf("%d", &x); 
			arr[tot++] = x - 1; 
		}
		else
		{
			if (tot && arr[tot - 1] != cur)
			{
				ans++; 
				tot = 0; 
			}
			else if (tot && arr[tot - 1] == cur)
				tot--; 
			cur++; 
		}
	}
	printf("%d\n", ans);
	return 0; 
}