#include <iostream>
#include <cstdio>
using namespace std; 
int cur = 2; 
inline void work(int n)
{
	int lst = 1; 
	for (int j = 0; j < n; j++)
	{
		printf("%d %d\n", lst, cur);
		lst = cur; 
		cur++; 
	}
}
int main()
{
	// freopen("B.in", "r", stdin); 
	int n, m;
	scanf("%d%d", &n, &m); 
	if (n - m == 1)
	{
		printf("2\n");
		for (int i = 0; i < m; i++)
			work(1); 
		return 0;
	}
	if (n - m == 2)
	{
		printf("3\n");
		printf("1 2\n");
		printf("2 3\n");
		for (int i = 2; i <= m; i++)
			printf("3 %d\n", i + 2);
		return 0; 
	}
	if (n - m <= m)
	{
		printf("4\n");
		for (int i = 1; i < n - m; i++)
			work(2); 
		for (int i = 0; i < 2 * m + 1 - n; i++)
			printf("1 %d\n", cur++);
		return 0; 
	}
	int a = (n - 2) / m; 
	if (n - m - 1 == m * (a - 1) + 1)
		printf("%d\n", a * 2 + 1);
	else
		printf("%d\n", a * 2 + 2);
	for (int i = 0; i < n - m - 1 - m * (a - 1); i++)
		work(a + 1); 
	for (int i = n - m - 1 - m * (a - 1); i < m; i++)
		work(a); 
	return 0; 
}