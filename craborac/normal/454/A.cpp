#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i <= n / 2; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(abs(j - (n / 2)) <= i)
				printf("D");
			else
				printf("*");	
		}
		printf("\n");
	}
	for(int i = (n / 2); i > 0; i--)
	{
		for(int j = 0; j < n; j++)
		{
			if(abs(j - (n / 2)) < i)
				printf("D");
			else
				printf("*");	
		}
		printf("\n");
	}
	return 0;
}