#include <stdio.h>

int main()
{
	int n, m;	scanf("%d %d", &n, &m);

	int ans = 1000000000;
	for(int i = 0; i < m; i++)
	{
		int l, r;	scanf("%d %d", &l, &r);
		int now = r - l + 1;
		if(ans > now)	ans = now;
	}
	printf("%d\n", ans);
	for(int i = 0; i < n; i++)	printf("%d ", i % ans);
	return 0;
}