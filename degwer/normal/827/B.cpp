#include<stdio.h>
int main()
{
	int num, gen;
	scanf("%d%d", &num, &gen);
	int sum = num - gen - 1;
	printf("%d\n", (sum + gen - 1) / gen + 1 + (sum + gen - 2) / gen + 1);
	int pt = 2;
	for (int i = 0; i < gen; i++)
	{
		int ko = sum / gen;
		if (i < sum%gen)ko++;
		for (int j = 0; j < ko; j++)printf("%d %d\n", pt, pt + 1), pt++;
		printf("%d %d\n", pt++, 1);
	}
}