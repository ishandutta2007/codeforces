#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int get1(int a)
{
	if (a <= 6)
	{
		if (a == 1)return 1;
		if (a == 2)return 0;
		if (a == 3)return 1;
		if (a == 4)return 2;
		if (a == 5)return 0;
		if (a == 6)return 2;
	}
	if (a % 2 == 1)return 0;
	if (a % 4 == 2)return 1;
	return 3 - get1(a / 2);
}
int main()
{
	int num, k;
	scanf("%d%d", &num, &k);
	k %= 2;
	int ans = 0;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		if (k == 0)
		{
			if (z == 1)ans ^= 1;
			if (z == 2)ans ^= 2;
			if (z >= 3)ans ^= (1 - z % 2);
		}
		else
		{
			ans ^= get1(z);
		}
	}
	if (ans == 0)printf("Nicky\n");
	else printf("Kevin\n");
}