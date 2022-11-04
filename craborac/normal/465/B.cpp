#include<cstdio>

int mas[2000];

int main()
{
	int n;
	scanf("%d", &n);
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &mas[i]);
		if(mas[i] == 1)
			ans += 1;
		if((mas[i] == 0) && (ans > 0) && (mas[i - 1] == 1))
			ans++;
	}
	if(mas[n - 1] == 1)
		ans++;	
	if(ans > 0)
		ans--;
	printf("%d", ans);
	return 0;
}