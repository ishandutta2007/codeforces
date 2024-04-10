#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	int max = 0;
	int now;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &now);
		if(now > max)
			max = now;
	}
	printf("%d", max);
	return 0;
}