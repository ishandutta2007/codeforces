#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	for (int i = 0; i <= c; i += a)
	{
		if ((c - i) % b == 0)
		{
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
}