#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int x[101], y[101];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num + num; i++)
	{
		int z;
		scanf("%d", &z);
		z--;
		if (x[z] == 0)x[z] = i + 1;
		else y[z] = i + 1;
	}
	int ans = 0;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (x[i] < x[j] && x[j] < y[j] && y[j] < y[i])ans += 2;
			if (x[i] < x[j] && x[j] < y[i] && y[i] < y[j])ans++;
		}
	}
	printf("%d\n", ans);
}