#include<cstdio>
int mas[(int)1e5 + 10];
int main()
{
	int n;
	scanf("%d", &n);
	int m = n;
	int q = 0;
	int w = 0;
	while(n >= 4)
	{
		mas[q] = 2 + w;
		mas[q + 1] = n + w;
		mas[m - 1 - q] = n - 1 + w;
		mas[m - 2 - q] = 1 + w;
		q += 2;
		w += 2;
		n -= 4;
	}
	if(n == 1)
	{
		mas[q] = 1 + w;
	}
	else if(n == 2)
	{
		printf("-1");
		return 0;
	}
	else if(n == 3)
	{
		printf("-1");
		return 0;
	}
	for(int i = 0; i < m; i++)
		printf("%d ", mas[i]);
	return 0;
}