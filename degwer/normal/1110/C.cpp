#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int gcd(int a, int b)
{
	if (a == 0)return b;
	if (b == 0)return a;
	for (;;)
	{
		if (a < b)swap(a, b);
		a %= b;
		if (a == 0)return b;
	}
}
int d[100];
int main()
{
	d[0] = 0;
	d[1] = 0;
	d[2] = 1;
	d[3] = 1;
	d[4] = 5;
	d[5] = 1;
	d[6] = 21;
	d[7] = 1;
	d[8] = 85;
	d[9] = 73;
	d[10] = 341;
	d[11] = 89;
	d[12] = 1365;
	d[13] = 1;
	d[14] = 5461;
	d[15] = 4681;
	d[16] = 21845;
	d[17] = 1;
	d[18] = 87381;
	d[19] = 1;
	d[20] = 349525;
	d[21] = 299593;
	d[22] = 1398101;
	d[23] = 178481;
	d[24] = 5592405;
	d[25] = 1082401;
	/*for (int i = 0; i <= 25; i++)
	{
		int maxi = 0, rr = -1;
		for (int j = 1; j < (1 << i) - 1; j++)maxi = max(maxi, gcd(j, (1 << i) - 1 - j));
		printf("d[%d]=%d;\n", i, maxi);
	}*/
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		int t = -1;
		for (int i = 0; i <= 25; i++)
		{
			if (z >= (1 << i))t = i;
		}
		if (z == (2 << t) - 1)printf("%d\n", d[t + 1]);
		else printf("%d\n", (2 << t) - 1);
	}
}