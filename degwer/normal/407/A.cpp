#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int sq[1000001];
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	for (int i = 1; i <= 1000; i++)sq[i*i] = i;
	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 1; j <= 1000; j++)
		{
			int t = i*i + j*j;
			if (a*a%t == 0 && b*b%t == 0)
			{
				if (sq[a*a / t] && sq[b*b / t])
				{
					if (j*sq[a*a / t] == i*sq[b*b / t])continue;
					printf("YES\n");
					printf("%d %d\n", -i*sq[a*a / t], j*sq[a*a / t]);
					printf("0 0\n");
					printf("%d %d\n", j*sq[b*b / t], i*sq[b*b / t]);
					return 0;
				}
			}
		}
	}
	printf("NO\n");
}