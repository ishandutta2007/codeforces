#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int dat[2000100];
int main()
{
	int num, gen;
	scanf("%d%d", &num, &gen);
	int mini = 1000000000;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		dat[z] = z;
		mini = min(mini, z);
	}
	for (int i = 1; i < 2000100; i++)
	{
		dat[i] = max(dat[i], dat[i - 1]);
	}
	int maxi = 0;
	for (int i = 1; i <= mini; i++)
	{
		int t = 1000000000;
		for (int j = i; j <= 2000010; j+=i)
		{
			if (j - dat[j - 1] < i)
			{
				t = min(t, j - dat[j - 1]);
			}
		}
		if (i - t <= gen)
		{
			maxi = i;
		}
	}
	printf("%d\n", maxi);
}