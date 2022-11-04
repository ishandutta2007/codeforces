#include<cstdio>
int t[100];
int main()
{
	int n, d;
	scanf("%d %d", &n, &d);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t[i]);
		sum += t[i];
		if(sum + (n - 1) * 10 > d)
		{
			printf("-1");
			return 0;
		}
	}
	printf("%d", (d - sum) / 5);
	return 0;
}