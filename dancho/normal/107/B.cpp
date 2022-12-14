#include <cstdio>
#include <cstring>

int n, m, h;
int s[1024];

int main()
{
	scanf("%d %d %d", &n, &m, &h);
	--h;
	int tot = 0;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &s[i]);
		if (i == h)
			--s[i];
		tot += s[i];
	}
	if (tot < n - 1)
	{
		printf("-1\n");
		return 0;
	}

	double ans = 1.0;
	for (int i = 0; i < s[h]; ++i)
	{
		ans /= (tot - s[h] + 1 + i);
		ans *= (tot - s[h] - n + 1 + i + 1);
	}
	printf("%.10lf\n", 1.0 - ans);
	return 0;
}