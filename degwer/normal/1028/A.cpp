#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int mx, my;
	scanf("%d%d", &mx, &my);
	int c = 0, a = 0, b = 0;
	for (int i = 0; i < mx; i++)
	{
		for (int j = 0; j < my; j++)
		{
			char z;
			scanf(" %c", &z);
			if (z == 'B')c++, a += i + 1, b += j + 1;
		}
	}
	printf("%d %d\n", a / c, b / c);
}