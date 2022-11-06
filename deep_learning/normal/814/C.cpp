#include <iostream>
#include <cstdio>
using namespace std; 
int ans[35][1505]; 
char str[1505]; 
int main()
{
	// freopen("814C.in", "r", stdin); 
	int n, q, cnt = 0; 
	scanf("%d%s%d", &n, str, &q); 
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cnt = 0; 
			for (int k = j; k < n; k++)
			{
				cnt += str[k] != i + 'a'; 
				ans[i][cnt] = max(ans[i][cnt], k - j + 1); 
			}
		}
		for (int j = 0; j < n; j++)
			ans[i][j + 1] = max(ans[i][j + 1], ans[i][j]); 
	}
	while (q--)
	{
		char c; 
		scanf("%d %c", &cnt, &c); 
		printf("%d\n", ans[c - 'a'][cnt]);
	}
	return 0; 
}