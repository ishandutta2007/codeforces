#include <cstdio>
#include <cstring>

bool p[1024][1024];
int g;
int a[1<<20], b[1<<20];

int main()
{
	int n, k;
	memset(p, 0, sizeof(p));
	
	scanf("%d %d", &n, &k);
	g = 0;
	for (int i = 1; i <= n; ++i)
	{
		int r = k;
		for (int j = 1; j <= n && r > 0; ++j)
		{
			if (i == j)
				continue;
			if (p[i][j])
				continue;
			p[i][j] = 1;
			p[j][i] = 1;
			a[g] = i;
			b[g] = j;
			++g;
			--r;
		}
		if (r > 0)
		{
			printf("-1\n");
			return 0;
		}
	}
	
	printf("%d\n", g);
	for (int i = 0; i < g; ++i)
	{
		printf("%d %d\n", a[i], b[i]);
	}
	
	return 0;
}