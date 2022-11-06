#include <iostream>
#include <cstdio>
#include <queue>
using namespace std; 
int arr[204800], ans[204800];
queue<int> app[204800]; 
int main()
{
	// freopen("534D.in", "r", stdin); 
	int n; 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i); 
		app[arr[i]].push(i); 
	}
	int cur = 0; 
	for (int i = 0; i < n; i++)
	{
		while (!app[cur].size())
		{
			if (cur >= 0)
				cur -= 3; 
			if (cur < 0)
			{
				printf("Impossible\n");
				return 0; 
			}
		}
		ans[i] = app[cur].front(); 
		app[cur].pop(); 
		cur++; 
	}
	printf("Possible\n");
	for (int i = 0; i < n; i++)
		printf("%d%c", ans[i] + 1, " \n"[i + 1 == n]);
	return 0; 
}