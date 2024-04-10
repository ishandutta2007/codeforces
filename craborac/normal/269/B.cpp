#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int mas[6000], ans[6000];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	double x;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d%lf", &mas[i], &x);
	}
	mas[0] = 0;
	ans[0] = 0;
	mas[n + 1] = m + 1;
	for(int i = 1; i <= n + 1; i++)
	{
		ans[i] = 0;
		for(int j = 0; j < i; j++)
			if((mas[j] <= mas[i]) && (ans[j] + 1 > ans[i]))
				ans[i] = ans[j] + 1;
	}
	printf("%d", n + 1 - ans[n + 1]);

	return 0;
}