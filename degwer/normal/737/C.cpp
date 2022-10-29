#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int dat[300000];
int main()
{
	int num,ch;
	scanf("%d%d", &num, &ch);
	ch--;
	int r = 0;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		if (i == ch)
		{
			if (z != 0)z = 0, r++;
		}
		dat[z]++;
	}
	r += max(0, dat[0] - 1);
	if (dat[0] > 1)
	{
		int pt = 0;
		for (int j = 1; j < dat[0]; j++)
		{
			for (;;)
			{
				if (dat[pt] == 0)break;
				pt++;
			}
			dat[pt]++;
		}
		dat[0] = 1;
	}
	int req = 0;
	int sum = num;
	int mini = 1000000000;
	for (int i = 0; i < num; i++)
	{
		if (dat[i] == 0)req++;
		sum -= dat[i];
		mini = min(mini, max(sum, req));
	}
	printf("%d\n", mini + r);
}