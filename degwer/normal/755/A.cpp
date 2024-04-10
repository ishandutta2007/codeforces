#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
bool pr[2000001];
int main()
{
	int n;
	scanf("%d", &n);
	if (n == 1)
	{
		printf("3\n");
		return 0;
	}
	for (int i = 2; i <= 2000000; i++)
	{
		if (!pr[i])
		{
			for (int j = i * 2; j <= 2000000; j += i)pr[j] = true;
		}
		else if (i%n == 1)
		{
			printf("%d\n", i / n);
			return 0;
		}
	}
}