#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int x[1000], y[1000];
int main()
{
	int num, ban;
	scanf("%d%d", &num, &ban);
	for (int i = 0; i < ban; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		x[za] = 1, y[zb] = 1;
	}
	int c = 0;
	for (int i = 1; i < num - 1; i++)c += (x[i] == 0) + (y[i] == 0);
	if (num % 2 == 1 && (x[num / 2] == 0) && (y[num / 2] == 0))c--;
	printf("%d\n", c);
}