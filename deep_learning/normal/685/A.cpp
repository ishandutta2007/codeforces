#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
typedef long long ll; 
bool app[15]; 
int main()
{
	// freopen("A.in", "r", stdin); 
	int n, m, x = 1, y = 1; 
	scanf("%d%d", &n, &m); 
	for (ll i = 7; i < n; i *= 7)
		x++; 
	for (ll i = 7; i < m; i *= 7)
		y++; 
	if (x + y > 7)
	{
		printf("0\n");
		return 0;
	}
	int ans = 0; 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			memset(app, false, sizeof(app)); 
			int tmp = i, cnt = 0; 
			for (int k = 0; k < x; k++)
			{
				app[tmp % 7] = true; 
				tmp /= 7; 
			}
			tmp = j; 
			for (int k = 0; k < y; k++)
			{
				app[tmp % 7] = true; 
				tmp /= 7; 
			}
			for (int k = 0; k < 7; k++)
				cnt += app[k]; 
			if (cnt == x + y)
				ans++; 
		}
	}
	printf("%d\n", ans);
	return 0; 
}