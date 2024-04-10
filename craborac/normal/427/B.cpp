#include<cstdio>
int main()
{
	int n, t, s;
	scanf("%d %d %d", &n, &t, &s);
	int col = 0;
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int a;
		scanf("%d", &a);
		if(a <= t)
			col++;
		else
		  col = 0;
		if(col >= s)
			ans++;
	}
	printf("%d", ans);
	return 0;
}