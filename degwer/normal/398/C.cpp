#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num;
	scanf("%d", &num);
	if (num % 2 == 0)
	{
		printf("%d %d %d\n", 1, 2, 1);
		for (int i = 0; i < (num - 1) / 4; i++)
		{
			printf("%d %d %d\n", i * 4 + 2, i * 4 + 5, 1);
			printf("%d %d %d\n", i * 4 + 3, i * 4 + 6, 1);
			printf("%d %d %d\n", i * 4 + 4, i * 4 + 5, 3);
			if (i * 4 + 6 == num)printf("%d %d %d\n", i * 4 + 3, i * 4 + 4, 2);
			else printf("%d %d %d\n", i * 4 + 3, i * 4 + 4, 3);
		}
	}
	else
	{
		for (int i = 0; i < (num - 1) / 4; i++)
		{
			printf("%d %d %d\n", i * 4 + 1, i * 4 + 4, 1);
			printf("%d %d %d\n", i * 4 + 2, i * 4 + 5, 1);
			if (i == 0)printf("%d %d %d\n", i * 4 + 3, i * 4 + 4, 2);
			else printf("%d %d %d\n", i * 4 + 3, i * 4 + 4, 3);
			if (i * 4 + 5 == num)printf("%d %d %d\n", i * 4 + 2, i * 4 + 3, 2);
			else printf("%d %d %d\n", i * 4 + 2, i * 4 + 3, 3);
		}
	}
	if (num % 4 == 3 || num % 4 == 0)
	{
		printf("%d %d %d\n", num - 2, num, 1);
		printf("%d %d %d\n", num - 1, num, 1);
	}
	if (num % 4 == 1)
	{
		for (int i = 0; i < (num - 1) / 4; i++)
		{
			printf("%d %d\n", i * 4 + 1, i * 4 + 2);
			printf("%d %d\n", i * 4 + 4, i * 4 + 5);
		}
	}
	else if (num % 4 == 2)
	{
		printf("%d %d\n", 1, 3);
		for (int i = 0; i < (num - 1) / 4; i++)
		{
			printf("%d %d\n", i * 4 + 2, i * 4 + 3);
			printf("%d %d\n", i * 4 + 5, i * 4 + 6);
		}
	}
	else if (num % 4 == 3)
	{
		for (int i = 0; i < (num - 1) / 4; i++)
		{
			printf("%d %d\n", i * 4 + 1, i * 4 + 2);
			printf("%d %d\n", i * 4 + 4, i * 4 + 5);
		}
		printf("%d %d\n", num - 3, num - 1);
	}
	else if (num % 4 == 0)
	{
		printf("%d %d\n", 1, 3);
		for (int i = 0; i < (num - 1) / 4; i++)
		{
			printf("%d %d\n", i * 4 + 2, i * 4 + 3);
			printf("%d %d\n", i * 4 + 5, i * 4 + 6);
		}
		printf("%d %d\n", num - 3, num - 1);
	}
}