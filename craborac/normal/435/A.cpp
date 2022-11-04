#include<cstdio>    
int mas[100];
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d", &mas[i]);
	int sum = m;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		if(sum + mas[i] > m)
		{
			sum = mas[i];
			ans++;
		}
		else
			sum += mas[i];
	}
	printf("%d", ans);
	return 0;
}