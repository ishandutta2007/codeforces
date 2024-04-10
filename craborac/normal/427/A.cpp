#include<cstdio>
int main()
{
	int n;
	scanf("%d",&n);
	int col = 0;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		if(a > 0)
			col += a;
		else
		{
			if(col == 0)
				ans++;
			else
				col--;	
		}
	}
	printf("%d", ans);
	return 0;
}