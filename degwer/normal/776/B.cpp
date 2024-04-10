#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
bool f[200000];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 2; i <= 150000; i++)
	{
		if (f[i])continue;
		for (int j = i + i; j <= 150000; j += i)f[j] = true;
	}
	if (num == 1)printf("1\n1\n");
	else if (num == 2)printf("1\n1 1\n");
	else
	{
		printf("2\n");
		for (int i = 2; i <= num + 1; i++)
		{
			if (f[i])printf("1 ");
			else printf("2 ");
		}
		printf("\n");
	}
}