#include<stdio.h>
int d[90];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		d[z - 1]++;
	}
	int t = 0;
	for (int i = 0; i < 90; i++)
	{
		if (d[i] != 0)t = 0;
		else t++;
		if (t == 15)
		{
			printf("%d\n", i + 1);
			return 0;
		}
	}
	printf("90\n");
}