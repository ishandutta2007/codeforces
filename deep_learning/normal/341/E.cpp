#include <iostream>
#include <cstdio>
using namespace std; 
int ans1[1000005], ans2[1000005], arr[1000005]; 
int main()
{
	// freopen("341E.in", "r", stdin); 
	int n, cnt = 0, x, y = 0, z = 1; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i); 
	for (int i = 2; i < n; i++)
	{
		for (x = i; ;)
		{
			if (arr[x] > arr[y])
				swap(x, y); 
			if (arr[y] > arr[z])
				swap(y, z); 
			if (arr[x] > arr[z])
				swap(x, y); 
			if (!arr[x])
				break; 
			for (int j = arr[y] / arr[x]; j; j >>= 1)
			{
				ans1[cnt] = x; 
				if (j & 1)
				{
					ans2[cnt++] = y; 
					arr[y] -= arr[x]; 
				}
				else
				{
					ans2[cnt++] = z; 
					arr[z] -= arr[x]; 
				}
				arr[x] <<= 1; 
			}
		}
	}
	if (!arr[x] + !arr[y] + !arr[z] != 1)
		puts("-1"); 
	else
	{
		printf("%d\n", cnt);
		for (int i = 0; i < cnt; i++)
			printf("%d %d\n", ans1[i] + 1, ans2[i] + 1);
	}
	return 0; 
}