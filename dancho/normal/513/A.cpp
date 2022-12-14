#include <cstdio>
#include <cstring>

int main()
{
	int n1, n2;
	scanf("%d %d", &n1, &n2);
	if (n1 <= n2)
	{
		printf("Second\n");
	}
	else
		printf("First\n");
	return 0;
}