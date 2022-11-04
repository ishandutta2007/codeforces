#include<cstdio>
int k[100], ans[100];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i <n; i++)
	{
		scanf("%d", &k[i]);
		ans[i] = k[i] * 15;
	}
	for(int i = 0; i < n; i++)
	{	
		for(int j = 0; j < k[i]; j++)
		{
			int a;
			scanf("%d", &a);
			ans[i] += a * 5;
		}
	}
	int minn = ans[0];
	for(int i = 1; i < n; i++)
		if(ans[i] < minn)
			minn = ans[i];
	printf("%d", minn);
	return 0;
}