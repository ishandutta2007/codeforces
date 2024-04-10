#include<stdio.h>

int main()
{
	int n, k;
	int f, t, ans;
	int i, now;

	scanf("%d%d", &n, &k);
	ans = -2000000000;
	for(i = 0; i < n; i++)
	{
		scanf("%d%d", &f, &t);

		if(t <= k) now = f;
		else now = f - (t - k);

		if( now > ans) ans = now;
	}

	printf("%d\n", ans);

	return 0;
}