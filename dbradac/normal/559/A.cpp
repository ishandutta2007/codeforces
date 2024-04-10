#include <cstdio>

int main()
{
	int p[8];
	
	for (int i=1; i<=6; i++)
		scanf("%d", &p[i]);

	printf("%d\n", p[1] * p[1] + 2 * p[1] * p[2] + 2 * p[1] * p[6] + 2 * p[2] * p[6] - p[4] * p[4]);
	
	return 0;
}