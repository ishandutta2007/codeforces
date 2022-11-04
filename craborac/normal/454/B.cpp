#include<cstdio>

int mas[(int)1e6];

int main()
{
	int n;
	scanf("%d", &n);
	int col = 0;
	int q = -1;
	int last_a = 0;
	for(int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &mas[i]);
		a = mas[i];
		if(a < last_a)
		{
			col++;
			q = i;
		}
		last_a = a;
	}
	if(col == 0)
	{
		printf("0");
		return 0;
	}
	if(mas[0] >= mas[n - 1])
	{
		if(col == 1)
		{
			printf("%d", n - q);
		}
		else
			printf("-1");
	}
	else
		printf("-1");
	return 0;
}