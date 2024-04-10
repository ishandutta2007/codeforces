#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int dat[100000];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		dat[z - 1] = i;
	}
	int now = 0, bef = 1000000000;
	int maxi = 0;
	for (int i = 0; i < num; i++)
	{
		if (bef < dat[i])now++;
		else now = 1;
		bef = dat[i];
		maxi = max(maxi, now);
	}
	printf("%d\n", num - maxi);
}