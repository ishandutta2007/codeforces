#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int dat[2000000];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		dat[z]++;
	}
	int ans = 0;
	for (int i = 0; i < 2000000; i++)
	{
		if (dat[i] % 2 == 1)ans++;
		dat[i + 1] += dat[i] / 2;
	}
	printf("%d\n", ans);
}