#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, m;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &m);
	if (n % m == 0)
	{
		for(int i = 1; i <= m; i++)
			printf("%d ", n / m);
		printf("\n");
	}
	else
	{
		int x = n % m;
		for(int i = 1; i <= x; i++)
			printf("%d ", n / m + 1);
		for(int i = x + 1; i <= m; i++)
			printf("%d ", n / m);
	}
	printf("\n");
	return 0;
}