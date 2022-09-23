#include <stdio.h>

int n, a, b;

int main()
{
	int one, two, half = 0;
	scanf("%d %d %d", &n, &a, &b);

	int ans = 0;
	one = a;
	two = b;

	for(int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);

		if(x == 1)
		{
			if(one != 0)
			{
				one--;
			}
			else if(two != 0)
			{
				two--;
				half++;
			}
			else if(half != 0)
			{
				half--;
			}
			else	ans++;
		}
		else
		{
			if(two != 0)	two--;
			else	ans += 2;
		}
	}
	printf("%d", ans);
	return 0;
}