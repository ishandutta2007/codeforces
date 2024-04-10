#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int d[404040];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)scanf("%d", &d[i]);
	int maxi = 0;
	for (int i = 0; i < num; i++)
	{
		if (d[0] != d[i])maxi = max(maxi, i);
		if (d[num - 1] != d[i])maxi = max(maxi, num - 1 - i);
	}
	printf("%d\n", maxi);
}